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
      template<> void TComm::SendObject<TArrayC>(const TArrayC &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayC>(TArrayC &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TArrayC>(const TArrayC *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayC>(TArrayC *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TArrayD
      template<> void TComm::SendObject<TArrayD>(const TArrayD &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayD>(TArrayD &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TArrayD>(const TArrayD *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayD>(TArrayD *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TArrayF
      template<> void TComm::SendObject<TArrayF>(const TArrayF &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayF>(TArrayF &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TArrayF>(const TArrayF *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayF>(TArrayF *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TArrayI
      template<> void TComm::SendObject<TArrayI>(const TArrayI &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayI>(TArrayI &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TArrayI>(const TArrayI *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayI>(TArrayI *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TArrayL
      template<> void TComm::SendObject<TArrayL>(const TArrayL &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayL>(TArrayL &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TArrayL>(const TArrayL *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayL>(TArrayL *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TArrayL64
      template<> void TComm::SendObject<TArrayL64>(const TArrayL64 &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayL64>(TArrayL64 &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TArrayL64>(const TArrayL64 *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayL64>(TArrayL64 *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TArrayS
      template<> void TComm::SendObject<TArrayS>(const TArrayS &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayS>(TArrayS &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TArrayS>(const TArrayS *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TArrayS>(TArrayS *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TVectorT<double>
      template<> void TComm::SendObject<TVectorT<double>>(const TVectorT<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TVectorT<double>>(TVectorT<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TVectorT<double>>(const TVectorT<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TVectorT<double>>(TVectorT<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TVectorT<float>
      template<> void TComm::SendObject<TVectorT<float>>(const TVectorT<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TVectorT<float>>(TVectorT<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TVectorT<float>>(const TVectorT<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TVectorT<float>>(TVectorT<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TComplex
      template<> void TComm::SendObject<TComplex>(const TComplex &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TComplex>(TComplex &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TComplex>(const TComplex *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TComplex>(TComplex *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TF12
      template<> void TComm::SendObject<TF12>(const TF12 &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TF12>(TF12 &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TF12>(const TF12 *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TF12>(TF12 *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TF2
      template<> void TComm::SendObject<TF2>(const TF2 &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TF2>(TF2 &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TF2>(const TF2 *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TF2>(TF2 *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TF3
      template<> void TComm::SendObject<TF3>(const TF3 &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TF3>(TF3 &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TF3>(const TF3 *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TF3>(TF3 *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TObject
      template<> void TComm::SendObject<TObject>(const TObject &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TObject>(TObject &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TObject>(const TObject *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TObject>(TObject *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THilbertMatrixT<double>
      template<> void TComm::SendObject<THilbertMatrixT<double>>(const THilbertMatrixT<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THilbertMatrixT<double>>(THilbertMatrixT<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THilbertMatrixT<double>>(const THilbertMatrixT<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THilbertMatrixT<double>>(THilbertMatrixT<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THilbertMatrixT<float>
      template<> void TComm::SendObject<THilbertMatrixT<float>>(const THilbertMatrixT<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THilbertMatrixT<float>>(THilbertMatrixT<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THilbertMatrixT<float>>(const THilbertMatrixT<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THilbertMatrixT<float>>(THilbertMatrixT<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THilbertMatrixTSym<double>
      template<> void TComm::SendObject<THilbertMatrixTSym<double>>(const THilbertMatrixTSym<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THilbertMatrixTSym<double>>(THilbertMatrixTSym<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THilbertMatrixTSym<double>>(const THilbertMatrixTSym<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THilbertMatrixTSym<double>>(THilbertMatrixTSym<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THilbertMatrixTSym<float>
      template<> void TComm::SendObject<THilbertMatrixTSym<float>>(const THilbertMatrixTSym<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THilbertMatrixTSym<float>>(THilbertMatrixTSym<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THilbertMatrixTSym<float>>(const THilbertMatrixTSym<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THilbertMatrixTSym<float>>(THilbertMatrixTSym<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THaarMatrixT<double>
      template<> void TComm::SendObject<THaarMatrixT<double>>(const THaarMatrixT<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THaarMatrixT<double>>(THaarMatrixT<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THaarMatrixT<double>>(const THaarMatrixT<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THaarMatrixT<double>>(THaarMatrixT<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THaarMatrixT<float>
      template<> void TComm::SendObject<THaarMatrixT<float>>(const THaarMatrixT<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THaarMatrixT<float>>(THaarMatrixT<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THaarMatrixT<float>>(const THaarMatrixT<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THaarMatrixT<float>>(THaarMatrixT<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayC>
      template<> void TComm::SendObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayC>>(THnSparseT<TArrayC> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayC>>(THnSparseT<TArrayC> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayS>
      template<> void TComm::SendObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayS>>(THnSparseT<TArrayS> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayS>>(THnSparseT<TArrayS> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayI>
      template<> void TComm::SendObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayI>>(THnSparseT<TArrayI> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayI>>(THnSparseT<TArrayI> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayL>
      template<> void TComm::SendObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayL>>(THnSparseT<TArrayL> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayL>>(THnSparseT<TArrayL> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayF>
      template<> void TComm::SendObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayF>>(THnSparseT<TArrayF> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayF>>(THnSparseT<TArrayF> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayD>
      template<> void TComm::SendObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayD>>(THnSparseT<TArrayD> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayD>>(THnSparseT<TArrayD> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMD5
      template<> void TComm::SendObject<TMD5>(const TMD5 &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMD5>(TMD5 &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMD5>(const TMD5 *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMD5>(TMD5 *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TLorentzVector
      template<> void TComm::SendObject<TLorentzVector>(const TLorentzVector &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TLorentzVector>(TLorentzVector &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TLorentzVector>(const TLorentzVector *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TLorentzVector>(TLorentzVector *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TQuaternion
      template<> void TComm::SendObject<TQuaternion>(const TQuaternion &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TQuaternion>(TQuaternion &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TQuaternion>(const TQuaternion *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TQuaternion>(TQuaternion *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TVector2
      template<> void TComm::SendObject<TVector2>(const TVector2 &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TVector2>(TVector2 &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TVector2>(const TVector2 *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TVector2>(TVector2 *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TVector3
      template<> void TComm::SendObject<TVector3>(const TVector3 &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TVector3>(TVector3 &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TVector3>(const TVector3 *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TVector3>(TVector3 *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompBK
      template<> void TComm::SendObject<TDecompBK>(const TDecompBK &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompBK>(TDecompBK &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TDecompBK>(const TDecompBK *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompBK>(TDecompBK *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompBase
      template<> void TComm::SendObject<TDecompBase>(const TDecompBase &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompBase>(TDecompBase &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TDecompBase>(const TDecompBase *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompBase>(TDecompBase *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompChol
      template<> void TComm::SendObject<TDecompChol>(const TDecompChol &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompChol>(TDecompChol &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TDecompChol>(const TDecompChol *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompChol>(TDecompChol *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompLU
      template<> void TComm::SendObject<TDecompLU>(const TDecompLU &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompLU>(TDecompLU &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TDecompLU>(const TDecompLU *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompLU>(TDecompLU *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompQRH
      template<> void TComm::SendObject<TDecompQRH>(const TDecompQRH &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompQRH>(TDecompQRH &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TDecompQRH>(const TDecompQRH *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompQRH>(TDecompQRH *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompSVD
      template<> void TComm::SendObject<TDecompSVD>(const TDecompSVD &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompSVD>(TDecompSVD &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TDecompSVD>(const TDecompSVD *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompSVD>(TDecompSVD *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompSparse
      template<> void TComm::SendObject<TDecompSparse>(const TDecompSparse &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompSparse>(TDecompSparse &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TDecompSparse>(const TDecompSparse *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TDecompSparse>(TDecompSparse *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseArrayChunk
      template<> void TComm::SendObject<THnSparseArrayChunk>(const THnSparseArrayChunk &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseArrayChunk>(THnSparseArrayChunk &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THnSparseArrayChunk>(const THnSparseArrayChunk *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseArrayChunk>(THnSparseArrayChunk *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayC>
      template<> void TComm::SendObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayC>>(THnSparseT<TArrayC> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayC>>(THnSparseT<TArrayC> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayD>
      template<> void TComm::SendObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayD>>(THnSparseT<TArrayD> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayD>>(THnSparseT<TArrayD> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayF>
      template<> void TComm::SendObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayF>>(THnSparseT<TArrayF> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayF>>(THnSparseT<TArrayF> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayI>
      template<> void TComm::SendObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayI>>(THnSparseT<TArrayI> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayI>>(THnSparseT<TArrayI> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayL>
      template<> void TComm::SendObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayL>>(THnSparseT<TArrayL> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayL>>(THnSparseT<TArrayL> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayS>
      template<> void TComm::SendObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayS>>(THnSparseT<TArrayS> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<THnSparseT<TArrayS>>(THnSparseT<TArrayS> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixDEigen
      template<> void TComm::SendObject<TMatrixDEigen>(const TMatrixDEigen &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixDEigen>(TMatrixDEigen &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixDEigen>(const TMatrixDEigen *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixDEigen>(TMatrixDEigen *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixDSymEigen
      template<> void TComm::SendObject<TMatrixDSymEigen>(const TMatrixDSymEigen &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixDSymEigen>(TMatrixDSymEigen &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixDSymEigen>(const TMatrixDSymEigen *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixDSymEigen>(TMatrixDSymEigen *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixT<double>
      template<> void TComm::SendObject<TMatrixT<double>>(const TMatrixT<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixT<double>>(TMatrixT<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixT<double>>(const TMatrixT<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixT<double>>(TMatrixT<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixT<float>
      template<> void TComm::SendObject<TMatrixT<float>>(const TMatrixT<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixT<float>>(TMatrixT<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixT<float>>(const TMatrixT<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixT<float>>(TMatrixT<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTColumn<double>
      template<> void TComm::SendObject<TMatrixTColumn<double>>(const TMatrixTColumn<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTColumn<double>>(TMatrixTColumn<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTColumn<double>>(const TMatrixTColumn<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTColumn<double>>(TMatrixTColumn<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTColumn<float>
      template<> void TComm::SendObject<TMatrixTColumn<float>>(const TMatrixTColumn<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTColumn<float>>(TMatrixTColumn<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTColumn<float>>(const TMatrixTColumn<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTColumn<float>>(TMatrixTColumn<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTColumn_const<double>
      template<> void TComm::SendObject<TMatrixTColumn_const<double>>(const TMatrixTColumn_const<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTColumn_const<double>>(TMatrixTColumn_const<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTColumn_const<double>>(const TMatrixTColumn_const<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTColumn_const<double>>(TMatrixTColumn_const<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTColumn_const<float>
      template<> void TComm::SendObject<TMatrixTColumn_const<float>>(const TMatrixTColumn_const<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTColumn_const<float>>(TMatrixTColumn_const<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTColumn_const<float>>(const TMatrixTColumn_const<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTColumn_const<float>>(TMatrixTColumn_const<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTDiag<double>
      template<> void TComm::SendObject<TMatrixTDiag<double>>(const TMatrixTDiag<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTDiag<double>>(TMatrixTDiag<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTDiag<double>>(const TMatrixTDiag<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTDiag<double>>(TMatrixTDiag<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTDiag<float>
      template<> void TComm::SendObject<TMatrixTDiag<float>>(const TMatrixTDiag<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTDiag<float>>(TMatrixTDiag<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTDiag<float>>(const TMatrixTDiag<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTDiag<float>>(TMatrixTDiag<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTDiag_const<double>
      template<> void TComm::SendObject<TMatrixTDiag_const<double>>(const TMatrixTDiag_const<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTDiag_const<double>>(TMatrixTDiag_const<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTDiag_const<double>>(const TMatrixTDiag_const<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTDiag_const<double>>(TMatrixTDiag_const<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTDiag_const<float>
      template<> void TComm::SendObject<TMatrixTDiag_const<float>>(const TMatrixTDiag_const<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTDiag_const<float>>(TMatrixTDiag_const<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTDiag_const<float>>(const TMatrixTDiag_const<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTDiag_const<float>>(TMatrixTDiag_const<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTFlat<double>
      template<> void TComm::SendObject<TMatrixTFlat<double>>(const TMatrixTFlat<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTFlat<double>>(TMatrixTFlat<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTFlat<double>>(const TMatrixTFlat<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTFlat<double>>(TMatrixTFlat<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTFlat<float>
      template<> void TComm::SendObject<TMatrixTFlat<float>>(const TMatrixTFlat<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTFlat<float>>(TMatrixTFlat<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTFlat<float>>(const TMatrixTFlat<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTFlat<float>>(TMatrixTFlat<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTFlat_const<double>
      template<> void TComm::SendObject<TMatrixTFlat_const<double>>(const TMatrixTFlat_const<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTFlat_const<double>>(TMatrixTFlat_const<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTFlat_const<double>>(const TMatrixTFlat_const<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTFlat_const<double>>(TMatrixTFlat_const<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTFlat_const<float>
      template<> void TComm::SendObject<TMatrixTFlat_const<float>>(const TMatrixTFlat_const<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTFlat_const<float>>(TMatrixTFlat_const<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTFlat_const<float>>(const TMatrixTFlat_const<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTFlat_const<float>>(TMatrixTFlat_const<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTLazy<double>
      template<> void TComm::SendObject<TMatrixTLazy<double>>(const TMatrixTLazy<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTLazy<double>>(TMatrixTLazy<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTLazy<double>>(const TMatrixTLazy<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTLazy<double>>(TMatrixTLazy<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTLazy<float>
      template<> void TComm::SendObject<TMatrixTLazy<float>>(const TMatrixTLazy<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTLazy<float>>(TMatrixTLazy<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTLazy<float>>(const TMatrixTLazy<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTLazy<float>>(TMatrixTLazy<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTRow<double>
      template<> void TComm::SendObject<TMatrixTRow<double>>(const TMatrixTRow<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTRow<double>>(TMatrixTRow<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTRow<double>>(const TMatrixTRow<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTRow<double>>(TMatrixTRow<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTRow<float>
      template<> void TComm::SendObject<TMatrixTRow<float>>(const TMatrixTRow<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTRow<float>>(TMatrixTRow<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTRow<float>>(const TMatrixTRow<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTRow<float>>(TMatrixTRow<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTRow_const<double>
      template<> void TComm::SendObject<TMatrixTRow_const<double>>(const TMatrixTRow_const<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTRow_const<double>>(TMatrixTRow_const<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTRow_const<double>>(const TMatrixTRow_const<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTRow_const<double>>(TMatrixTRow_const<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTRow_const<float>
      template<> void TComm::SendObject<TMatrixTRow_const<float>>(const TMatrixTRow_const<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTRow_const<float>>(TMatrixTRow_const<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTRow_const<float>>(const TMatrixTRow_const<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTRow_const<float>>(TMatrixTRow_const<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparse<double>
      template<> void TComm::SendObject<TMatrixTSparse<double>>(const TMatrixTSparse<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparse<double>>(TMatrixTSparse<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSparse<double>>(const TMatrixTSparse<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparse<double>>(TMatrixTSparse<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparse<float>
      template<> void TComm::SendObject<TMatrixTSparse<float>>(const TMatrixTSparse<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparse<float>>(TMatrixTSparse<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSparse<float>>(const TMatrixTSparse<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparse<float>>(TMatrixTSparse<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag<double>
      template<> void TComm::SendObject<TMatrixTSparseDiag<double>>(const TMatrixTSparseDiag<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseDiag<double>>(TMatrixTSparseDiag<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSparseDiag<double>>(const TMatrixTSparseDiag<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseDiag<double>>(TMatrixTSparseDiag<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag<float>
      template<> void TComm::SendObject<TMatrixTSparseDiag<float>>(const TMatrixTSparseDiag<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseDiag<float>>(TMatrixTSparseDiag<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSparseDiag<float>>(const TMatrixTSparseDiag<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseDiag<float>>(TMatrixTSparseDiag<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag_const<double>
      template<> void TComm::SendObject<TMatrixTSparseDiag_const<double>>(const TMatrixTSparseDiag_const<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseDiag_const<double>>(TMatrixTSparseDiag_const<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSparseDiag_const<double>>(const TMatrixTSparseDiag_const<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseDiag_const<double>>(TMatrixTSparseDiag_const<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag_const<float>
      template<> void TComm::SendObject<TMatrixTSparseDiag_const<float>>(const TMatrixTSparseDiag_const<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseDiag_const<float>>(TMatrixTSparseDiag_const<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSparseDiag_const<float>>(const TMatrixTSparseDiag_const<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseDiag_const<float>>(TMatrixTSparseDiag_const<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow<double>
      template<> void TComm::SendObject<TMatrixTSparseRow<double>>(const TMatrixTSparseRow<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseRow<double>>(TMatrixTSparseRow<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSparseRow<double>>(const TMatrixTSparseRow<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseRow<double>>(TMatrixTSparseRow<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow<float>
      template<> void TComm::SendObject<TMatrixTSparseRow<float>>(const TMatrixTSparseRow<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseRow<float>>(TMatrixTSparseRow<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSparseRow<float>>(const TMatrixTSparseRow<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseRow<float>>(TMatrixTSparseRow<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow_const<double>
      template<> void TComm::SendObject<TMatrixTSparseRow_const<double>>(const TMatrixTSparseRow_const<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseRow_const<double>>(TMatrixTSparseRow_const<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSparseRow_const<double>>(const TMatrixTSparseRow_const<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseRow_const<double>>(TMatrixTSparseRow_const<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow_const<float>
      template<> void TComm::SendObject<TMatrixTSparseRow_const<float>>(const TMatrixTSparseRow_const<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseRow_const<float>>(TMatrixTSparseRow_const<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSparseRow_const<float>>(const TMatrixTSparseRow_const<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSparseRow_const<float>>(TMatrixTSparseRow_const<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSub<double>
      template<> void TComm::SendObject<TMatrixTSub<double>>(const TMatrixTSub<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSub<double>>(TMatrixTSub<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSub<double>>(const TMatrixTSub<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSub<double>>(TMatrixTSub<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSub<float>
      template<> void TComm::SendObject<TMatrixTSub<float>>(const TMatrixTSub<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSub<float>>(TMatrixTSub<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSub<float>>(const TMatrixTSub<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSub<float>>(TMatrixTSub<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSub_const<double>
      template<> void TComm::SendObject<TMatrixTSub_const<double>>(const TMatrixTSub_const<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSub_const<double>>(TMatrixTSub_const<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSub_const<double>>(const TMatrixTSub_const<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSub_const<double>>(TMatrixTSub_const<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSub_const<float>
      template<> void TComm::SendObject<TMatrixTSub_const<float>>(const TMatrixTSub_const<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSub_const<float>>(TMatrixTSub_const<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSub_const<float>>(const TMatrixTSub_const<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSub_const<float>>(TMatrixTSub_const<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSym<double>
      template<> void TComm::SendObject<TMatrixTSym<double>>(const TMatrixTSym<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSym<double>>(TMatrixTSym<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSym<double>>(const TMatrixTSym<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSym<double>>(TMatrixTSym<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSym<float>
      template<> void TComm::SendObject<TMatrixTSym<float>>(const TMatrixTSym<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSym<float>>(TMatrixTSym<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSym<float>>(const TMatrixTSym<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSym<float>>(TMatrixTSym<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSymLazy<double>
      template<> void TComm::SendObject<TMatrixTSymLazy<double>>(const TMatrixTSymLazy<double> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSymLazy<double>>(TMatrixTSymLazy<double> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSymLazy<double>>(const TMatrixTSymLazy<double> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSymLazy<double>>(TMatrixTSymLazy<double> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSymLazy<float>
      template<> void TComm::SendObject<TMatrixTSymLazy<float>>(const TMatrixTSymLazy<float> &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSymLazy<float>>(TMatrixTSymLazy<float> &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TMatrixTSymLazy<float>>(const TMatrixTSymLazy<float> *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TMatrixTSymLazy<float>>(TMatrixTSymLazy<float> *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TString
      template<> void TComm::SendObject<TString>(const TString &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TString>(TString &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TString>(const TString *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TString>(TString *obj, Int_t count, Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TStringLong
      template<> void TComm::SendObject<TStringLong>(const TStringLong &obj, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TStringLong>(TStringLong &obj, Int_t source, Int_t tag);
      template<> void TComm::SendObject<TStringLong>(const TStringLong *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject<TStringLong>(TStringLong *obj, Int_t count, Int_t source, Int_t tag);

   }
}
#endif
