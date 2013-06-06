//Example take from http://stat.ethz.ch/R-manual/R-patched/library/stats/html/optimize.html
#include<TRInterface.h>
void SimpleOptim()
{
   //This example is for a ROOT R interface,
   //Author:Omar Zapata

   gR->parse("f <- function (x, a) {(x - a)^2}");
   gR->parse("xmin <- optimize(f, c(0, 1), tol = 0.0001, a = 1/3)");
   gR->parse("xmin");

   gR->parse("optimize(function(x) x^2*(print(x)-1), lower = 0, upper = 10)");

   gR->parse("f  <- function(x) {ifelse(x > -1, ifelse(x < 4, exp(-1/abs(x - 1)), 10), 10)}");
   gR->parse("fp <- function(x) { print(x); f(x) }");
   gR->x11();//required to show plot
   gR->plot("f, -2,5, ylim = 0:1, col = 2");
   gR->parse("optimize(fp, c(-4, 20))");   // doesn't see the minimum
   gR->parse("optimize(fp, c(-7, 20))");   // ok
}
