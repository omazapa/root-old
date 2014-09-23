/*************************************************************************
* Copyright (C) 2013,  Gfif Developers                                   *
* Grupo de Fenomenologia de Interacciones Fundamentales                  *
* http://gfif.udea.edu.co                                                *
* División de ciencias de la computación Gfifdev                         *
* Class Created and Maintained By Omar Andres Zapata Mesa                *
* All rights reserved.                                                   *
*                                                                        *
* For the licensing terms see $ROOTSYS/LICENSE.                          *
* For the list of contributors see $ROOTSYS/README/CREDITS.              *
*************************************************************************/
#include<TRInterface.h>
#include"TRCompletion.h"
#include<vector>
static Bool_t statusEventLoop;
const char *argvs[] = {"rootr", "--no-save", "--silent"};
ROOT::R::TRInterface *gR = new ROOT::R::TRInterface(3, argvs, true, false, true);
//______________________________________________________________________________
/* Begin_Html
<center><h2>TRInterface class</h2></center>

</p>
The TRInterface class lets you procces R code from ROOT.<br>
You can call R libraries and their functions, plot results in R or ROOT,<br>
and use the power of ROOT and R at the same time.<br>
It also lets you pass scalars, vectors and matrices from ROOT to R<br>
and from R to ROOT using TRObjectProxy.<br>
<br>
To plot in R environment you should first call the method Xwin() to initiliaze the window's system<br>
before calling the class' plotting methods.<br>
<br>
<i style="color:red;">NOTE</i> In the same way that TROOT class has an unique global object, gROOT,<br>
TRInterface has gR. More objects of TRInterface class can not be instantiated, but you can create objects using the methods
TRInterface& Instance() and TRInterface* InstancePtr() to create your own objects or just to use directly a gR object.<br>
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

// extern SEXP rcompgen_rho;

//______________________________________________________________________________
TRInterface::TRInterface(const int argc, const char *argv[], const bool loadRcpp, const bool verbose, const bool interactive)
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
}

//______________________________________________________________________________
Int_t  TRInterface::ParseEval(const TString &code, TRObjectProxy  &ans)
{
// Parse R code and returns status of execution.
// the RObject's response is saved in  ans
   SEXP fans;
   Int_t rc = fR->parseEval(code.Data(), fans);
   ans = fans;
   ans.SetStatus((rc == 0) ? kTRUE : kFALSE);
   return rc;
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
   SEXP ans;
   int rc = fR->parseEval(code.Data(), ans);
   if (rc != 0 && exception) {
      if (exception) throw std::runtime_error(std::string("Error evaluating: ") + code.Data());
   } else if (rc != 0) {
      Error("ParseEval", (std::string("Error evaluating: ") + code.Data()).c_str());
   }   
   return TRObjectProxy(ans , (rc == 0) ? kTRUE : kFALSE);
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
void TRInterface::Xwin(TString opt)
{
   //Initiliaze the window's system to make plots.
   //every platform has its own system.
   //see R manual for x11(unix based systems),windows(MS windows)
#if defined(R__WIN32)
   Parse(TString("windows(" + opt + ")").Data());
#else
   Parse(TString("x11(" + opt + ")").Data());
#endif
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
void TRInterface::Install(TString pkg, TString options)
{
   //utility function to install R's packages with the default options.
   pkg.Prepend("install.packages('");
   if (!options.IsNull() && !options.IsWhitespace())pkg.Append("'," + options);
   pkg.Append(")");
   Parse(pkg);
}

//______________________________________________________________________________
void TRInterface::Remove(TString pkg)
{
   //utility function to remove R's packages with the default options.
   pkg.Prepend("revome.packages('").Append("')");
   Parse(pkg);
}

#undef _POSIX_C_SOURCE
#include <R_ext/eventloop.h>

static void _REventLoop(void *args)
{
   while (kTRUE) {
      fd_set *fd;
      int usec = 10000;
      fd = R_checkActivity(usec, 0);
      R_runHandlers(R_InputHandlers, fd);
      gSystem->Sleep(100);
   }
}

//______________________________________________________________________________
void TRInterface::ProcessEventsLoop()
{
   //run the R's eventloop to process graphics events
   if (!statusEventLoop) {
      th = new TThread(_REventLoop);
      th->Run();
      statusEventLoop = kTRUE;
   }
}
