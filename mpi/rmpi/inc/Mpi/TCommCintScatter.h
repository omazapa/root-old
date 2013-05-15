//generated Mon Apr  8 12:46:32 COT 2013
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
#include<TF2GL.h>
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
#include<TPointSet3DGL.h>
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
namespace ROOT {
   namespace Mpi {
//______________________________________________________________________________
//Support for class TArrayC
      template<> void TComm::ScatterObject<TArrayC>(const TArrayC *sendobjs, TArrayC &obj, Int_t root);

//______________________________________________________________________________
//Support for class TArrayD
      template<> void TComm::ScatterObject<TArrayD>(const TArrayD *sendobjs, TArrayD &obj, Int_t root);

//______________________________________________________________________________
//Support for class TArrayF
      template<> void TComm::ScatterObject<TArrayF>(const TArrayF *sendobjs, TArrayF &obj, Int_t root);

//______________________________________________________________________________
//Support for class TArrayI
      template<> void TComm::ScatterObject<TArrayI>(const TArrayI *sendobjs, TArrayI &obj, Int_t root);

//______________________________________________________________________________
//Support for class TArrayL
      template<> void TComm::ScatterObject<TArrayL>(const TArrayL *sendobjs, TArrayL &obj, Int_t root);

//______________________________________________________________________________
//Support for class TArrayL64
      template<> void TComm::ScatterObject<TArrayL64>(const TArrayL64 *sendobjs, TArrayL64 &obj, Int_t root);

//______________________________________________________________________________
//Support for class TArrayS
      template<> void TComm::ScatterObject<TArrayS>(const TArrayS *sendobjs, TArrayS &obj, Int_t root);

//______________________________________________________________________________
//Support for class TVectorT<double>
      template<> void TComm::ScatterObject<TVectorT<double>>(const TVectorT<double> *sendobjs, TVectorT<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TVectorT<float>
      template<> void TComm::ScatterObject<TVectorT<float>>(const TVectorT<float> *sendobjs, TVectorT<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TComplex
      template<> void TComm::ScatterObject<TComplex>(const TComplex *sendobjs, TComplex &obj, Int_t root);

//______________________________________________________________________________
//Support for class TF12
      template<> void TComm::ScatterObject<TF12>(const TF12 *sendobjs, TF12 &obj, Int_t root);

//______________________________________________________________________________
//Support for class TF2
      template<> void TComm::ScatterObject<TF2>(const TF2 *sendobjs, TF2 &obj, Int_t root);

//______________________________________________________________________________
//Support for class TF3
      template<> void TComm::ScatterObject<TF3>(const TF3 *sendobjs, TF3 &obj, Int_t root);

//______________________________________________________________________________
//Support for class TObject
      template<> void TComm::ScatterObject<TObject>(const TObject *sendobjs, TObject &obj, Int_t root);

//______________________________________________________________________________
//Support for class THilbertMatrixT<double>
      template<> void TComm::ScatterObject<THilbertMatrixT<double>>(const THilbertMatrixT<double> *sendobjs, THilbertMatrixT<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THilbertMatrixT<float>
      template<> void TComm::ScatterObject<THilbertMatrixT<float>>(const THilbertMatrixT<float> *sendobjs, THilbertMatrixT<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THilbertMatrixTSym<double>
      template<> void TComm::ScatterObject<THilbertMatrixTSym<double>>(const THilbertMatrixTSym<double> *sendobjs, THilbertMatrixTSym<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THilbertMatrixTSym<float>
      template<> void TComm::ScatterObject<THilbertMatrixTSym<float>>(const THilbertMatrixTSym<float> *sendobjs, THilbertMatrixTSym<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THaarMatrixT<double>
      template<> void TComm::ScatterObject<THaarMatrixT<double>>(const THaarMatrixT<double> *sendobjs, THaarMatrixT<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THaarMatrixT<float>
      template<> void TComm::ScatterObject<THaarMatrixT<float>>(const THaarMatrixT<float> *sendobjs, THaarMatrixT<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayC>
      template<> void TComm::ScatterObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> *sendobjs, THnSparseT<TArrayC> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayS>
      template<> void TComm::ScatterObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> *sendobjs, THnSparseT<TArrayS> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayI>
      template<> void TComm::ScatterObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> *sendobjs, THnSparseT<TArrayI> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayL>
      template<> void TComm::ScatterObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> *sendobjs, THnSparseT<TArrayL> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayF>
      template<> void TComm::ScatterObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> *sendobjs, THnSparseT<TArrayF> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayD>
      template<> void TComm::ScatterObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> *sendobjs, THnSparseT<TArrayD> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMD5
      template<> void TComm::ScatterObject<TMD5>(const TMD5 *sendobjs, TMD5 &obj, Int_t root);

//______________________________________________________________________________
//Support for class TLorentzVector
      template<> void TComm::ScatterObject<TLorentzVector>(const TLorentzVector *sendobjs, TLorentzVector &obj, Int_t root);

//______________________________________________________________________________
//Support for class TQuaternion
      template<> void TComm::ScatterObject<TQuaternion>(const TQuaternion *sendobjs, TQuaternion &obj, Int_t root);

//______________________________________________________________________________
//Support for class TVector2
      template<> void TComm::ScatterObject<TVector2>(const TVector2 *sendobjs, TVector2 &obj, Int_t root);

//______________________________________________________________________________
//Support for class TVector3
      template<> void TComm::ScatterObject<TVector3>(const TVector3 *sendobjs, TVector3 &obj, Int_t root);

//______________________________________________________________________________
//Support for class TDecompBK
      template<> void TComm::ScatterObject<TDecompBK>(const TDecompBK *sendobjs, TDecompBK &obj, Int_t root);

//______________________________________________________________________________
//Support for class TDecompBase
      template<> void TComm::ScatterObject<TDecompBase>(const TDecompBase *sendobjs, TDecompBase &obj, Int_t root);

//______________________________________________________________________________
//Support for class TDecompChol
      template<> void TComm::ScatterObject<TDecompChol>(const TDecompChol *sendobjs, TDecompChol &obj, Int_t root);

//______________________________________________________________________________
//Support for class TDecompLU
      template<> void TComm::ScatterObject<TDecompLU>(const TDecompLU *sendobjs, TDecompLU &obj, Int_t root);

//______________________________________________________________________________
//Support for class TDecompQRH
      template<> void TComm::ScatterObject<TDecompQRH>(const TDecompQRH *sendobjs, TDecompQRH &obj, Int_t root);

//______________________________________________________________________________
//Support for class TDecompSVD
      template<> void TComm::ScatterObject<TDecompSVD>(const TDecompSVD *sendobjs, TDecompSVD &obj, Int_t root);

//______________________________________________________________________________
//Support for class TDecompSparse
      template<> void TComm::ScatterObject<TDecompSparse>(const TDecompSparse *sendobjs, TDecompSparse &obj, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseArrayChunk
      template<> void TComm::ScatterObject<THnSparseArrayChunk>(const THnSparseArrayChunk *sendobjs, THnSparseArrayChunk &obj, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayC>
      template<> void TComm::ScatterObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> *sendobjs, THnSparseT<TArrayC> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayD>
      template<> void TComm::ScatterObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> *sendobjs, THnSparseT<TArrayD> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayF>
      template<> void TComm::ScatterObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> *sendobjs, THnSparseT<TArrayF> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayI>
      template<> void TComm::ScatterObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> *sendobjs, THnSparseT<TArrayI> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayL>
      template<> void TComm::ScatterObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> *sendobjs, THnSparseT<TArrayL> &obj, Int_t root);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayS>
      template<> void TComm::ScatterObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> *sendobjs, THnSparseT<TArrayS> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixDEigen
      template<> void TComm::ScatterObject<TMatrixDEigen>(const TMatrixDEigen *sendobjs, TMatrixDEigen &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixDSymEigen
      template<> void TComm::ScatterObject<TMatrixDSymEigen>(const TMatrixDSymEigen *sendobjs, TMatrixDSymEigen &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixT<double>
      template<> void TComm::ScatterObject<TMatrixT<double>>(const TMatrixT<double> *sendobjs, TMatrixT<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixT<float>
      template<> void TComm::ScatterObject<TMatrixT<float>>(const TMatrixT<float> *sendobjs, TMatrixT<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTColumn<double>
      template<> void TComm::ScatterObject<TMatrixTColumn<double>>(const TMatrixTColumn<double> *sendobjs, TMatrixTColumn<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTColumn<float>
      template<> void TComm::ScatterObject<TMatrixTColumn<float>>(const TMatrixTColumn<float> *sendobjs, TMatrixTColumn<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTColumn_const<double>
      template<> void TComm::ScatterObject<TMatrixTColumn_const<double>>(const TMatrixTColumn_const<double> *sendobjs, TMatrixTColumn_const<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTColumn_const<float>
      template<> void TComm::ScatterObject<TMatrixTColumn_const<float>>(const TMatrixTColumn_const<float> *sendobjs, TMatrixTColumn_const<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTDiag<double>
      template<> void TComm::ScatterObject<TMatrixTDiag<double>>(const TMatrixTDiag<double> *sendobjs, TMatrixTDiag<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTDiag<float>
      template<> void TComm::ScatterObject<TMatrixTDiag<float>>(const TMatrixTDiag<float> *sendobjs, TMatrixTDiag<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTDiag_const<double>
      template<> void TComm::ScatterObject<TMatrixTDiag_const<double>>(const TMatrixTDiag_const<double> *sendobjs, TMatrixTDiag_const<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTDiag_const<float>
      template<> void TComm::ScatterObject<TMatrixTDiag_const<float>>(const TMatrixTDiag_const<float> *sendobjs, TMatrixTDiag_const<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTFlat<double>
      template<> void TComm::ScatterObject<TMatrixTFlat<double>>(const TMatrixTFlat<double> *sendobjs, TMatrixTFlat<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTFlat<float>
      template<> void TComm::ScatterObject<TMatrixTFlat<float>>(const TMatrixTFlat<float> *sendobjs, TMatrixTFlat<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTFlat_const<double>
      template<> void TComm::ScatterObject<TMatrixTFlat_const<double>>(const TMatrixTFlat_const<double> *sendobjs, TMatrixTFlat_const<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTFlat_const<float>
      template<> void TComm::ScatterObject<TMatrixTFlat_const<float>>(const TMatrixTFlat_const<float> *sendobjs, TMatrixTFlat_const<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTLazy<double>
      template<> void TComm::ScatterObject<TMatrixTLazy<double>>(const TMatrixTLazy<double> *sendobjs, TMatrixTLazy<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTLazy<float>
      template<> void TComm::ScatterObject<TMatrixTLazy<float>>(const TMatrixTLazy<float> *sendobjs, TMatrixTLazy<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTRow<double>
      template<> void TComm::ScatterObject<TMatrixTRow<double>>(const TMatrixTRow<double> *sendobjs, TMatrixTRow<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTRow<float>
      template<> void TComm::ScatterObject<TMatrixTRow<float>>(const TMatrixTRow<float> *sendobjs, TMatrixTRow<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTRow_const<double>
      template<> void TComm::ScatterObject<TMatrixTRow_const<double>>(const TMatrixTRow_const<double> *sendobjs, TMatrixTRow_const<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTRow_const<float>
      template<> void TComm::ScatterObject<TMatrixTRow_const<float>>(const TMatrixTRow_const<float> *sendobjs, TMatrixTRow_const<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparse<double>
      template<> void TComm::ScatterObject<TMatrixTSparse<double>>(const TMatrixTSparse<double> *sendobjs, TMatrixTSparse<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparse<float>
      template<> void TComm::ScatterObject<TMatrixTSparse<float>>(const TMatrixTSparse<float> *sendobjs, TMatrixTSparse<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag<double>
      template<> void TComm::ScatterObject<TMatrixTSparseDiag<double>>(const TMatrixTSparseDiag<double> *sendobjs, TMatrixTSparseDiag<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag<float>
      template<> void TComm::ScatterObject<TMatrixTSparseDiag<float>>(const TMatrixTSparseDiag<float> *sendobjs, TMatrixTSparseDiag<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag_const<double>
      template<> void TComm::ScatterObject<TMatrixTSparseDiag_const<double>>(const TMatrixTSparseDiag_const<double> *sendobjs, TMatrixTSparseDiag_const<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag_const<float>
      template<> void TComm::ScatterObject<TMatrixTSparseDiag_const<float>>(const TMatrixTSparseDiag_const<float> *sendobjs, TMatrixTSparseDiag_const<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow<double>
      template<> void TComm::ScatterObject<TMatrixTSparseRow<double>>(const TMatrixTSparseRow<double> *sendobjs, TMatrixTSparseRow<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow<float>
      template<> void TComm::ScatterObject<TMatrixTSparseRow<float>>(const TMatrixTSparseRow<float> *sendobjs, TMatrixTSparseRow<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow_const<double>
      template<> void TComm::ScatterObject<TMatrixTSparseRow_const<double>>(const TMatrixTSparseRow_const<double> *sendobjs, TMatrixTSparseRow_const<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow_const<float>
      template<> void TComm::ScatterObject<TMatrixTSparseRow_const<float>>(const TMatrixTSparseRow_const<float> *sendobjs, TMatrixTSparseRow_const<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSub<double>
      template<> void TComm::ScatterObject<TMatrixTSub<double>>(const TMatrixTSub<double> *sendobjs, TMatrixTSub<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSub<float>
      template<> void TComm::ScatterObject<TMatrixTSub<float>>(const TMatrixTSub<float> *sendobjs, TMatrixTSub<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSub_const<double>
      template<> void TComm::ScatterObject<TMatrixTSub_const<double>>(const TMatrixTSub_const<double> *sendobjs, TMatrixTSub_const<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSub_const<float>
      template<> void TComm::ScatterObject<TMatrixTSub_const<float>>(const TMatrixTSub_const<float> *sendobjs, TMatrixTSub_const<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSym<double>
      template<> void TComm::ScatterObject<TMatrixTSym<double>>(const TMatrixTSym<double> *sendobjs, TMatrixTSym<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSym<float>
      template<> void TComm::ScatterObject<TMatrixTSym<float>>(const TMatrixTSym<float> *sendobjs, TMatrixTSym<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSymLazy<double>
      template<> void TComm::ScatterObject<TMatrixTSymLazy<double>>(const TMatrixTSymLazy<double> *sendobjs, TMatrixTSymLazy<double> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TMatrixTSymLazy<float>
      template<> void TComm::ScatterObject<TMatrixTSymLazy<float>>(const TMatrixTSymLazy<float> *sendobjs, TMatrixTSymLazy<float> &obj, Int_t root);

//______________________________________________________________________________
//Support for class TString
      template<> void TComm::ScatterObject<TString>(const TString *sendobjs, TString &obj, Int_t root);

//______________________________________________________________________________
//Support for class TStringLong
      template<> void TComm::ScatterObject<TStringLong>(const TStringLong *sendobjs, TStringLong &obj, Int_t root);

   }
}
#endif
