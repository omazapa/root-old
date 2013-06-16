## include headers and libraries for R 
RCPPFLAGS := 		$(shell R CMD config --cppflags)
RLDFLAGS := 		$(shell R CMD config --ldflags)
RBLAS := 		$(shell R CMD config BLAS_LIBS)
RLAPACK := 		$(shell R CMD config LAPACK_LIBS)
 
## if you need to set an rpath to R itself, also uncomment
#RRPATH :=		-Wl,-rpath,$(R_HOME)/lib
 
## include headers and libraries for Rcpp interface classes
RCPPINCL := 		$(shell echo 'Rcpp:::CxxFlags()' | R --vanilla --slave)
RCPPLIBS := 		$(shell echo 'Rcpp:::LdFlags()'  | R --vanilla --slave)
 
 
## include headers and libraries for RInside embedding classes
RINSIDEINCL := 		$(shell echo 'RInside:::CxxFlags()' | R --vanilla --slave)
RINSIDELIBS := 		$(shell echo 'RInside:::LdFlags()'  | R --vanilla --slave)

## include headers and libraries for RInside embedding classes
ROOTINCL := 		$(shell root-config --cflags)
ROOTLIBS := 		$(shell root-config --libs) -lRInterface

CXXFLAGS := 		$(RCPPFLAGS) $(RCPPINCL) $(RINSIDEINCL) $(ROOTINCL)
LDLIBS := 		$(RLDFLAGS) $(RRPATH) $(RBLAS) $(RLAPACK) $(RCPPLIBS) $(RINSIDELIBS) $(ROOTLIBS)
 
all:Functions

Functions:Functions.cxx
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDLIBS)
