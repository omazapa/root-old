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
      template<> void TComm::AllGatherObject<TArrayC>(const TArrayC &sendobj, TArrayC *recvobjs);

//______________________________________________________________________________
//Support for class TArrayD
      template<> void TComm::AllGatherObject<TArrayD>(const TArrayD &sendobj, TArrayD *recvobjs);

//______________________________________________________________________________
//Support for class TArrayF
      template<> void TComm::AllGatherObject<TArrayF>(const TArrayF &sendobj, TArrayF *recvobjs);

//______________________________________________________________________________
//Support for class TArrayI
      template<> void TComm::AllGatherObject<TArrayI>(const TArrayI &sendobj, TArrayI *recvobjs);

//______________________________________________________________________________
//Support for class TArrayL
      template<> void TComm::AllGatherObject<TArrayL>(const TArrayL &sendobj, TArrayL *recvobjs);

//______________________________________________________________________________
//Support for class TArrayL64
      template<> void TComm::AllGatherObject<TArrayL64>(const TArrayL64 &sendobj, TArrayL64 *recvobjs);

//______________________________________________________________________________
//Support for class TArrayS
      template<> void TComm::AllGatherObject<TArrayS>(const TArrayS &sendobj, TArrayS *recvobjs);

//______________________________________________________________________________
//Support for class TVectorT<double>
      template<> void TComm::AllGatherObject<TVectorT<double>>(const TVectorT<double> &sendobj, TVectorT<double> *recvobjs);

//______________________________________________________________________________
//Support for class TVectorT<float>
      template<> void TComm::AllGatherObject<TVectorT<float>>(const TVectorT<float> &sendobj, TVectorT<float> *recvobjs);

//______________________________________________________________________________
//Support for class TComplex
      template<> void TComm::AllGatherObject<TComplex>(const TComplex &sendobj, TComplex *recvobjs);

//______________________________________________________________________________
//Support for class TF12
      template<> void TComm::AllGatherObject<TF12>(const TF12 &sendobj, TF12 *recvobjs);

//______________________________________________________________________________
//Support for class TF2
      template<> void TComm::AllGatherObject<TF2>(const TF2 &sendobj, TF2 *recvobjs);

//______________________________________________________________________________
//Support for class TF3
      template<> void TComm::AllGatherObject<TF3>(const TF3 &sendobj, TF3 *recvobjs);

//______________________________________________________________________________
//Support for class TObject
      template<> void TComm::AllGatherObject<TObject>(const TObject &sendobj, TObject *recvobjs);

//______________________________________________________________________________
//Support for class THilbertMatrixT<double>
      template<> void TComm::AllGatherObject<THilbertMatrixT<double>>(const THilbertMatrixT<double> &sendobj, THilbertMatrixT<double> *recvobjs);

//______________________________________________________________________________
//Support for class THilbertMatrixT<float>
      template<> void TComm::AllGatherObject<THilbertMatrixT<float>>(const THilbertMatrixT<float> &sendobj, THilbertMatrixT<float> *recvobjs);

//______________________________________________________________________________
//Support for class THilbertMatrixTSym<double>
      template<> void TComm::AllGatherObject<THilbertMatrixTSym<double>>(const THilbertMatrixTSym<double> &sendobj, THilbertMatrixTSym<double> *recvobjs);

//______________________________________________________________________________
//Support for class THilbertMatrixTSym<float>
      template<> void TComm::AllGatherObject<THilbertMatrixTSym<float>>(const THilbertMatrixTSym<float> &sendobj, THilbertMatrixTSym<float> *recvobjs);

//______________________________________________________________________________
//Support for class THaarMatrixT<double>
      template<> void TComm::AllGatherObject<THaarMatrixT<double>>(const THaarMatrixT<double> &sendobj, THaarMatrixT<double> *recvobjs);

//______________________________________________________________________________
//Support for class THaarMatrixT<float>
      template<> void TComm::AllGatherObject<THaarMatrixT<float>>(const THaarMatrixT<float> &sendobj, THaarMatrixT<float> *recvobjs);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayC>
      template<> void TComm::AllGatherObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> &sendobj, THnSparseT<TArrayC> *recvobjs);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayS>
      template<> void TComm::AllGatherObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> &sendobj, THnSparseT<TArrayS> *recvobjs);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayI>
      template<> void TComm::AllGatherObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> &sendobj, THnSparseT<TArrayI> *recvobjs);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayL>
      template<> void TComm::AllGatherObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> &sendobj, THnSparseT<TArrayL> *recvobjs);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayF>
      template<> void TComm::AllGatherObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> &sendobj, THnSparseT<TArrayF> *recvobjs);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayD>
      template<> void TComm::AllGatherObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> &sendobj, THnSparseT<TArrayD> *recvobjs);

//______________________________________________________________________________
//Support for class TMD5
      template<> void TComm::AllGatherObject<TMD5>(const TMD5 &sendobj, TMD5 *recvobjs);

//______________________________________________________________________________
//Support for class TLorentzVector
      template<> void TComm::AllGatherObject<TLorentzVector>(const TLorentzVector &sendobj, TLorentzVector *recvobjs);

//______________________________________________________________________________
//Support for class TQuaternion
      template<> void TComm::AllGatherObject<TQuaternion>(const TQuaternion &sendobj, TQuaternion *recvobjs);

//______________________________________________________________________________
//Support for class TVector2
      template<> void TComm::AllGatherObject<TVector2>(const TVector2 &sendobj, TVector2 *recvobjs);

//______________________________________________________________________________
//Support for class TVector3
      template<> void TComm::AllGatherObject<TVector3>(const TVector3 &sendobj, TVector3 *recvobjs);

//______________________________________________________________________________
//Support for class TDecompBK
      template<> void TComm::AllGatherObject<TDecompBK>(const TDecompBK &sendobj, TDecompBK *recvobjs);

//______________________________________________________________________________
//Support for class TDecompBase
      template<> void TComm::AllGatherObject<TDecompBase>(const TDecompBase &sendobj, TDecompBase *recvobjs);

//______________________________________________________________________________
//Support for class TDecompChol
      template<> void TComm::AllGatherObject<TDecompChol>(const TDecompChol &sendobj, TDecompChol *recvobjs);

//______________________________________________________________________________
//Support for class TDecompLU
      template<> void TComm::AllGatherObject<TDecompLU>(const TDecompLU &sendobj, TDecompLU *recvobjs);

//______________________________________________________________________________
//Support for class TDecompQRH
      template<> void TComm::AllGatherObject<TDecompQRH>(const TDecompQRH &sendobj, TDecompQRH *recvobjs);

//______________________________________________________________________________
//Support for class TDecompSVD
      template<> void TComm::AllGatherObject<TDecompSVD>(const TDecompSVD &sendobj, TDecompSVD *recvobjs);

//______________________________________________________________________________
//Support for class TDecompSparse
      template<> void TComm::AllGatherObject<TDecompSparse>(const TDecompSparse &sendobj, TDecompSparse *recvobjs);

//______________________________________________________________________________
//Support for class THnSparseArrayChunk
      template<> void TComm::AllGatherObject<THnSparseArrayChunk>(const THnSparseArrayChunk &sendobj, THnSparseArrayChunk *recvobjs);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayC>
      template<> void TComm::AllGatherObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> &sendobj, THnSparseT<TArrayC> *recvobjs);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayD>
      template<> void TComm::AllGatherObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> &sendobj, THnSparseT<TArrayD> *recvobjs);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayF>
      template<> void TComm::AllGatherObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> &sendobj, THnSparseT<TArrayF> *recvobjs);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayI>
      template<> void TComm::AllGatherObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> &sendobj, THnSparseT<TArrayI> *recvobjs);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayL>
      template<> void TComm::AllGatherObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> &sendobj, THnSparseT<TArrayL> *recvobjs);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayS>
      template<> void TComm::AllGatherObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> &sendobj, THnSparseT<TArrayS> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixDEigen
      template<> void TComm::AllGatherObject<TMatrixDEigen>(const TMatrixDEigen &sendobj, TMatrixDEigen *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixDSymEigen
      template<> void TComm::AllGatherObject<TMatrixDSymEigen>(const TMatrixDSymEigen &sendobj, TMatrixDSymEigen *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixT<double>
      template<> void TComm::AllGatherObject<TMatrixT<double>>(const TMatrixT<double> &sendobj, TMatrixT<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixT<float>
      template<> void TComm::AllGatherObject<TMatrixT<float>>(const TMatrixT<float> &sendobj, TMatrixT<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTColumn<double>
      template<> void TComm::AllGatherObject<TMatrixTColumn<double>>(const TMatrixTColumn<double> &sendobj, TMatrixTColumn<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTColumn<float>
      template<> void TComm::AllGatherObject<TMatrixTColumn<float>>(const TMatrixTColumn<float> &sendobj, TMatrixTColumn<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTColumn_const<double>
      template<> void TComm::AllGatherObject<TMatrixTColumn_const<double>>(const TMatrixTColumn_const<double> &sendobj, TMatrixTColumn_const<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTColumn_const<float>
      template<> void TComm::AllGatherObject<TMatrixTColumn_const<float>>(const TMatrixTColumn_const<float> &sendobj, TMatrixTColumn_const<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTDiag<double>
      template<> void TComm::AllGatherObject<TMatrixTDiag<double>>(const TMatrixTDiag<double> &sendobj, TMatrixTDiag<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTDiag<float>
      template<> void TComm::AllGatherObject<TMatrixTDiag<float>>(const TMatrixTDiag<float> &sendobj, TMatrixTDiag<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTDiag_const<double>
      template<> void TComm::AllGatherObject<TMatrixTDiag_const<double>>(const TMatrixTDiag_const<double> &sendobj, TMatrixTDiag_const<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTDiag_const<float>
      template<> void TComm::AllGatherObject<TMatrixTDiag_const<float>>(const TMatrixTDiag_const<float> &sendobj, TMatrixTDiag_const<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTFlat<double>
      template<> void TComm::AllGatherObject<TMatrixTFlat<double>>(const TMatrixTFlat<double> &sendobj, TMatrixTFlat<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTFlat<float>
      template<> void TComm::AllGatherObject<TMatrixTFlat<float>>(const TMatrixTFlat<float> &sendobj, TMatrixTFlat<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTFlat_const<double>
      template<> void TComm::AllGatherObject<TMatrixTFlat_const<double>>(const TMatrixTFlat_const<double> &sendobj, TMatrixTFlat_const<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTFlat_const<float>
      template<> void TComm::AllGatherObject<TMatrixTFlat_const<float>>(const TMatrixTFlat_const<float> &sendobj, TMatrixTFlat_const<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTLazy<double>
      template<> void TComm::AllGatherObject<TMatrixTLazy<double>>(const TMatrixTLazy<double> &sendobj, TMatrixTLazy<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTLazy<float>
      template<> void TComm::AllGatherObject<TMatrixTLazy<float>>(const TMatrixTLazy<float> &sendobj, TMatrixTLazy<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTRow<double>
      template<> void TComm::AllGatherObject<TMatrixTRow<double>>(const TMatrixTRow<double> &sendobj, TMatrixTRow<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTRow<float>
      template<> void TComm::AllGatherObject<TMatrixTRow<float>>(const TMatrixTRow<float> &sendobj, TMatrixTRow<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTRow_const<double>
      template<> void TComm::AllGatherObject<TMatrixTRow_const<double>>(const TMatrixTRow_const<double> &sendobj, TMatrixTRow_const<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTRow_const<float>
      template<> void TComm::AllGatherObject<TMatrixTRow_const<float>>(const TMatrixTRow_const<float> &sendobj, TMatrixTRow_const<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSparse<double>
      template<> void TComm::AllGatherObject<TMatrixTSparse<double>>(const TMatrixTSparse<double> &sendobj, TMatrixTSparse<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSparse<float>
      template<> void TComm::AllGatherObject<TMatrixTSparse<float>>(const TMatrixTSparse<float> &sendobj, TMatrixTSparse<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag<double>
      template<> void TComm::AllGatherObject<TMatrixTSparseDiag<double>>(const TMatrixTSparseDiag<double> &sendobj, TMatrixTSparseDiag<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag<float>
      template<> void TComm::AllGatherObject<TMatrixTSparseDiag<float>>(const TMatrixTSparseDiag<float> &sendobj, TMatrixTSparseDiag<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag_const<double>
      template<> void TComm::AllGatherObject<TMatrixTSparseDiag_const<double>>(const TMatrixTSparseDiag_const<double> &sendobj, TMatrixTSparseDiag_const<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag_const<float>
      template<> void TComm::AllGatherObject<TMatrixTSparseDiag_const<float>>(const TMatrixTSparseDiag_const<float> &sendobj, TMatrixTSparseDiag_const<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow<double>
      template<> void TComm::AllGatherObject<TMatrixTSparseRow<double>>(const TMatrixTSparseRow<double> &sendobj, TMatrixTSparseRow<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow<float>
      template<> void TComm::AllGatherObject<TMatrixTSparseRow<float>>(const TMatrixTSparseRow<float> &sendobj, TMatrixTSparseRow<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow_const<double>
      template<> void TComm::AllGatherObject<TMatrixTSparseRow_const<double>>(const TMatrixTSparseRow_const<double> &sendobj, TMatrixTSparseRow_const<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow_const<float>
      template<> void TComm::AllGatherObject<TMatrixTSparseRow_const<float>>(const TMatrixTSparseRow_const<float> &sendobj, TMatrixTSparseRow_const<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSub<double>
      template<> void TComm::AllGatherObject<TMatrixTSub<double>>(const TMatrixTSub<double> &sendobj, TMatrixTSub<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSub<float>
      template<> void TComm::AllGatherObject<TMatrixTSub<float>>(const TMatrixTSub<float> &sendobj, TMatrixTSub<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSub_const<double>
      template<> void TComm::AllGatherObject<TMatrixTSub_const<double>>(const TMatrixTSub_const<double> &sendobj, TMatrixTSub_const<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSub_const<float>
      template<> void TComm::AllGatherObject<TMatrixTSub_const<float>>(const TMatrixTSub_const<float> &sendobj, TMatrixTSub_const<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSym<double>
      template<> void TComm::AllGatherObject<TMatrixTSym<double>>(const TMatrixTSym<double> &sendobj, TMatrixTSym<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSym<float>
      template<> void TComm::AllGatherObject<TMatrixTSym<float>>(const TMatrixTSym<float> &sendobj, TMatrixTSym<float> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSymLazy<double>
      template<> void TComm::AllGatherObject<TMatrixTSymLazy<double>>(const TMatrixTSymLazy<double> &sendobj, TMatrixTSymLazy<double> *recvobjs);

//______________________________________________________________________________
//Support for class TMatrixTSymLazy<float>
      template<> void TComm::AllGatherObject<TMatrixTSymLazy<float>>(const TMatrixTSymLazy<float> &sendobj, TMatrixTSymLazy<float> *recvobjs);

//______________________________________________________________________________
//Support for class TString
      template<> void TComm::AllGatherObject<TString>(const TString &sendobj, TString *recvobjs);

//______________________________________________________________________________
//Support for class TStringLong
      template<> void TComm::AllGatherObject<TStringLong>(const TStringLong &sendobj, TStringLong *recvobjs);

   }
}
#endif
