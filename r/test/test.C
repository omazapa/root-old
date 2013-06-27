#include<TRInterface.h>
void test()
{
   TArrayD v(3);
   v[0] = 0;
   v[1] = 1;
   v[2] = 2;

   TMatrixD mat(2, 3);
   mat[0][0] = 1.1;
   mat[0][1] = 2.2;
   mat[0][2] = 3.3;
   mat[1][0] = 4.4;
   mat[1][1] = 5.5;
   mat[1][2] = 6.6;
   delete gR;
   ROOT::R::TRInterface r(0, 0, true, true);
   ROOT::R::TRObjectProxy robj;
   r.assign(v, "v");
   r.assign(TString("ROOTR"), "str");
   r.assign(mat, "mat");
   cout << "------------------------------\n";
   r.parse("cat(v)");
   cout << "------------------------------\n";
   r.parse("summary(v)");
   cout << "------------------------------\n";
   r.parse("v<-2*v");
   cout << "------------------------------\n";
   r.parse("M = matrix(c(2.1, 4.2, 3.3, 1.4, 5.5, 7.0),nrow=2,ncol=3)");
   cout << "------------------------------\n";
   r.parse("cat(M)");
   cout << "------------------------------\n";
   cout << "mat = \n";
   mat.Print();
   r.parse("mat");
   cout << "------------------------------\n";



   robj = r.parseEval("str");
   TString str = robj.toString();

   robj = r.parseEval("v");
   TVectorD vout = robj.toVector();
   cout << "------------------------------\n";
   TArrayD aout = robj.toArray();
   cout << "------------------------------\n";
   robj = r.parseEval("M");
   TMatrixD M = robj.toMatrix();
   robj = r.parseEval("mat");
   TMatrixD rmat = robj.toMatrix();

   cout << "---\n";
   cout << str.Data() << endl;
   cout << "---\n";
   cout << "[" << vout[0] << "," << vout[1] << "," << vout[2] << "]" << endl;
   cout << "[" << aout[0] << "," << aout[1] << "," << aout[2] << "]" << endl;
   cout << "---\n";
   M.Print();
   cout << "---\n";
   cout << "Original mat\n";
   mat.Print();

   cout << "Returned mat\n";
   rmat.Print();
   cout << "---\n";
}
