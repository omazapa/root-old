# Module.mk for llvm module
# Copyright (c) 2012 Rene Brun and Fons Rademakers
#
# Author: Fons Rademakers, 6/8/2012

MODNAME      := llvm
MODDIR       := $(ROOT_SRCDIR)/interpreter/$(MODNAME)
LLVMDIRO     := $(call stripsrc,$(MODDIR)/obj)
LLVMDIRI     := $(call stripsrc,$(MODDIR)/inst)

ifneq ($(BUILTINLLVM),yes)

LLVMDEP      :=

.PHONY:         distclean-$(MODNAME)

distclean-$(MODNAME):
		@rm -rf $(LLVMDIRO) $(LLVMDIRI)

# Don't clean LLVM when doing standard "make distclean" as it is mostly not
# needed. To explicitly clean LLVM do either: "make maintainer-clean" or
# "make distclean-llvm".
#distclean::     distclean-$(MODNAME)
maintainer-clean:: distclean-$(MODNAME)

else

MODDIRS      := $(MODDIR)/src

LLVMDIR      := $(MODDIR)
LLVMDIRS     := $(MODDIRS)

##### libllvm #####
LLVMLIB      := $(LLVMDIRI)/lib/libclangSema.a
LLVMDEPO     := $(LLVMDIRO)/Makefile.config
LLVMDEPS     := $(LLVMDIRS)/Makefile
ifeq ($(strip $(LLVMCONFIG)),)
LLVMCONFIG   := interpreter/llvm/inst/bin/llvm-config
endif
LLVMGOODS    := $(MODDIRS)/../../cling/LastKnownGoodLLVMSVNRevision.txt
LLVMGOODO    := $(LLVMDIRO)/$(notdir $(LLVMGOODS))
LLVMVERSION  := $(shell echo $(subst rc,,$(subst svn,,$(subst PACKAGE_VERSION=,,\
	$(shell grep 'PACKAGE_VERSION=' $(LLVMDIRS)/configure)))))
LLVMRES      := etc/cling/lib/clang/$(LLVMVERSION)/include/stddef.h
LLVMRESEXTRA := etc/cling/lib/clang/$(LLVMVERSION)/include/assert.h
LLVMDEP      := $(LLVMLIB) $(LLVMRES) $(LLVMRESEXTRA)

ROOT_NOCLANG := "ROOT_NOCLANG=yes"
ifeq ($(LLVMDEV),)
LLVMOPTFLAGS := --enable-optimized --disable-assertions
else
ROOT_NOCLANG := "ROOT_NOCLANG=no"
ifeq (,$(findstring debug,$(ROOTBUILD)))
LLVMOPTFLAGS := --enable-optimized --enable-debug-symbols --disable-assertions
else
LLVMOPTFLAGS := --disable-optimized
endif
endif

FORCELLVM := 0
ifeq ($(findstring $(MAKECMDGOALS),clean distclean maintainer-clean dist distsrc),)
ifeq ($(findstring clean-,$(MAKECMDGOALS)),)
ifeq ($(shell which git 2>&1 | sed -ne "s@.*/git@git@p"),git)
FORCELLVM := $(shell bash $(ROOT_SRCDIR)/build/unix/gitinfollvm.sh $(ROOT_SRCDIR))
ENDLLVMBUILD := && cd ../../.. && ( $(ROOT_SRCDIR)/build/unix/gitinfollvm.sh $(ROOT_SRCDIR) > /dev/null )
endif
endif
endif

ifneq ($(FORCELLVM),0)
FORCELLVMTARGET := FORCELLVMTARGET
FORCENEXTLLVM := $(shell rm -f $(LLVMDIRO)/llvmrev.txt)
endif

##### local rules #####
.PHONY: all-$(MODNAME) clean-$(MODNAME) distclean-$(MODNAME) FORCELLVMTARGET

# clang resource directory gets copied to lib/clang/
# clang version extraction as in tools/clang/lib/Headers/Makefile
ifeq ($(LLVMCONFIG),interpreter/llvm/inst/bin/llvm-config)
$(LLVMCONFIG): $(LLVMLIB)
endif

$(LLVMRES): $(LLVMLIB)
		@mkdir -p $(dir $(LLVMRES))
		@cp $(LLVMDIRI)/lib/clang/$(LLVMVERSION)/include/* $(dir $(LLVMRES))

$(LLVMRESEXTRA): $(dir $(firstword $(LLVMRESEXTRA)))%: $(MODDIR)/ROOT/%
		@mkdir -p $(dir $@)
		@cp $< $@

$(LLVMLIB): $(LLVMDEPO) $(FORCELLVMTARGET)
		@(echo "*** Building $@..."; \
		cd $(LLVMDIRO) && \
		$(MAKE) ONLY_TOOLS=clang NOCLING=1 VERBOSE=1 $(ROOT_NOCLANG) && \
		rm -rf ../inst/lib/clang && \
		$(MAKE) ONLY_TOOLS=clang NOCLING=1 install $(ROOT_NOCLANG) \
                $(ENDLLVMBUILD) )

$(LLVMGOODO): $(LLVMGOODS) $(LLVMLIB)
		@cp $(LLVMGOODS) $(LLVMGOODO)

$(LLVMDEPO): $(LLVMDEPS)
		$(MAKEDIR)
		@(LLVMCC="$(CC)" && \
		LLVMCXX="$(CXX)" && \
		if [ $(ARCH) = "aix5" ]; then \
			LLVM_CFLAGS="-DBOOL=int"; \
		fi; \
		if [ $(ARCH) = "linux" ]; then \
			LLVM_CFLAGS="-m32"; \
		fi; \
		if [ $(ARCH) = "linuxx8664gcc" ]; then \
			LLVM_CFLAGS="-m64"; \
		fi; \
		if [ $(ARCH) = "linuxicc" ]; then \
			LLVM_CFLAGS="-m32"; \
		fi; \
		if [ $(ARCH) = "linuxx8664icc" ]; then \
			LLVM_CFLAGS="-m64"; \
		fi; \
		if [ $(ARCH) = "macosx" ]; then \
			LLVM_CFLAGS="-m32"; \
		fi; \
		if [ $(ARCH) = "macosx64" ]; then \
			LLVM_CFLAGS="-m64"; \
		fi; \
		if [ $(ARCH) = "iossim" ]; then \
			LLVM_CFLAGS="-arch i386 -isysroot $(IOSSDK) -miphoneos-version-min=$(IOSVERS)"; \
			LLVM_HOST="--host=i386-apple-darwin"; \
		fi; \
		if [ $(ARCH) = "ios" ]; then \
			LLVM_CFLAGS="-arch armv7 -isysroot $(IOSSDK) -miphoneos-version-min=$(IOSVERS)"; \
			LLVM_EXTRA_OPTIONS="--with-extra-options=$$LLVM_CFLAGS"; \
			LLVM_HOST="--host=armv7-apple-darwin"; \
			LLVM_TARGET="--target=armv7-apple-darwin"; \
			LLVM_BUILD="--build=i386-apple-darwin"; \
			LLVM_BUILD_CC="BUILD_CC=$(CC)"; \
			LLVM_BUILD_CXX="BUILD_CXX=$(CXX)"; \
		fi; \
		if [ $(ARCH) = "solaris64CC5" ]; then \
			LLVM_CFLAGS="-m64"; \
		fi; \
		if [ $(ARCH) = "linuxppc64gcc" ]; then \
			LLVM_CFLAGS="-m64"; \
		fi; \
		if [ $(ARCH) = "linuxppcgcc" ]; then \
			LLVM_CFLAGS="-m32"; \
		fi; \
		if [ $(ARCH) = "hpuxia64acc" ]; then \
			LLVMCC="cc"; \
			LLVMCXX="aCC"; \
			LLVM_CFLAGS="+DD64 -Ae"; \
		fi; \
		if [ $(LIBCXX) = "yes" ]; then \
			LLVMLIBCXX="--enable-libcpp"; \
		fi; \
		if [ "x$$LLVM_EXTRA_OPTIONS" = "x" ]; then \
			LLVM_EXTRA_OPTIONS="--with-extra-options="; \
		fi; \
		if [ x$(GCCTOOLCHAIN) != "x" ]; then \
			LLVM_GCC_TOOLCHAIN="--with-gcc-toolchain=$(GCCTOOLCHAIN)"; \
		fi; \
		echo "*** Configuring LLVM in $(dir $@) ..."; \
		mkdir -p $(dir $@) && \
		cd $(dir $@)  && \
		GNUMAKE=$(MAKE) $(LLVMDIRS)/configure --enable-cxx11 \
		$$LLVM_HOST \
		$$LLVM_TARGET \
		$$LLVM_BUILD \
		--prefix=$(ROOT_OBJDIR)/$(LLVMDIRI) \
		--disable-docs --disable-bindings \
		--disable-visibility-inlines-hidden \
		--disable-clang-rewriter --disable-clang-static-analyzer \
		--disable-clang-arcmt \
		--disable-compiler-version-checks \
		$$LLVMLIBCXX \
		$(LLVMOPTFLAGS) \
		--enable-targets=host \
		"$$LLVM_EXTRA_OPTIONS" \
		$$LLVM_GCC_TOOLCHAIN \
		CC=$$LLVMCC CXX=$$LLVMCXX \
		$$LLVM_BUILD_CC $$LLVM_BUILD_CXX \
		CFLAGS="$$LLVM_CFLAGS" CXXFLAGS="$$LLVM_CFLAGS" )

all-$(MODNAME): $(LLVMLIB)

clean-llvm:
		-@(if [ -d $(LLVMDIRO) ]; then \
			cd $(LLVMDIRO); \
			$(MAKE) clean ONLY_TOOLS=clang NOCLING=1 $(ROOT_NOCLANG); \
		fi)

clean::         clean-$(MODNAME)

distclean-$(MODNAME): clean-$(MODNAME)
		@rm -rf $(LLVMDIRO) $(LLVMDIRI)

# Don't clean LLVM when doing standard "make distclean" as it is mostly not
# needed. To explicitly clean LLVM do either: "make maintainer-clean" or
# "make distclean-llvm".
#distclean::     distclean-$(MODNAME)
maintainer-clean:: distclean-$(MODNAME)

endif
