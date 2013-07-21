//generated Sat Jul 20 19:19:53 COT 2013
//Warning!! this header is auto-generated, the changes will be removed!!
/*************************************************************************
* Copyright (C)  Gfif Developers                                         *
* Grupo de Fenomenologia de Interacciones Fundamentales                  *
* http://gfif.udea.edu.co                                                *
* División de ciencias de la computación Gfifdev                         *
* http://gfifdev.udea.edu.co                                             *
* Class Created and Maintained By Omar Andres Zapata Mesa                *
* All rights reserved.                                                   *
*                                                                        *
*                                                                        *
* For the list of contributors see /home/omazapa/MyProjects/root/README/CREDITS.              *
*************************************************************************/
#include"TComm.h"
#include"TMpiMessage.h"
#include<TArrayC.h>
#include<TArrayD.h>
#include<TArrayF.h>
#include<TArrayI.h>
#include<TArrayL.h>
#include<TArrayL64.h>
#include<TArrayS.h>
#include<TMatrixDEigen.h>
#include<TMatrixDSymEigen.h>
#include<TMatrixD.h>
#include<TMatrixF.h>
#include<TString.h>
#include<TStringLong.h>
#include<TFunction.h>
#include<TVectorD.h>
#include<TVectorF.h>
#include<TRotMatrix.h>
#include<TComplex.h>
#include<TVirtualFFT.h>
#include<TF12.h>
#include<TF1Editor.h>
#include<TF2.h>
#include<TF3.h>
#include<TMatrixTUtils.h>
#include<TObject.h>
#include<TMatrixTLazy.h>
#include<THnSparse.h>
#include<TMD5.h>
#include<TLorentzVector.h>
#include<TQuaternion.h>
#include<TVector2.h>
#include<TVector3.h>
#include<TDecompBK.h>
#include<TDecompBase.h>
#include<TDecompChol.h>
#include<TDecompLU.h>
#include<TDecompQRH.h>
#include<TDecompSVD.h>
#include<TDecompSparse.h>
#include<THnSparse.h>
#include<TMatrixTSparse.h>
#include<TMatrixDEigen.h>
#include<TMatrixDSymEigen.h>
#include<TMatrixTSym.h>
#include<TMessage.h>
#include<TH1D.h>
#include<TFormula.h>
#include<TFormulaPrimitive.h>
#include<TFunction.h>
#include<TH1.h>
#include<TH1C.h>
#include<TH1D.h>
#include<TH1Editor.h>
#include<TH1F.h>
#include<TH1I.h>
#include<TH1K.h>
#include<TH1S.h>
#include<TLine.h>
#include<TList.h>
#include<TMap.h>
#include<TCollection.h>
#include<TBits.h>
#include<TParameter.h>
#include<TPointSet3D.h>
#include<TPoints.h>
#include<TPoints3D.h>
#include<TPoints3DABC.h>
#include<TPointsArray3D.h>
#include<TPolyLine.h>
#include<TPolyLine3D.h>
#include<TPolyLineShape.h>
#include<TPolyMarker.h>
#include<TPolyMarker3D.h>
#include<TRandom.h>
#include<TRandom1.h>
#include<TRandom2.h>
#include<TRandom3.h>
#include<TSpline.h>
#include<TStatistic.h>
#include<TTime.h>
#include<TTimeStamp.h>
#include<TTimer.h>
#include<TUUID.h>
#include<TSysEvtHandler.h>
#include<TSystem.h>
#include<TSystemDirectory.h>
#include<TSystemFile.h>
#include<TString.h>
#include<TStringLong.h>
#include<TPRegexp.h>
#include<TTable.h>
#include<TTable3Points.h>
#include<TTableDescriptor.h>
#include<TTableIter.h>
#include<TTableMap.h>
#include<TTablePoints.h>
#include<TTableSorter.h>
#include<TTask.h>
#include<TUri.h>
#include<TUrl.h>
#include<TTree.h>
#include<TTreeCache.h>
#include<TTreeCacheUnzip.h>
#include<TTreeCloner.h>
#include<TTreeDrawArgsParser.h>
#include<TTreeFormula.h>
#include<TTreeFormulaManager.h>
#include<TTreeIndex.h>
#include<TTreePerfStats.h>
#include<TTreePlayer.h>
#include<TTreeResult.h>
#include<TTreeRow.h>
#include<TTreeSQL.h>
#include<TTreeTableInterface.h>
#include<TFitter.h>
#include<TLinearFitter.h>
#include<TLinearMinimizer.h>
#include<TMinuit.h>
#include<TMinuitMinimizer.h>
#ifdef __CINT__ 
namespace ROOT{
namespace Mpi{
//______________________________________________________________________________
//Support for class TArrayC
template<> void TComm::BcastObject<TArrayC>(TArrayC &obj, Int_t root);
template<> void TComm::BcastObject<TArrayC>(TArrayC *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TArrayD
template<> void TComm::BcastObject<TArrayD>(TArrayD &obj, Int_t root);
template<> void TComm::BcastObject<TArrayD>(TArrayD *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TArrayF
template<> void TComm::BcastObject<TArrayF>(TArrayF &obj, Int_t root);
template<> void TComm::BcastObject<TArrayF>(TArrayF *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TArrayI
template<> void TComm::BcastObject<TArrayI>(TArrayI &obj, Int_t root);
template<> void TComm::BcastObject<TArrayI>(TArrayI *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TArrayL
template<> void TComm::BcastObject<TArrayL>(TArrayL &obj, Int_t root);
template<> void TComm::BcastObject<TArrayL>(TArrayL *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TArrayL64
template<> void TComm::BcastObject<TArrayL64>(TArrayL64 &obj, Int_t root);
template<> void TComm::BcastObject<TArrayL64>(TArrayL64 *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TArrayS
template<> void TComm::BcastObject<TArrayS>(TArrayS &obj, Int_t root);
template<> void TComm::BcastObject<TArrayS>(TArrayS *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TVectorT<double>
template<> void TComm::BcastObject<TVectorT<double>>(TVectorT<double> &obj, Int_t root);
template<> void TComm::BcastObject<TVectorT<double>>(TVectorT<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TVectorT<float>
template<> void TComm::BcastObject<TVectorT<float>>(TVectorT<float> &obj, Int_t root);
template<> void TComm::BcastObject<TVectorT<float>>(TVectorT<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TComplex
template<> void TComm::BcastObject<TComplex>(TComplex &obj, Int_t root);
template<> void TComm::BcastObject<TComplex>(TComplex *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TF12
template<> void TComm::BcastObject<TF12>(TF12 &obj, Int_t root);
template<> void TComm::BcastObject<TF12>(TF12 *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TF2
template<> void TComm::BcastObject<TF2>(TF2 &obj, Int_t root);
template<> void TComm::BcastObject<TF2>(TF2 *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TF3
template<> void TComm::BcastObject<TF3>(TF3 &obj, Int_t root);
template<> void TComm::BcastObject<TF3>(TF3 *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TObject
template<> void TComm::BcastObject<TObject>(TObject &obj, Int_t root);
template<> void TComm::BcastObject<TObject>(TObject *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THilbertMatrixT<double>
template<> void TComm::BcastObject<THilbertMatrixT<double>>(THilbertMatrixT<double> &obj, Int_t root);
template<> void TComm::BcastObject<THilbertMatrixT<double>>(THilbertMatrixT<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THilbertMatrixT<float>
template<> void TComm::BcastObject<THilbertMatrixT<float>>(THilbertMatrixT<float> &obj, Int_t root);
template<> void TComm::BcastObject<THilbertMatrixT<float>>(THilbertMatrixT<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THilbertMatrixTSym<double>
template<> void TComm::BcastObject<THilbertMatrixTSym<double>>(THilbertMatrixTSym<double> &obj, Int_t root);
template<> void TComm::BcastObject<THilbertMatrixTSym<double>>(THilbertMatrixTSym<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THilbertMatrixTSym<float>
template<> void TComm::BcastObject<THilbertMatrixTSym<float>>(THilbertMatrixTSym<float> &obj, Int_t root);
template<> void TComm::BcastObject<THilbertMatrixTSym<float>>(THilbertMatrixTSym<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THaarMatrixT<double>
template<> void TComm::BcastObject<THaarMatrixT<double>>(THaarMatrixT<double> &obj, Int_t root);
template<> void TComm::BcastObject<THaarMatrixT<double>>(THaarMatrixT<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THaarMatrixT<float>
template<> void TComm::BcastObject<THaarMatrixT<float>>(THaarMatrixT<float> &obj, Int_t root);
template<> void TComm::BcastObject<THaarMatrixT<float>>(THaarMatrixT<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayC>
template<> void TComm::BcastObject<THnSparseT<TArrayC>>(THnSparseT<TArrayC> &obj, Int_t root);
template<> void TComm::BcastObject<THnSparseT<TArrayC>>(THnSparseT<TArrayC> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayS>
template<> void TComm::BcastObject<THnSparseT<TArrayS>>(THnSparseT<TArrayS> &obj, Int_t root);
template<> void TComm::BcastObject<THnSparseT<TArrayS>>(THnSparseT<TArrayS> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayI>
template<> void TComm::BcastObject<THnSparseT<TArrayI>>(THnSparseT<TArrayI> &obj, Int_t root);
template<> void TComm::BcastObject<THnSparseT<TArrayI>>(THnSparseT<TArrayI> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayL>
template<> void TComm::BcastObject<THnSparseT<TArrayL>>(THnSparseT<TArrayL> &obj, Int_t root);
template<> void TComm::BcastObject<THnSparseT<TArrayL>>(THnSparseT<TArrayL> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayF>
template<> void TComm::BcastObject<THnSparseT<TArrayF>>(THnSparseT<TArrayF> &obj, Int_t root);
template<> void TComm::BcastObject<THnSparseT<TArrayF>>(THnSparseT<TArrayF> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayD>
template<> void TComm::BcastObject<THnSparseT<TArrayD>>(THnSparseT<TArrayD> &obj, Int_t root);
template<> void TComm::BcastObject<THnSparseT<TArrayD>>(THnSparseT<TArrayD> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMD5
template<> void TComm::BcastObject<TMD5>(TMD5 &obj, Int_t root);
template<> void TComm::BcastObject<TMD5>(TMD5 *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TLorentzVector
template<> void TComm::BcastObject<TLorentzVector>(TLorentzVector &obj, Int_t root);
template<> void TComm::BcastObject<TLorentzVector>(TLorentzVector *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TQuaternion
template<> void TComm::BcastObject<TQuaternion>(TQuaternion &obj, Int_t root);
template<> void TComm::BcastObject<TQuaternion>(TQuaternion *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TVector2
template<> void TComm::BcastObject<TVector2>(TVector2 &obj, Int_t root);
template<> void TComm::BcastObject<TVector2>(TVector2 *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TVector3
template<> void TComm::BcastObject<TVector3>(TVector3 &obj, Int_t root);
template<> void TComm::BcastObject<TVector3>(TVector3 *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TDecompBK
template<> void TComm::BcastObject<TDecompBK>(TDecompBK &obj, Int_t root);
template<> void TComm::BcastObject<TDecompBK>(TDecompBK *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TDecompBase
template<> void TComm::BcastObject<TDecompBase>(TDecompBase &obj, Int_t root);
template<> void TComm::BcastObject<TDecompBase>(TDecompBase *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TDecompChol
template<> void TComm::BcastObject<TDecompChol>(TDecompChol &obj, Int_t root);
template<> void TComm::BcastObject<TDecompChol>(TDecompChol *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TDecompLU
template<> void TComm::BcastObject<TDecompLU>(TDecompLU &obj, Int_t root);
template<> void TComm::BcastObject<TDecompLU>(TDecompLU *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TDecompQRH
template<> void TComm::BcastObject<TDecompQRH>(TDecompQRH &obj, Int_t root);
template<> void TComm::BcastObject<TDecompQRH>(TDecompQRH *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TDecompSVD
template<> void TComm::BcastObject<TDecompSVD>(TDecompSVD &obj, Int_t root);
template<> void TComm::BcastObject<TDecompSVD>(TDecompSVD *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TDecompSparse
template<> void TComm::BcastObject<TDecompSparse>(TDecompSparse &obj, Int_t root);
template<> void TComm::BcastObject<TDecompSparse>(TDecompSparse *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseArrayChunk
template<> void TComm::BcastObject<THnSparseArrayChunk>(THnSparseArrayChunk &obj, Int_t root);
template<> void TComm::BcastObject<THnSparseArrayChunk>(THnSparseArrayChunk *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayC>
template<> void TComm::BcastObject<THnSparseT<TArrayC>>(THnSparseT<TArrayC> &obj, Int_t root);
template<> void TComm::BcastObject<THnSparseT<TArrayC>>(THnSparseT<TArrayC> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayD>
template<> void TComm::BcastObject<THnSparseT<TArrayD>>(THnSparseT<TArrayD> &obj, Int_t root);
template<> void TComm::BcastObject<THnSparseT<TArrayD>>(THnSparseT<TArrayD> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayF>
template<> void TComm::BcastObject<THnSparseT<TArrayF>>(THnSparseT<TArrayF> &obj, Int_t root);
template<> void TComm::BcastObject<THnSparseT<TArrayF>>(THnSparseT<TArrayF> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayI>
template<> void TComm::BcastObject<THnSparseT<TArrayI>>(THnSparseT<TArrayI> &obj, Int_t root);
template<> void TComm::BcastObject<THnSparseT<TArrayI>>(THnSparseT<TArrayI> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayL>
template<> void TComm::BcastObject<THnSparseT<TArrayL>>(THnSparseT<TArrayL> &obj, Int_t root);
template<> void TComm::BcastObject<THnSparseT<TArrayL>>(THnSparseT<TArrayL> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayS>
template<> void TComm::BcastObject<THnSparseT<TArrayS>>(THnSparseT<TArrayS> &obj, Int_t root);
template<> void TComm::BcastObject<THnSparseT<TArrayS>>(THnSparseT<TArrayS> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixDEigen
template<> void TComm::BcastObject<TMatrixDEigen>(TMatrixDEigen &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixDEigen>(TMatrixDEigen *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixDSymEigen
template<> void TComm::BcastObject<TMatrixDSymEigen>(TMatrixDSymEigen &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixDSymEigen>(TMatrixDSymEigen *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixT<double>
template<> void TComm::BcastObject<TMatrixT<double>>(TMatrixT<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixT<double>>(TMatrixT<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixT<float>
template<> void TComm::BcastObject<TMatrixT<float>>(TMatrixT<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixT<float>>(TMatrixT<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTColumn<double>
template<> void TComm::BcastObject<TMatrixTColumn<double>>(TMatrixTColumn<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTColumn<double>>(TMatrixTColumn<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTColumn<float>
template<> void TComm::BcastObject<TMatrixTColumn<float>>(TMatrixTColumn<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTColumn<float>>(TMatrixTColumn<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTColumn_const<double>
template<> void TComm::BcastObject<TMatrixTColumn_const<double>>(TMatrixTColumn_const<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTColumn_const<double>>(TMatrixTColumn_const<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTColumn_const<float>
template<> void TComm::BcastObject<TMatrixTColumn_const<float>>(TMatrixTColumn_const<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTColumn_const<float>>(TMatrixTColumn_const<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTDiag<double>
template<> void TComm::BcastObject<TMatrixTDiag<double>>(TMatrixTDiag<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTDiag<double>>(TMatrixTDiag<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTDiag<float>
template<> void TComm::BcastObject<TMatrixTDiag<float>>(TMatrixTDiag<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTDiag<float>>(TMatrixTDiag<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTDiag_const<double>
template<> void TComm::BcastObject<TMatrixTDiag_const<double>>(TMatrixTDiag_const<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTDiag_const<double>>(TMatrixTDiag_const<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTDiag_const<float>
template<> void TComm::BcastObject<TMatrixTDiag_const<float>>(TMatrixTDiag_const<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTDiag_const<float>>(TMatrixTDiag_const<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTFlat<double>
template<> void TComm::BcastObject<TMatrixTFlat<double>>(TMatrixTFlat<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTFlat<double>>(TMatrixTFlat<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTFlat<float>
template<> void TComm::BcastObject<TMatrixTFlat<float>>(TMatrixTFlat<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTFlat<float>>(TMatrixTFlat<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTFlat_const<double>
template<> void TComm::BcastObject<TMatrixTFlat_const<double>>(TMatrixTFlat_const<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTFlat_const<double>>(TMatrixTFlat_const<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTFlat_const<float>
template<> void TComm::BcastObject<TMatrixTFlat_const<float>>(TMatrixTFlat_const<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTFlat_const<float>>(TMatrixTFlat_const<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTLazy<double>
template<> void TComm::BcastObject<TMatrixTLazy<double>>(TMatrixTLazy<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTLazy<double>>(TMatrixTLazy<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTLazy<float>
template<> void TComm::BcastObject<TMatrixTLazy<float>>(TMatrixTLazy<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTLazy<float>>(TMatrixTLazy<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTRow<double>
template<> void TComm::BcastObject<TMatrixTRow<double>>(TMatrixTRow<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTRow<double>>(TMatrixTRow<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTRow<float>
template<> void TComm::BcastObject<TMatrixTRow<float>>(TMatrixTRow<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTRow<float>>(TMatrixTRow<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTRow_const<double>
template<> void TComm::BcastObject<TMatrixTRow_const<double>>(TMatrixTRow_const<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTRow_const<double>>(TMatrixTRow_const<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTRow_const<float>
template<> void TComm::BcastObject<TMatrixTRow_const<float>>(TMatrixTRow_const<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTRow_const<float>>(TMatrixTRow_const<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparse<double>
template<> void TComm::BcastObject<TMatrixTSparse<double>>(TMatrixTSparse<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSparse<double>>(TMatrixTSparse<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparse<float>
template<> void TComm::BcastObject<TMatrixTSparse<float>>(TMatrixTSparse<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSparse<float>>(TMatrixTSparse<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag<double>
template<> void TComm::BcastObject<TMatrixTSparseDiag<double>>(TMatrixTSparseDiag<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSparseDiag<double>>(TMatrixTSparseDiag<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag<float>
template<> void TComm::BcastObject<TMatrixTSparseDiag<float>>(TMatrixTSparseDiag<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSparseDiag<float>>(TMatrixTSparseDiag<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag_const<double>
template<> void TComm::BcastObject<TMatrixTSparseDiag_const<double>>(TMatrixTSparseDiag_const<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSparseDiag_const<double>>(TMatrixTSparseDiag_const<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag_const<float>
template<> void TComm::BcastObject<TMatrixTSparseDiag_const<float>>(TMatrixTSparseDiag_const<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSparseDiag_const<float>>(TMatrixTSparseDiag_const<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow<double>
template<> void TComm::BcastObject<TMatrixTSparseRow<double>>(TMatrixTSparseRow<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSparseRow<double>>(TMatrixTSparseRow<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow<float>
template<> void TComm::BcastObject<TMatrixTSparseRow<float>>(TMatrixTSparseRow<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSparseRow<float>>(TMatrixTSparseRow<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow_const<double>
template<> void TComm::BcastObject<TMatrixTSparseRow_const<double>>(TMatrixTSparseRow_const<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSparseRow_const<double>>(TMatrixTSparseRow_const<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow_const<float>
template<> void TComm::BcastObject<TMatrixTSparseRow_const<float>>(TMatrixTSparseRow_const<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSparseRow_const<float>>(TMatrixTSparseRow_const<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSub<double>
template<> void TComm::BcastObject<TMatrixTSub<double>>(TMatrixTSub<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSub<double>>(TMatrixTSub<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSub<float>
template<> void TComm::BcastObject<TMatrixTSub<float>>(TMatrixTSub<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSub<float>>(TMatrixTSub<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSub_const<double>
template<> void TComm::BcastObject<TMatrixTSub_const<double>>(TMatrixTSub_const<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSub_const<double>>(TMatrixTSub_const<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSub_const<float>
template<> void TComm::BcastObject<TMatrixTSub_const<float>>(TMatrixTSub_const<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSub_const<float>>(TMatrixTSub_const<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSym<double>
template<> void TComm::BcastObject<TMatrixTSym<double>>(TMatrixTSym<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSym<double>>(TMatrixTSym<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSym<float>
template<> void TComm::BcastObject<TMatrixTSym<float>>(TMatrixTSym<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSym<float>>(TMatrixTSym<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSymLazy<double>
template<> void TComm::BcastObject<TMatrixTSymLazy<double>>(TMatrixTSymLazy<double> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSymLazy<double>>(TMatrixTSymLazy<double> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSymLazy<float>
template<> void TComm::BcastObject<TMatrixTSymLazy<float>>(TMatrixTSymLazy<float> &obj, Int_t root);
template<> void TComm::BcastObject<TMatrixTSymLazy<float>>(TMatrixTSymLazy<float> *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TString
template<> void TComm::BcastObject<TString>(TString &obj, Int_t root);
template<> void TComm::BcastObject<TString>(TString *obj,Int_t count, Int_t root);

//______________________________________________________________________________
//Support for class TStringLong
template<> void TComm::BcastObject<TStringLong>(TStringLong &obj, Int_t root);
template<> void TComm::BcastObject<TStringLong>(TStringLong *obj,Int_t count, Int_t root);

}
}
#endif
