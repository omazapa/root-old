# Module.mk for RMpi module
# Copyright (c) Omar Andres Zapata Mesa
#
# Author: Omar Andres Zapata Mesa, 1/10/2012

MODNAME      := rmpi
MODDIR       := $(ROOT_SRCDIR)/mpi/$(MODNAME)
MODDIRS      := $(MODDIR)/src
MODDIRI      := $(MODDIR)/inc

MPIDIR       := $(MODDIR)
MPIDIRS      := $(MPIDIR)/src
MPIDIRI      := $(MPIDIR)/inc

##### libRMpi #####
MPIL1        := $(MODDIRI)/Mpi/LinkDef.h
MPIL2        := $(MODDIRI)/Mpi/LinkDef_Globals.h
MPIL3        := $(MODDIRI)/Mpi/LinkDef_Functions.h
MPIDS1       := $(call stripsrc,$(MODDIRS)/G__RMpi.cxx)
MPIDS2       := $(call stripsrc,$(MODDIRS)/G__RMpiGlobals.cxx)
MPIDS3       := $(call stripsrc,$(MODDIRS)/G__RMpiFunctions.cxx)
MPIDO1       := $(MPIDS1:.cxx=.o)
MPIDO2       := $(MPIDS2:.cxx=.o)
MPIDO3       := $(MPIDS3:.cxx=.o)
MPIL         := $(MPIL1) $(MPIL2) $(MPIL3)
MPIDS        := $(MPIDS1) $(MPIDS2) $(MPIDS3)
MPIDO        := $(MPIDO1) $(MPIDO2) $(MPIDO3)
MPIDH        := $(MPIDS:.cxx=.h)

MPIH1        := TIntercomm.h   \
                TComm.h   \
                TCommCintSendRecv.h   \
                TCommCintISendRecv.h   \
                TCommCintBcast.h   \
                TCommCintGather.h   \
                TCommCintAllGather.h   \
                TCommCintScatter.h   \
                TUtils.h   \
                TInfo.h   \
                TFile.h   \
                TGroup.h   \
                TWin.h   \
                TFunctions.h   \
                TIntracomm.h   \
                TDatatype.h   \
                TOp.h   \
                TMpiException.h   \
                TErrhandler.h   \
                TGraphcomm.h   \
                TStatus.h   \
                TEnvironment.h   \
                TMpiMessage.h   \
                TRequest.h   \
                TCartcomm.h   \
                MTypes.h

MPIH2        := MTypes.h  \
                TOp.h   \
                TDatatype.h  \
                TIntracomm.h  \
                TErrhandler.h 

MPIH3        := TFunctions.h

MPIH1        := $(patsubst %,$(MODDIRI)/Mpi/%,$(MPIH1))
MPIH2        := $(patsubst %,$(MODDIRI)/Mpi/%,$(MPIH2))
MPIH3        := $(patsubst %,$(MODDIRI)/Mpi/%,$(MPIH3))

MPIH         := $(MPIH1) $(MPIH2) $(MPIH3)
MPIS         := $(filter-out $(MODDIRS)/G__%,$(wildcard $(MODDIRS)/*.cxx))
MPIO         := $(call stripsrc,$(MPIS:.cxx=.o))

MPIDEP       := $(MPIO:.o=.d) $(MPIDO:.o=.d)

MPILIB       := $(LPATH)/libRMpi.$(SOEXT)
MPIMAP       := $(MPILIB:.$(SOEXT)=.rootmap)

# used in the main Makefile
ALLHDRS     += $(patsubst $(MODDIRI)/Mpi/%.h,include/Mpi/%.h,$(MPIH))
ALLLIBS     += $(MPILIB)
ALLMAPS     += $(MPIMAP)

# include all dependency files
INCLUDEFILES += $(MPIDEP)

##### local rules #####
.PHONY:         all-$(MODNAME) clean-$(MODNAME) distclean-$(MODNAME)

include/Mpi/%.h:    $(MPIDIRI)/Mpi/%.h
		  @(if [ ! -d "include/Mpi" ]; then     \
		    mkdir -p include/Mpi;              \
		  fi)
		  cp $< $@
		  cp $(MPIDIRI)/RMpi.h include
		  
$(MPILIB):      $(MPIO) $(MPIDO) $(ORDER_) $(MAINLIBS) $(MPILIBDEP)
		@$(MAKELIB) $(PLATFORM) $(LD) "$(LDFLAGS)" \
		   "$(SOFLAGS)" libRMpi.$(SOEXT) $@ "$(MPIO) $(MPIDO)" \
		   "$(MPILIBEXTRA)" "$(MPILIBS)"

$(MPIDS1):      $(MPIH1) $(MPIL1) $(ROOTCINTTMPDEP)
		$(MAKEDIR)
		@echo "Generating dictionary $@..."
		$(ROOTCINTTMP) -f $@ -c $(MPIH1) $(MPIL1)
$(MPIDS2):      $(MPIH2) $(MPIL2) $(ROOTCINTTMPDEP)
		$(MAKEDIR)
		@echo "Generating dictionary $@..."
		$(ROOTCINTTMP) -f $@ -c $(MPIH2) $(MPIL2)
$(MPIDS3):      $(MPIH3) $(MPIL3) $(ROOTCINTTMPDEP)
		$(MAKEDIR)
		@echo "Generating dictionary $@..."
		$(ROOTCINTTMP) -f $@ -c $(MPIH3) $(MPIL3)

$(MPIMAP):      $(RLIBMAP) $(MAKEFILEDEP) $(MPIL)
		$(RLIBMAP) -o $@ -l $(MPILIB) \
		   -d $(MPILIBDEPM) -c $(MPIL)

all-$(MODNAME): $(MPILIB) $(MPIMAP)

clean-$(MODNAME):
		@rm -f $(MPIO) $(MPIDO)

clean::         clean-$(MODNAME)

distclean-$(MODNAME): clean-$(MODNAME)
		@rm -rf $(MPIDEP) $(MPIDS) $(MPIDH) $(MPILIB) $(MPIMAP) include/Mpi

distclean::     distclean-$(MODNAME)

$(MPIO):  CXXFLAGS += -I$(MPIDIRI)/Mpi/ -I$(MPIDIRI) -DUSE_ROOT_ERROR 
$(MPIO):  CXX = $(MPICXX)


$(MPIDO): CXXFLAGS += -I$(MPIDIRI)/Mpi/ -I$(MPIDIRI) -DUSE_ROOT_ERROR 
$(MPIDO): CXX = $(MPICXX)


$(MPILIB): CXX = $(MPICXX)
$(MPILIB): LD = $(MPICXX)
