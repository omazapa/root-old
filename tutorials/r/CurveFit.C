#include "TRandom.h"
#include "TMath.h"
//Example take from http://www.itc.nl/~rossiter/teach/R/R_CurveFit.pdf
//Please read the file R_CurveFit.pdf while read this code.

void CurveFit()
{
   gSystem->Load("libRInterface.so");
   //Example of fitting a curve, using RInterface
   //This example is for a ROOT R interface,
   //Author:Omar Zapata
   
   ROOT::R::TRInterface r(0,0,true,true);
   //////////////////////////////////////////////////////
   //Task 1 setting up data to fit and make data frame //
   //////////////////////////////////////////////////////
   Int_t len = 24;
   Double_t *x = new Double_t[len];
   Double_t *y = new Double_t[len];

   //Generate points along a X^3 with noise
  TRandom rg;
    rg.SetSeed(520);
    for (Int_t i=0; i<len; i++) {
      x[i] = rg.Uniform(0,1);
      y[i] = TMath::Power(x[i],3) + rg.Gaus()*0.06;
    }
   r.assign(len,"x"); 
   r.assign(TVectorD(len,x),"x"); 
   r.assign(TVectorD(len,y),"y");
   
   r.parse("ds<-data.frame(x=x,y=y)");
   r.parse("str(ds)");
   r.x11();//to active de window for plot
   r.plot("y~x,main = 'Known cubic, with noise'");
   r.parse("s <- seq(0,1,length = 100)");
   r.lines("s,s^3,lty = 2 , col = 'green'");
   
   ////////////////////////////////////////////////////////////////////////////////////
   //Task 2 fit a poder model, with zero intercep using Nonlinear Least Squares (nls)//
   ////////////////////////////////////////////////////////////////////////////////////
   r.parse("m <- nls(y ~ I(x^power),data = ds, start = list(power = 1),trace = T)");
   
   ///////////////////////////////
   //Task 3 Display the Solution//
   ///////////////////////////////
   
   r.parse("summary(m)$coefficients");
   
   ///////////////////////////////////////////////////////
   //Task 4 Plot the fitted curve against the know curve//
   ///////////////////////////////////////////////////////
   
   r.parse("power <- round(summary(m)$coefficients[1],3)");
   r.parse("power.se <- round(summary(m)$coefficients[2],3)");
   r.plot("y ~ x, main='Fitted power model',sub = 'blue:fit; green:known'");
   r.lines("s,s^3,lty = 2 , col = 'green'");
   r.lines("s,predict(m,list(x=s)),lty = 1 , col = 'blue'");
   r.text("0,0.5,paste('y = x^(',power ,'+/-',power.se,')',sep = ''),pos = 4");
   
   ///////////////////////////////////////////
   //Task 5 Determine the quality of the fit//
   ///////////////////////////////////////////
   r.parse("RSS.p <- sum(residuals(m)^2)");
   r.parse("TSS   <- sum((y-mean(y))^2)");
   r.parse("1-(RSS.p/TSS)");
   r.parse("1-sum((x^3 - y)^2)/TSS");
   
   
   getchar();
}