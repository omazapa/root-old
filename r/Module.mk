# Module.mk for R interface module
# Copyright (c) 2013 Omar Andres Zapata Mesa
#
# Author: Omar Zapata, 30/5/2013

MODNAME      := r
MODDIR       := $(ROOT_SRCDIR)/$(MODNAME)
MODDIRS      := $(MODDIR)/src
MODDIRI      := $(MODDIR)/inc

RDIR  := $(MODDIR)
RDIRS := $(RDIR)/src
RDIRI := $(RDIR)/inc

##### libRInterface #####
RL           := $(MODDIRI)/LinkDef.h

RDS          := $(call stripsrc,$(MODDIRS)/G__RInterface.cxx)

RDO          := $(RDS:.cxx=.o)

#RDH          := $(RDS:.cxx=.h)

RDH          := $(MODDIRI)/RExports.h \
                $(MODDIRI)/TRInterface.h \
                $(MODDIRI)/TRObjectProxy.h \
                $(MODDIRI)/TRFunction.h \
                $(MODDIRI)/compilerdata.h 

RDHF         := $(MODDIRI)/TRInternalFunction.h \
                $(MODDIRI)/TRInternalFunction__ctors.h
                
RH    := $(RDH) $(RDHF)

RS    := $(filter-out $(MODDIRS)/G__%,$(wildcard $(MODDIRS)/*.cxx))
RO    := $(call stripsrc,$(RS:.cxx=.o))

RDEP  := $(RO:.o=.d) $(RDO:.o=.d)

RLIB  := $(LPATH)/libRInterface.$(SOEXT)
RMAP  := $(RLIB:.$(SOEXT)=.rootmap)

# used in the main Makefile
ALLHDRS      += $(patsubst $(MODDIRI)/%.h,include/%.h,$(RH))
ALLLIBS      += $(RLIB)
ALLMAPS      += $(RMAP)

# include all dependency files
INCLUDEFILES += $(RDEP)


##### local rules #####
.PHONY:         all-$(MODNAME) clean-$(MODNAME) distclean-$(MODNAME) \
                test-$(MODNAME)

include/%.h:    $(RDIRI)/%.h
		cp $< $@

$(RLIB): $(RO) $(RDO) $(ORDER_) $(MAINLIBS) $(RLIBDEP)
		@$(MAKELIB) $(PLATFORM) $(LD) "$(LDFLAGS)"  \
		   "$(SOFLAGS)" libRInterface.$(SOEXT) $@     \
		   "$(RO) $(RDO)" \
		   "$(RLIBEXTRA) $(RLIBS)"

$(RDS): $(RDH) $(RL) $(ROOTCINTTMPDEP)
		$(MAKEDIR)
		@echo "Generating dictionary $@..."
		$(ROOTCINTTMP) -f $@ -c $(RDH) $(RL)

$(RMAP): $(RLIBMAP) $(MAKEFILEDEP) $(ALLRL)
		$(RLIBMAP) -o $@ -l $(RLIB) \
		   -d $(RLIBDEPM) -c $(RL) $(RLINC)

all-$(MODNAME): $(RLIB) $(RMAP)

clean-$(MODNAME):
		@rm -f $(RDO)

clean::         clean-$(MODNAME)

distclean-$(MODNAME): clean-$(MODNAME)
		@rm -f $(RDEP) $(RDS) \
		   $(RLIB) $(RMAP)

distclean::     distclean-$(MODNAME)

#test-$(MODNAME): all-$(MODNAME)

##### extra rules ######
$(RO): CXXFLAGS += -DUSE_ROOT_ERROR
$(RDO): CXXFLAGS += -DUSE_ROOT_ERROR 
# add optimization to G__RInterface compilation
# Optimize dictionary with stl containers.
#$(RDO) : NOOPT = $(OPT)

$(RO):  CXXFLAGS  += $(RFLAGS)
$(RDO): CXXFLAGS += $(RFLAGS)
