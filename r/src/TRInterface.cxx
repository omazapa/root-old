/*************************************************************************
* Copyright (C) 2013,  Gfif Developers                                   *
* Grupo de Fenomenologia de Interacciones Fundamentales                  *
* http://gfif.udea.edu.co                                                *
* División de ciencias de la computación Gfifdev                         *
* Class Created and Maintained By Omar Andres Zapata Mesa                *
* All rights reserved.                                                   *
*                                                                        *
*                                                                        *
* For the list of contributors see $ROOTSYS/README/CREDITS.              *
*************************************************************************/
#include<TRInterface.h>
#include<Rembedded.h>
#include<Rinterface.h>
#include<Rinternals.h>
#include<vector>

const char *argvs[] = {"rootr","--no-save", "--silent"};
ROOT::R::TRInterface *gR = new ROOT::R::TRInterface(3, argvs, true, false, true);
#include <readline/readline.h>
#include <readline/history.h>
//______________________________________________________________________________
/* Begin_Html
<center><h2>TRInterface class</h2></center>

</p>
The TRInterface class lets you procces R code from ROOT.<br>
You can call R libraries and their functions, plot results in R or ROOT language<br>
and to use the power of ROOT and R at the same time.<br>
It also lets you pass scalars, vectors and matrices from ROOT to R<br>
and from R to ROOT using TRObjectProxy.<br>
<br>
To plot in R environment you should first call the method Xwin() to initiliaze the window's system<br>
before calling the class' plotting methods.<br>
<br>
<i style="color:red;">NOTE</i> In the same way that TROOT class have an unique global object gROOT,<br>
TRInterface has gR. Not more objects of TRInterface class can be instantiated, but you can create objects using the methods
TRInterface& Instance() and TRInterface* InstancePtr() to create your objects or just to use directly gR object.<br>
<br>
</p>
Show an example below:
End_Html
Begin_Macro(source)
{

//Create an exponential fit
//The idea is to create a set of numbers x,y with noise from ROOT,
//pass then to R and fit the data to x^3,
//get the fitted coefficient(power) and plot the points with noise,
//the known function and the fitted function.
//Author:: Omar Zapata
   TCanvas *c1 = new TCanvas("c1","Curve Fit",700,500);
   c1->SetGrid();

   // draw a frame for multiples graphs
   TMultiGraph *mg = new TMultiGraph();

   // create the first graph (points with gaussian noise)
   const Int_t n = 24;
   Double_t x1[n] ;
   Double_t y1[n] ;
   //Generate points along a X^3 with noise
   TRandom rg;
   rg.SetSeed(520);
   for (Int_t i = 0; i < n; i++) {
      x1[i] = rg.Uniform(0, 1);
      y1[i] = TMath::Power(x1[i], 3) + rg.Gaus() * 0.06;
   }

   TGraph *gr1 = new TGraph(n,x1,y1);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(8);
   gr1->SetMarkerSize(1);
   mg->Add(gr1);

      // create second graph
   TF1 *f_known=new TF1("f_known","pow(x,3)",0,1);
   TGraph *gr2 = new TGraph(f_known);
   gr2->SetMarkerColor(kRed);
   gr2->SetMarkerStyle(8);
   gr2->SetMarkerSize(1);
   mg->Add(gr2);

   //passing to R x and y values to fit
   gR->Assign(TVectorD(n, x1), "x");
   gR->Assign(TVectorD(n, y1), "y");
   //creating a R data frame
   gR->Parse("ds<-data.frame(x=x,y=y)");
   //fitting x and y to X^power using Nonlinear Least Squares
   gR->Parse("m <- nls(y ~ I(x^power),data = ds, start = list(power = 1),trace = T)");
   //getting the fitted value (power)
   ROOT::R::TRObjectProxy robj=gR->ParseEval("summary(m)$coefficients[1]");
   Double_t power=robj.ToScalar();

   TF1 *f_fitted=new TF1("f_fitted","pow(x,[0])",0,1);
   f_fitted->SetParameter(0,power);
   //plotting the fitted function
   TGraph *gr3 = new TGraph(f_fitted);
   gr3->SetMarkerColor(kGreen);
   gr3->SetMarkerStyle(8);
   gr3->SetMarkerSize(1);

   mg->Add(gr3);
   mg->Draw("ap");

   //displaying basic results
   TPaveText *pt = new TPaveText(0.1,0.6,0.5,0.9,"brNDC");
   pt->SetFillColor(18);
   pt->SetTextAlign(12);
   pt->AddText("Fitting x^power ");
   pt->AddText(" \"Blue\"   Points with gaussian noise to be fitted");
   pt->AddText(" \"Red\"    Known function x^3");
   TString fmsg;
   fmsg.Form(" \"Green\"  Fitted function with power=%.4lf",power);
   pt->AddText(fmsg);
   pt->Draw();
   c1->Update();
   return c1;
}
End_Macro */

using namespace ROOT::R;
ClassImp(TRInterface)

//Variables for READLINE
static SEXP
RComp_assignBufferSym,
RComp_assignStartSym,
RComp_assignEndSym,
RComp_assignTokenSym,
RComp_completeTokenSym,
RComp_getFileCompSym,
RComp_retrieveCompsSym;
SEXP rcompgen_rho;

char *R_completion_generator(const char *text, int state)
{
   // If this is a new word to complete, initialize now.  This
   //   involves saving 'text' to somewhere R can get at it, calling
   //   completeToken(), and retrieving the completions. 
   //NOTE: Code based R code and ajusted to Rcpp
   static int list_index, ncomp;
   static char **compstrings;


   if (!state) {
      int i;
      SEXP completions,
           assignCall = PROTECT(Rf_lang2(RComp_assignTokenSym, Rf_mkString(text))),
           completionCall = PROTECT(Rf_lang1(RComp_completeTokenSym)),
           retrieveCall = PROTECT(Rf_lang1(RComp_retrieveCompsSym));
      const void *vmax = vmaxget();

      Rf_eval(assignCall, rcompgen_rho);
      Rf_eval(completionCall, rcompgen_rho);
      PROTECT(completions = Rf_eval(retrieveCall, rcompgen_rho));
      list_index = 0;
      ncomp = Rf_length(completions);
      if (ncomp > 0) {
         compstrings = (char **) malloc(ncomp * sizeof(char*));
         if (!compstrings)  return (char *)NULL;
         for (i = 0; i < ncomp; i++)
            compstrings[i] = strdup(Rf_translateChar(STRING_ELT(completions, i)));
      }
      UNPROTECT(4);
      vmaxset(vmax);
   }

   if (list_index < ncomp)
      return compstrings[list_index++];
   else {
      /* nothing matched or remaining, so return NULL. */
      if (ncomp > 0) free(compstrings);
   }
   return (char *)NULL;
}

char ** R_custom_completion(const char *text, int start, int end)
{
   //NOTE: Code based R code and ajusted to Rcpp
   char **matches = (char **)NULL;
   SEXP infile,
        linebufferCall = PROTECT(Rf_lang2(RComp_assignBufferSym,
                                          Rf_mkString(rl_line_buffer))),
                         startCall = PROTECT(Rf_lang2(RComp_assignStartSym, Rf_ScalarInteger(start))),
                         endCall = PROTECT(Rf_lang2(RComp_assignEndSym, Rf_ScalarInteger(end)));
   SEXP filecompCall;

   // Don't want spaces appended at the end.  Need to do this
   // everytime, as readline>=6 resets it to ' '
   rl_completion_append_character = '\0';

   Rf_eval(linebufferCall, rcompgen_rho);
   Rf_eval(startCall, rcompgen_rho);
   Rf_eval(endCall, rcompgen_rho);
   UNPROTECT(3);
   matches = rl_completion_matches(text, R_completion_generator);
   filecompCall = PROTECT(Rf_lang1(RComp_getFileCompSym));
   infile = PROTECT(Rf_eval(filecompCall, rcompgen_rho));
   if (!Rf_asLogical(infile)) rl_attempted_completion_over = 1;
   UNPROTECT(2);
   return matches;
}

//______________________________________________________________________________
TRInterface::TRInterface(const int argc, const char *argv[], const bool loadRcpp, const bool verbose, const bool interactive)
{
// The command line arguments are by deafult argc=0 and argv=NULL,
// The verbose mode are by default disabled but you can enable it to show procedures information in stdout/stderr
   if (RInside::instancePtr()) throw std::runtime_error("Can only have one TRInterface instance");
   fR = new RInside(argc, argv, loadRcpp, verbose, interactive);

   //installing the readline callbacks for completion in the
   //method Interactive
   rcompgen_rho = R_FindNamespace(Rf_mkString("utils"));
   RComp_assignBufferSym  = Rf_install(".assignLinebuffer");
   RComp_assignStartSym   = Rf_install(".assignStart");
   RComp_assignEndSym     = Rf_install(".assignEnd");
   RComp_assignTokenSym   = Rf_install(".assignToken");
   RComp_completeTokenSym = Rf_install(".completeToken");
   RComp_getFileCompSym   = Rf_install(".getFileComp");
   RComp_retrieveCompsSym = Rf_install(".retrieveCompletions");
   rl_attempted_completion_function = R_custom_completion;

}



//______________________________________________________________________________
Int_t  TRInterface::ParseEval(const TString &code, TRObjectProxy  &ans)
{
// Parse R code and returns status of execution.
// the RObject's response is saved in  ans
   SEXP fans;
   Int_t fResult = fR->parseEval(code.Data(), fans);
   ans = fans;
   return fResult;
}

//______________________________________________________________________________
void TRInterface::Parse(const TString &code, Bool_t exception)
{
// Parse R code. The argument exception is by defualt false, and
// if the code has some error prints an error and continues executing.
// if exception if true, the code it launches an exception and stop the execution.
   if (exception) fR->parseEvalQ((std::string)code);
   else fR->parseEvalQNT(code.Data());
}

//______________________________________________________________________________
TRObjectProxy TRInterface::ParseEval(const TString &code, Bool_t exception)
{
// Parse R code. The argument exception is by defualt false, and
// if the code has some error prints an error and continues executing.
//if exception if true, the code launches an exception and stop the execution.
//The RObject result of execution is returned in TRObjectProxy
   if (exception) return TRObjectProxy((SEXP)fR->parseEval(code.Data()));
   else return TRObjectProxy((SEXP)fR->parseEvalNT(code.Data()));
}


void TRInterface::SetVerbose(Bool_t status)
{
   //verbose mode shows you all procedures in stdout/stderr
   //very important to debug and to see the results.
   fR->setVerbose(status);
}

//______________________________________________________________________________
TRInterface::Binding TRInterface::operator[](const TString& name)
{
   return Binding(this, name);
}

//______________________________________________________________________________
void TRInterface::Xwin(TString opt)
{
   //Initiliaze the window's system to do plots.
   //every platform has it owns system.
   //see R manual for x11(unix based systems),windows(MS windows)
#if defined(R__WIN32)
      Parse(TString("windows(" + opt + ")").Data());
#else
      Parse(TString("x11(" + opt + ")").Data());
#endif
}

//______________________________________________________________________________
void TRInterface::Assign(const TRFunction &obj, const TString & name)
{
   //This method let you to pass c++ functions to R environment.
   fR->assign(*obj.f, name.Data());
}

//______________________________________________________________________________
void TRInterface::Interactive()
{
   //this method launch a R command line to run directly R code that you can
   //pass to ROOT calling the apropiate method.

   while (kTRUE) {
      char * line = readline("[r]:");
      if (!line) continue;
      if (*line) add_history(line);
      if (std::string(line) == ".q") break;
      Parse(line, false);
      free(line);
   }
}

//______________________________________________________________________________
void TRInterface::Install(TString pkg,TString options)
{
  //utility function to install R's packages with default options.
  pkg.Prepend("install.packages('");
  if(!options.IsNull()&&!options.IsWhitespace())pkg.Append("',"+options);
  pkg.Append(")");
  Parse(pkg);
}

//______________________________________________________________________________
void TRInterface::Remove(TString pkg)
{
  //utility function to remove R's packages with default options.
  pkg.Prepend("revome.packages('").Append("')");
  Parse(pkg);
}
