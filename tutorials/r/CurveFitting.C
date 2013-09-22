//Example taken from http://www.itc.nl/~rossiter/teach/R/R_CurveFit.pdf
//Please read the file R_CurveFit.pdf while reading this code.
#include<TRInterface.h>
void CurveFitting()
{
   //Fitting of a curve, using RInterface
   //This example is for a ROOTR interface,
   //Author:Omar Zapata

   //////////////////////////////////////////////////////
   //Task 1.  Generate the data for fitting and make a dataframe //
   //////////////////////////////////////////////////////
   Int_t len = 24;
   TVectorD x(len);
   TVectorD y(len);

   //Generate points along a X^3 with noise
   TRandom rg;
   rg.SetSeed(520);
   for (Int_t i = 0; i < len; i++) {
      x[i] = rg.Uniform(0, 1);
      y[i] = TMath::Power(x[i], 3) + rg.Gaus() * 0.06;
   }
   ROOT::R::TRInterface &r=gR->Instance();
   r["x"]=x;
   r["y"]=y;

   r.Parse("ds<-data.frame(x=x,y=y)");
   r.Parse("str(ds)");
   r.Xwin();//to active a new window for plotting
   r.plot("y~x,main = 'Known cubic, with noise'");
   r.Parse("s <- seq(0,1,length = 100)");
   r.lines("s,s^3,lty = 2 , col = 'green'");

   ////////////////////////////////////////////////////////////////////////////////////
   //Task 2. Fit a power model with zero intercept, using Nonlinear Least Squares (nls)//
   ////////////////////////////////////////////////////////////////////////////////////
   r.Parse("m <- nls(y ~ I(x^power),data = ds, start = list(power = 1),trace = T)");

   ///////////////////////////////
   //Task 3. Display the Solution//
   ///////////////////////////////
   r.Parse("summary(m)$coefficients");

   ///////////////////////////////////////////////////////
   //Task 4. Plot the fitted curve against the known curve//
   ///////////////////////////////////////////////////////

   r.Parse("power <- round(summary(m)$coefficients[1],3)");
   r.Parse("power.se <- round(summary(m)$coefficients[2],3)");
   r.plot("y ~ x, main='Fitted power model',sub = 'blue:fit; green:known'");
   r.lines("s,s^3,lty = 2 , col = 'green'");
   r.lines("s,predict(m,list(x=s)),lty = 1 , col = 'blue'");
   r.text("0,0.5,paste('y = x^(',power ,'+/-',power.se,')',sep = ''),pos = 4");

   ///////////////////////////////////////////
   //Task 5. Determine the quality of the fit//
   ///////////////////////////////////////////
   r.Parse("RSS.p <- sum(residuals(m)^2)");
   r.Parse("TSS   <- sum((y-mean(y))^2)");
   r.Parse("1-(RSS.p/TSS)");
   r.Parse("1-sum((x^3 - y)^2)/TSS");

   ///////////////////////////////////////////
   //Task 5. Fit a power model and intercept.//
   ///////////////////////////////////////////
   //defining the function
   r.Parse("rhs <- function(x, b0, b1) { b0 + x^b1}");
   r.Parse("m.2 <- nls(y ~ rhs(x, intercept, power), data = ds,start = list(intercept = 0,power = 2), trace = T)");
   r.Parse("summary(m.2)");
   r.Xwin();//to active a new window for plotting
   r.plot("ds$y ~ ds$x, main = 'Fitted power model, with intercept',sub = 'Blue: fit; magenta: fit w/o intercept; green: known'");
   r.abline("h = 0, lty = 1, lwd = 0.5");
   r.lines("s, s^3, lty = 2, col = 'green'");
   r.lines("s, predict(m.2, list(x = s)), lty = 1, col = 'blue'");
   r.lines("s, predict(m, list(x = s)), lty = 2, col = 'magenta'");
   r.segments("x, y, x, fitted(m.2), lty = 2, col = 'red'");

   /////////////////////////////////////////////////////////////////////////////
   //Task 7. Compare the ﬁt with the known relation and the power-only model.//
   /////////////////////////////////////////////////////////////////////////////
   r.Parse("(RSS.pi <- sum(residuals(m.2)^2))");
   r.Parse("(RSS.p)");
   r.Parse("1 - (RSS.pi/TSS)");
   r.Parse("1 - (RSS.p/TSS)");
   r.Parse("1 - sum((x^3 - y)^2)/TSS");
}
