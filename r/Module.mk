# Module.mk for R interface module
# Copyright (c) 2013 Omar Andres Zapata Mesa
#
# Author: Omar Zapata, 30/5/2013
# updated Apr 29 2014 GSoC

MODNAME      := r
MODDIR       := $(ROOT_SRCDIR)/$(MODNAME)
MODDIRS      := $(MODDIR)/src
MODDIRI      := $(MODDIR)/inc

RDIR  := $(MODDIR)
RDIRS := $(RDIR)/src
RDIRI := $(RDIR)/inc


##### libRInterface #####
RL    := $(MODDIRI)/LinkDef.h


RDS   := $(call stripsrc,$(MODDIRS)/G__RInterface.cxx)
RDO   := $(RDS:.cxx=.o)
#RDH   := $(RDS:.cxx=.h)

RDH   := $(MODDIRI)/RExports.h \
                $(MODDIRI)/TRInterface.h \
                $(MODDIRI)/TRObjectProxy.h \
                $(MODDIRI)/TRFunction.h \
                $(MODDIRI)/compilerdata.h 

RH    := $(filter-out $(MODDIRI)/LinkDef%,$(wildcard $(MODDIRI)/*.h))
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
.PHONY:         all-$(MODNAME) clean-$(MODNAME) distclean-$(MODNAME)

include/%.h: $(RDIRI)/%.h
		cp $< $@

$(RLIB): $(RO) $(RDO) $(ORDER_) $(MAINLIBS) $(RLIBDEP)
		@$(MAKELIB) $(PLATFORM) $(LD) "$(LDFLAGS)"  \
		   "$(SOFLAGS)" libRInterface.$(SOEXT) $@     \
		   "$(RLIBEXTRA) $(RLIBS)"

$(call pcmrule,R)
	$(noop)

$(RDS):  $(RL) $(RLINC) $(ROOTCINTTMPDEP) $(call pcmdep,R)
		$(MAKEDIR)
		@echo "Generating dictionary $@..."
		$(ROOTCINTTMP) -f $@  $(call dictModule,R) -c $(ROOT_SRCDIR:%=-I%) $(RFLAGS) $(RL)

$(RMAP): $(RL) $(RLINC) $(ROOTCINTTMPDEP) $(call pcmdep,R)
		$(MAKEDIR)
		@echo "Generating rootmap $@..."
		$(ROOTCINTTMP) -r $(RDS)  $(call dictModule,R) -c $(ROOT_SRCDIR:%=-I%) $(RFLAGS)  $(RL)

all-$(MODNAME): $(RLIB)

clean-$(MODNAME):
		@rm -f $(RO) $(RDO)

clean::         clean-$(MODNAME)

distclean-$(MODNAME): clean-$(MODNAME)
		@rm -f $(RDEP) $(RDS) \
		   $(RLIB) $(RMAP)

distclean::     distclean-$(MODNAME)

##### extra rules ######
$(RO): CXXFLAGS += $(RFLAGS) -DUSE_ROOT_ERROR
$(RDO): CXXFLAGS += $(RFLAGS) -DUSE_ROOT_ERROR

# Optimize dictionary with stl containers.
$(RDO): NOOPT = $(OPT)
