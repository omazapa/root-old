//Example take from http://www.itc.nl/~rossiter/teach/R/R_CurveFit.pdf
//Please read the file R_CurveFit.pdf while read this code.
#include<TRInterface.h>
void CurveFit()
{
   //Example of fitting a curve, using RInterface
   //This example is for a ROOT R interface,
   //Author:Omar Zapata

   //////////////////////////////////////////////////////
   //Task 1 setting up data to fit and make data frame //
   //////////////////////////////////////////////////////
   Int_t len = 24;
   Double_t *x = new Double_t[len];
   Double_t *y = new Double_t[len];

   //Generate points along a X^3 with noise
   TRandom rg;
   rg.SetSeed(520);
   for (Int_t i = 0; i < len; i++) {
      x[i] = rg.Uniform(0, 1);
      y[i] = TMath::Power(x[i], 3) + rg.Gaus() * 0.06;
   }
   gR->assign(len, "x");
   gR->assign(TVectorD(len, x), "x");
   gR->assign(TVectorD(len, y), "y");

   gR->parse("ds<-data.frame(x=x,y=y)");
   gR->parse("str(ds)");
   gR->x11();//to active new window for plot
   gR->plot("y~x,main = 'Known cubic, with noise'");
   gR->parse("s <- seq(0,1,length = 100)");
   gR->lines("s,s^3,lty = 2 , col = 'green'");

   ////////////////////////////////////////////////////////////////////////////////////
   //Task 2 fit a poder model, with zero intercep using Nonlinear Least Squares (nls)//
   ////////////////////////////////////////////////////////////////////////////////////
   gR->parse("m <- nls(y ~ I(x^power),data = ds, start = list(power = 1),trace = T)");

   ///////////////////////////////
   //Task 3 Display the Solution//
   ///////////////////////////////

   gR->parse("summary(m)$coefficients");

   ///////////////////////////////////////////////////////
   //Task 4 Plot the fitted curve against the know curve//
   ///////////////////////////////////////////////////////

   gR->parse("power <- round(summary(m)$coefficients[1],3)");
   gR->parse("power.se <- round(summary(m)$coefficients[2],3)");
   gR->plot("y ~ x, main='Fitted power model',sub = 'blue:fit; green:known'");
   gR->lines("s,s^3,lty = 2 , col = 'green'");
   gR->lines("s,predict(m,list(x=s)),lty = 1 , col = 'blue'");
   gR->text("0,0.5,paste('y = x^(',power ,'+/-',power.se,')',sep = ''),pos = 4");

   ///////////////////////////////////////////
   //Task 5 Determine the quality of the fit//
   ///////////////////////////////////////////
   gR->parse("RSS.p <- sum(residuals(m)^2)");
   gR->parse("TSS   <- sum((y-mean(y))^2)");
   gR->parse("1-(RSS.p/TSS)");
   gR->parse("1-sum((x^3 - y)^2)/TSS");

   ///////////////////////////////////////////
   //Task 5 Fit a power model and intercept.//
   ///////////////////////////////////////////
   //defining a function
   gR->parse("rhs <- function(x, b0, b1) { b0 + x^b1}");
   gR->parse("m.2 <- nls(y ~ rhs(x, intercept, power), data = ds,start = list(intercept = 0,power = 2), trace = T)");
   gR->parse("summary(m.2)");
   gR->x11();//to active new window for plot
   gR->plot("ds$y ~ ds$x, main = 'Fitted power model, with intercept',sub = 'Blue: fit; magenta: fit w/o intercept; green: known'");
   gR->abline("h = 0, lty = 1, lwd = 0.5");
   gR->lines("s, s^3, lty = 2, col = 'green'");
   gR->lines("s, predict(m.2, list(x = s)), lty = 1, col = 'blue'");
   gR->lines("s, predict(m, list(x = s)), lty = 2, col = 'magenta'");
   gR->segments("x, y, x, fitted(m.2), lty = 2, col = 'red'");

   /////////////////////////////////////////////////////////////////////////////
   //Task 7 : Compare the ﬁt with the known relation and the power-only model.//
   /////////////////////////////////////////////////////////////////////////////
   gR->parse("(RSS.pi <- sum(residuals(m.2)^2))");
   gR->parse("(RSS.p)");
   gR->parse("1 - (RSS.pi/TSS)");
   gR->parse("1 - (RSS.p/TSS)");
   gR->parse("1 - sum((x^3 - y)^2)/TSS");


}
