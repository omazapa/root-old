/*************************************************************************
 * Copyright (C) 2013-2014, Omar Andres Zapata Mesa                      *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#include<TRInterface.h>
#include"TRCompletion.h"
#include<vector>

#include<TRint.h>

//______________________________________________________________________________
/* Begin_Html
<center><h2>TRInterface class</h2></center>

</p>
The TRInterface class lets you procces R code from ROOT.<br>
You can call R libraries and their functions, plot results in R or ROOT,<br>
and use the power of ROOT and R at the same time.<br>
It also lets you pass scalars, vectors and matrices from ROOT to R<br>
and from R to ROOT using TRObjectProxy; but you can to use overloaded opetarors [],<< and >> <br>
to work with ROOTR like work with streams of data.<br>

<i style="color:red;">NOTE</i> In the same way that TROOT class has an unique global object, gROOT,<br>
TRInterface can have just one. More objects of TRInterface class can not be instantiated, but you can create objects using the static methods
TRInterface& Instance() and TRInterface* InstancePtr() to create your own objects.<br>
<br>
</p>
Show an example below:
End_Html
Begin_Macro(source)
{

//Create an exponential fit
//The idea is to create a set of numbers x,y with noise from ROOT,
//pass them to R and fit the data to x^3,
//get the fitted coefficient(power) and plot the data,
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

   //passing x and y values to R for fitting
   ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();
   r["x"]<<TVectorD(n, x1);
   r["y"]<<TVectorD(n, y1);
   //creating a R data frame
   r<<"ds<-data.frame(x=x,y=y)";
   //fitting x and y to X^power using Nonlinear Least Squares
   r<<"m <- nls(y ~ I(x^power),data = ds, start = list(power = 1),trace = T)";
   //getting the fitted value (power)
   Double_t power;
   r["summary(m)$coefficients[1]"]>>power;

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

// extern SEXP rcompgen_rho;

//function for ROOTR modules
extern "C" SEXP _rcpp_module_boot_ROOTR_TRF1();
extern "C" SEXP _rcpp_module_boot_ROOTR_TRGraph();
extern "C" SEXP _rcpp_module_boot_ROOTR_TRCanvas();
extern "C" SEXP _rcpp_module_boot_ROOTR_TRRint();
static ROOT::R::TRInterface *gR = NULL;
static Bool_t statusModules;

//______________________________________________________________________________
TRInterface::TRInterface(const int argc, const char *argv[], const bool loadRcpp, const bool verbose, const bool interactive): TObject()
{
// The command line arguments are by deafult argc=0 and argv=NULL,
// The verbose mode is by default disabled but you can enable it to show procedures information in stdout/stderr
   if (RInside::instancePtr()) throw std::runtime_error("Can only have one TRInterface instance");
   fR = new RInside(argc, argv, loadRcpp, verbose, interactive);

   //Installing the readline callbacks for completion in the
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
   statusModules = kFALSE;
}

void ROOT::R::TRInterface::LoadModule()
{
   if (!statusModules) {
      this->Assign(Rf_eval(Rf_lang2((ROOT::R::ModuleSymRef == NULL ? ROOT::R::ModuleSymRef = Rf_install("Module") : ROOT::R::ModuleSymRef), _rcpp_module_boot_ROOTR_TRF1()), R_GlobalEnv), "ROOTR_TRF1");
      this->Assign(Rf_eval(Rf_lang2((ROOT::R::ModuleSymRef == NULL ? ROOT::R::ModuleSymRef = Rf_install("Module") : ROOT::R::ModuleSymRef), _rcpp_module_boot_ROOTR_TRGraph()), R_GlobalEnv), "ROOTR_TRGraph");
      this->Assign(Rf_eval(Rf_lang2((ROOT::R::ModuleSymRef == NULL ? ROOT::R::ModuleSymRef = Rf_install("Module") : ROOT::R::ModuleSymRef), _rcpp_module_boot_ROOTR_TRCanvas()), R_GlobalEnv), "ROOTR_TRCanvas");
      this->Assign(Rf_eval(Rf_lang2((ROOT::R::ModuleSymRef == NULL ? ROOT::R::ModuleSymRef = Rf_install("Module") : ROOT::R::ModuleSymRef), _rcpp_module_boot_ROOTR_TRRint()), R_GlobalEnv), "ROOTR_TRRint");
      this->Parse("ROOTR <- c()");
      this->Parse("ROOTR$TRF1     <- function(name,formula){ new(ROOTR_TRF1$TRF1, name, formula) }");
      this->Parse("ROOTR$TRGraph  <- function(n,x,y){ new(ROOTR_TRGraph$TRGraph, n,x,y) }");
      this->Parse("ROOTR$TRCanvas <- function(name,tittle=''){ new(ROOTR_TRCanvas$TRCanvas, name,tittle) }");
      this->Parse("ROOTR$TRRint   <- function(name,args=c('')){ new(ROOTR_TRRint$TRRint,name,args) }");
      statusModules = kTRUE;
   }
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
// if the code has an error prints the error and continues executing.
// if exception is true, the code launches an exception and stops the execution.
   if (exception) fR->parseEvalQ((std::string)code);
   else fR->parseEvalQNT(code.Data());
}

//______________________________________________________________________________
TRObjectProxy TRInterface::ParseEval(const TString &code, Bool_t exception)
{
// Parse R code. The argument exception is by defualt false, and
// if the code has an error prints the error and continues executing.
//if exception is true, the code launches an exception and stops the execution.
//The RObject result of execution is returned in TRObjectProxy
   if (exception) return TRObjectProxy((SEXP)fR->parseEval(code.Data()));
   else return TRObjectProxy((SEXP)fR->parseEvalNT(code.Data()));
}


void TRInterface::SetVerbose(Bool_t status)
{
   //verbose mode shows you all the procedures in stdout/stderr
   //very important to debug and to see the results.
   fR->setVerbose(status);
}

//______________________________________________________________________________
TRInterface::Binding TRInterface::operator[](const TString &name)
{
   return Binding(this, name);
}

//______________________________________________________________________________
void TRInterface::Assign(const TRFunction &obj, const TString &name)
{
   //This method lets you pass c++ functions to R environment.
   fR->assign(*obj.f, name.Data());
}

//______________________________________________________________________________
void TRInterface::Interactive()
{
   //This method launches a R command line to run directly R code which you can
   //pass to ROOT calling the apropiate method.

   while (kTRUE) {
      char *line = readline("[r]:");
      if (!line) continue;
      if (std::string(line) == ".q") break;
      Parse(line, false);
      if (*line) add_history(line);
      free(line);
   }
}


//______________________________________________________________________________
TRInterface *TRInterface::InstancePtr()
{
   if (!gR) {
      const char *R_argv[] = {"rootr", "--gui=none", "--no-save", "--no-readline", "--silent", "--vanilla", "--slave"};
      gR = new ROOT::R::TRInterface(7, R_argv, true, false, false);
   }
   gR->LoadModule();
   return gR;
}

//______________________________________________________________________________
TRInterface &TRInterface::Instance()
{
   return  *ROOT::R::TRInterface::InstancePtr();
}



