""" PyCintex compatibility module.
    This module allows transferring away from PyCintex from ROOT v5 to v6.
    It provides both the original PyCintex.py (most code here is copied over
    from PyCintex.py) as well as the newer cppyy (from PyPy) APIs. In ROOT6,
    these codes are consolidated.
"""

import sys, string

### helper to get the version number from root-config
def get_version():
   try:
      import commands
      stat, output = commands.getstatusoutput("root-config --version")
      if stat == 0:
         return output
   except Exception:
      pass
   # semi-sensible default in case of failure ...
   return "6.03/XY"

### PyPy has 'cppyy' builtin (if enabled, that is)
if 'cppyy' in sys.builtin_module_names:
   _builtin_cppyy = True

   import imp
   sys.modules[ __name__ ] = \
      imp.load_module( 'cppyy', *(None, 'cppyy', ('', '', imp.C_BUILTIN) ) )
   del imp

   _thismodule = sys.modules[ __name__ ]
   _backend = _thismodule.gbl

   # custom behavior that is not yet part of PyPy's cppyy
   def _MakeRootClass( self, name ):
      return getattr( self, name )
   type(_backend).MakeRootClass = _MakeRootClass

   def _LookupRootEntity( self, name ):
      return getattr( self, name )
   type(_backend).LookupRootEntity = _LookupRootEntity

   class _Double(float): pass
   type(_backend).Double = _Double

   def _AddressOf( self, obj ):
      import array
      return array.array('L', [_thismodule.addressof( obj )] )
   type(_backend).AddressOf = _AddressOf

   del _AddressOf, _Double, _LookupRootEntity, _MakeRootClass

else:
   _builtin_cppyy = False

   # load PyROOT C++ extension module, special case for linux and Sun
   needsGlobal =  ( 0 <= string.find( sys.platform, 'linux' ) ) or\
                  ( 0 <= string.find( sys.platform, 'sunos' ) )
   if needsGlobal:
      # change dl flags to load dictionaries from pre-linked .so's
      dlflags = sys.getdlopenflags()
      sys.setdlopenflags( 0x100 | 0x2 )    # RTLD_GLOBAL | RTLD_NOW

   import libPyROOT as _backend

   # reset dl flags if needed
   if needsGlobal:
      sys.setdlopenflags( dlflags )
   del needsGlobal

# PyCintex tests rely on this, but they should not:
sys.modules[ __name__ ].libPyROOT = _backend

if not _builtin_cppyy:
   _backend.SetMemoryPolicy( _backend.kMemoryStrict )

#--- Enable Autoloading ignoring possible error for the time being
try:    _backend.gInterpreter.EnableAutoLoading()
except: pass


### template support ------------------------------------------------------------
if not _builtin_cppyy:
   class Template:
      def __init__( self, name ):
         self.__name__ = name

      def __call__( self, *args ):
         newargs = [ self.__name__[ 0 <= self.__name__.find( 'std::' ) and 5 or 0:] ]
         for arg in args:
            if type(arg) == str:
               arg = ','.join( map( lambda x: x.strip(), arg.split(',') ) )
            newargs.append( arg )
         result = _backend.MakeRootTemplateClass( *newargs )

       # special case pythonization (builtin_map is not available from the C-API)
         if hasattr( result, 'push_back' ):
            def iadd( self, ll ):
               [ self.push_back(x) for x in ll ]
               return self

            result.__iadd__ = iadd

         return result

   _backend.Template = Template


#--- LoadDictionary function and aliases -----------------------------
def loadDictionary(name):
   # prepend "lib" 
   if sys.platform != 'win32' and name[:3] != 'lib':
       name = 'lib' + name
   sc = _backend.gSystem.Load(name)
   if sc == -1: raise RuntimeError("Error Loading dictionary")
loadDict = loadDictionary

def load_reflection_info(name):
   sc = _backend.gSystem.Load(name)


#--- Other functions needed -------------------------------------------
if not _builtin_cppyy:
   class _ns_meta( type ):
      def __getattr__( cls, name ):
         attr = _backend.LookupRootEntity( name )
         if type(attr) is _backend.PropertyProxy:
            setattr( cls.__class__, name, attr )
            return attr.__get__(cls)
         setattr( cls, name, attr )
         return attr

   class _stdmeta( type ):
      def __getattr__( cls, name ):   # for non-templated classes in std
         klass = _backend.MakeRootClass( name, cls )
         setattr( cls, name, klass )
         return klass

   class _global_cpp:
      __metaclass__ = _ns_meta

      class std( object ):
         __metaclass__ = _stdmeta

         stlclasses = ( 'complex', 'pair', \
            'deque', 'list', 'queue', 'stack', 'vector', 'map', 'multimap', 'set', 'multiset' )

         for name in stlclasses:
            locals()[ name ] = Template( 'std::%s' % name )

         string = _backend.MakeRootClass( 'string' )

else:
   _global_cpp = _backend
 
def Namespace( name ) :
   if name == '' : return _global_cpp
   else :          return _backend.LookupRootEntity( name )
makeNamespace = Namespace

def makeClass( name ) :
   return _backend.MakeRootClass( name )
  
def addressOf( obj ) :                  # Cintex-style
   return _backend.AddressOf( obj )[0]
addressof = _backend.addressof          # cppyy-style
       
def getAllClasses() :
   TClassTable = makeClass( 'TClassTable' )
   TClassTable.Init()
   classes = []
   while True :
      c = TClassTable.Next()
      if c : classes.append( c )
      else : break
   return classes

#--- Global namespace and global objects -------------------------------
gbl  = _global_cpp
sys.modules['cppyy.gbl'] = gbl
NULL = 0 # _backend.GetRootGlobal returns a descriptor, which needs a class
class double(float): pass
class short(int): pass
class long_int(int): pass
class unsigned_short(int): pass
class unsigned_int(int): pass
class unsigned_long(long): pass

#--- Copy over locally defined names ------------------------------------
if _builtin_cppyy:
   for name in dir():
      if name[0] != '_': setattr( _thismodule, name, eval(name) )

#--- Compatibility ------------------------------------------------------
if not _builtin_cppyy:
   bind_object = _backend.BindObject
