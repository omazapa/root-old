// @(#)root/pyroot:$Id$
// Author: Wim Lavrijsen, Jan 2005
#ifndef PYROOT_CONVERTERS_H
#define PYROOT_CONVERTERS_H

// ROOT
#include "DllImport.h"
#include "TString.h"
#include "TClassRef.h"
#include "TDictionary.h"

// Standard
#include <limits.h>
#include <string>
#include <map>


namespace PyROOT {

   union TParameter_t;

   class TConverter {
   public:
      virtual ~TConverter() {}

   public:
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 ) = 0;
      virtual PyObject* FromMemory( void* address );
      virtual Bool_t ToMemory( PyObject* value, void* address );
   };

#define PYROOT_DECLARE_BASIC_CONVERTER( name )                                \
   class T##name##Converter : public TConverter {                             \
   public:                                                                    \
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );\
      virtual PyObject* FromMemory( void* );                                  \
      virtual Bool_t ToMemory( PyObject*, void* );                            \
   }

#define PYROOT_DECLARE_BASIC_CONVERTER2( name, base )                         \
   class T##name##Converter : public T##base##Converter {                     \
   public:                                                                    \
      virtual PyObject* FromMemory( void* );                                  \
      virtual Bool_t ToMemory( PyObject*, void* );                            \
   }

#define PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( name, type )                 \
   class TConst##name##RefConverter : public T##name##Converter {             \
   public:                                                                    \
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );\
   private:                                                                   \
      type fBuffer;                                                           \
   }

#define PYROOT_DECLARE_ARRAY_CONVERTER( name )                                \
   class T##name##Converter : public TConverter {                             \
   public:                                                                    \
      T##name##Converter( Py_ssize_t size = -1 ) { fSize = size; }            \
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );\
      virtual PyObject* FromMemory( void* );                                  \
      virtual Bool_t ToMemory( PyObject*, void* );                            \
   private:                                                                   \
      Py_ssize_t fSize;                                                       \
   }

// converters for built-ins
   PYROOT_DECLARE_BASIC_CONVERTER( Long );
   PYROOT_DECLARE_BASIC_CONVERTER( LongRef );
   PYROOT_DECLARE_BASIC_CONVERTER( Bool );
   PYROOT_DECLARE_BASIC_CONVERTER( Char );
   PYROOT_DECLARE_BASIC_CONVERTER( UChar );
   PYROOT_DECLARE_BASIC_CONVERTER2( Short, Long );
   PYROOT_DECLARE_BASIC_CONVERTER2( UShort, Long );
   PYROOT_DECLARE_BASIC_CONVERTER2( Int, Long );
   PYROOT_DECLARE_BASIC_CONVERTER( IntRef );
   PYROOT_DECLARE_BASIC_CONVERTER( ULong );
   PYROOT_DECLARE_BASIC_CONVERTER2( UInt, ULong );
   PYROOT_DECLARE_BASIC_CONVERTER( LongLong );
   PYROOT_DECLARE_BASIC_CONVERTER( ULongLong );
   PYROOT_DECLARE_BASIC_CONVERTER( Double );
   PYROOT_DECLARE_BASIC_CONVERTER2( Float, Double );
   PYROOT_DECLARE_BASIC_CONVERTER2( LongDouble, Double );
   PYROOT_DECLARE_BASIC_CONVERTER( DoubleRef );

   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( Bool, Bool_t );
   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( Char, Char_t );
   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( UChar, UChar_t );
   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( Short, Short_t );
   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( UShort, UShort_t );
   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( Int, Int_t );
   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( UInt, UInt_t );
   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( Long, Long_t );
   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( ULong, ULong_t );
   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( LongLong, Long64_t );
   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( ULongLong, ULong64_t );
   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( Float, Float_t );
   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( Double, Double_t );
   PYROOT_DECLARE_BASIC_CONST_REFCONVERTER( LongDouble, LongDouble_t );

   class TVoidConverter : public TConverter {
   public:
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );
   };

   class TCStringConverter : public TConverter {
   public:
      TCStringConverter( UInt_t maxSize = UINT_MAX ) : fMaxSize( maxSize ) {}

   public:
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );
      virtual PyObject* FromMemory( void* address );
      virtual Bool_t ToMemory( PyObject* value, void* address );

   protected:
      std::string fBuffer;
      UInt_t fMaxSize;
   };

   class TNonConstCStringConverter : public TCStringConverter {
   public:
      TNonConstCStringConverter( UInt_t maxSize = UINT_MAX ) : TCStringConverter( maxSize ) {}

   public:
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );
      virtual PyObject* FromMemory( void* address );
   };

   class TNonConstUCStringConverter : public TNonConstCStringConverter {
   public:
      TNonConstUCStringConverter( UInt_t maxSize = UINT_MAX ) : TNonConstCStringConverter( maxSize ) {}

   public:
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );
   };

// pointer/array conversions
   class TVoidArrayConverter : public TConverter {
   public:
      TVoidArrayConverter( Bool_t keepControl = kTRUE ) { fKeepControl = keepControl; }
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );
      virtual PyObject* FromMemory( void* address );
      virtual Bool_t ToMemory( PyObject* value, void* address );

   protected:
      virtual Bool_t GetAddressSpecialCase( PyObject* pyobject, void*& address );

   protected:
      Bool_t KeepControl() { return fKeepControl; }

   private:
      Bool_t fKeepControl;
   };

   PYROOT_DECLARE_ARRAY_CONVERTER( BoolArray );
   PYROOT_DECLARE_ARRAY_CONVERTER( ShortArray );
   PYROOT_DECLARE_ARRAY_CONVERTER( UShortArray );
   PYROOT_DECLARE_ARRAY_CONVERTER( IntArray );
   PYROOT_DECLARE_ARRAY_CONVERTER( UIntArray );
   PYROOT_DECLARE_ARRAY_CONVERTER( LongArray );
   PYROOT_DECLARE_ARRAY_CONVERTER( ULongArray );
   PYROOT_DECLARE_ARRAY_CONVERTER( FloatArray );
   PYROOT_DECLARE_ARRAY_CONVERTER( DoubleArray );

   class TLongLongArrayConverter : public TVoidArrayConverter {
   public:
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );
   };

// converters for special cases
   class TRootObjectConverter : public TVoidArrayConverter {
   public:
      TRootObjectConverter( const TClassRef& klass, Bool_t keepControl = kFALSE ) :
         TVoidArrayConverter( keepControl ), fClass( klass ) {}

   public:
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );
      virtual PyObject* FromMemory( void* address );
      virtual Bool_t ToMemory( PyObject* value, void* address );

   protected:
      TClassRef fClass;
   };

   class TStrictRootObjectConverter : public TRootObjectConverter {
   public:
      TStrictRootObjectConverter( const TClassRef& klass, Bool_t keepControl = kFALSE ) :
         TRootObjectConverter( klass, keepControl ) {}

   protected:
      virtual Bool_t GetAddressSpecialCase( PyObject*, void*& ) { return kFALSE; }
   };

   class TRootObjectPtrConverter : public TRootObjectConverter {
   public:
      TRootObjectPtrConverter( const TClassRef& klass, Bool_t keepControl = kFALSE ) :
         TRootObjectConverter( klass, keepControl ) {}

   public:
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );
      virtual PyObject* FromMemory( void* address );
      virtual Bool_t ToMemory( PyObject* value, void* address );
   };

   class TRootObjectArrayConverter : public TRootObjectConverter {
   public:
      TRootObjectArrayConverter( const TClassRef& klass, size_t size, Bool_t keepControl = kFALSE ) :
         TRootObjectConverter( klass, keepControl ), m_size( size ) {}

   public:
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );
      virtual PyObject* FromMemory( void* address );
      virtual Bool_t ToMemory( PyObject* value, void* address );

   protected:
      size_t m_size;
   };

// CLING WORKAROUND -- classes for STL iterators are completely undefined in that
// they come in a bazillion different guises, so just do whatever
   class TSTLIteratorConverter : public TConverter {
   public:
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );
   };
// -- END CLING WORKAROUND

   class TVoidPtrRefConverter : public TConverter {
   public:
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );
   };

   class TVoidPtrPtrConverter : public TConverter {
   public:
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );
      virtual PyObject* FromMemory( void* address );
   };

   PYROOT_DECLARE_BASIC_CONVERTER( PyObject );

#define PYROOT_DECLARE_STRING_CONVERTER( name, strtype )                      \
   class T##name##Converter : public TRootObjectConverter {                   \
   public:                                                                    \
      T##name##Converter( Bool_t keepControl = kTRUE );                       \
   public:                                                                    \
   virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );\
      virtual PyObject* FromMemory( void* address );                          \
      virtual Bool_t ToMemory( PyObject* value, void* address );              \
   private:                                                                   \
      strtype fBuffer;                                                        \
   }

   PYROOT_DECLARE_STRING_CONVERTER( TString,   TString );
   PYROOT_DECLARE_STRING_CONVERTER( STLString, std::string );

   class TNotImplementedConverter : public TConverter {
   public:
      virtual Bool_t SetArg( PyObject*, TParameter_t&, CallFunc_t* = 0, Long_t = 0 );
   };

// factories
   typedef TConverter* (*ConverterFactory_t) ( Long_t user );
   typedef std::map< std::string, ConverterFactory_t > ConvFactories_t;
   R__EXTERN ConvFactories_t gConvFactories;

// create converter from fully qualified type
   TConverter* CreateConverter( const std::string& fullType, Long_t user = -1 );

} // namespace PyROOT

#endif // !PYROOT_CONVERTERS_H
