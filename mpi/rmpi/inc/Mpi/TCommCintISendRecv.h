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
template<> void TComm::ISendObject<TArrayC>(const TArrayC &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TArrayC>(const TArrayC &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TArrayC>(const TArrayC &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TArrayC>(TArrayC &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TArrayD
template<> void TComm::ISendObject<TArrayD>(const TArrayD &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TArrayD>(const TArrayD &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TArrayD>(const TArrayD &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TArrayD>(TArrayD &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TArrayF
template<> void TComm::ISendObject<TArrayF>(const TArrayF &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TArrayF>(const TArrayF &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TArrayF>(const TArrayF &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TArrayF>(TArrayF &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TArrayI
template<> void TComm::ISendObject<TArrayI>(const TArrayI &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TArrayI>(const TArrayI &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TArrayI>(const TArrayI &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TArrayI>(TArrayI &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TArrayL
template<> void TComm::ISendObject<TArrayL>(const TArrayL &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TArrayL>(const TArrayL &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TArrayL>(const TArrayL &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TArrayL>(TArrayL &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TArrayL64
template<> void TComm::ISendObject<TArrayL64>(const TArrayL64 &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TArrayL64>(const TArrayL64 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TArrayL64>(const TArrayL64 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TArrayL64>(TArrayL64 &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TArrayS
template<> void TComm::ISendObject<TArrayS>(const TArrayS &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TArrayS>(const TArrayS &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TArrayS>(const TArrayS &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TArrayS>(TArrayS &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TVectorT<double>
template<> void TComm::ISendObject<TVectorT<double>>(const TVectorT<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TVectorT<double>>(const TVectorT<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TVectorT<double>>(const TVectorT<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TVectorT<double>>(TVectorT<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TVectorT<float>
template<> void TComm::ISendObject<TVectorT<float>>(const TVectorT<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TVectorT<float>>(const TVectorT<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TVectorT<float>>(const TVectorT<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TVectorT<float>>(TVectorT<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TComplex
template<> void TComm::ISendObject<TComplex>(const TComplex &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TComplex>(const TComplex &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TComplex>(const TComplex &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TComplex>(TComplex &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TF12
template<> void TComm::ISendObject<TF12>(const TF12 &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TF12>(const TF12 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TF12>(const TF12 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TF12>(TF12 &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TF2
template<> void TComm::ISendObject<TF2>(const TF2 &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TF2>(const TF2 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TF2>(const TF2 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TF2>(TF2 &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TF3
template<> void TComm::ISendObject<TF3>(const TF3 &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TF3>(const TF3 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TF3>(const TF3 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TF3>(TF3 &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TObject
template<> void TComm::ISendObject<TObject>(const TObject &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TObject>(const TObject &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TObject>(const TObject &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TObject>(TObject &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THilbertMatrixT<double>
template<> void TComm::ISendObject<THilbertMatrixT<double>>(const THilbertMatrixT<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THilbertMatrixT<double>>(const THilbertMatrixT<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THilbertMatrixT<double>>(const THilbertMatrixT<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THilbertMatrixT<double>>(THilbertMatrixT<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THilbertMatrixT<float>
template<> void TComm::ISendObject<THilbertMatrixT<float>>(const THilbertMatrixT<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THilbertMatrixT<float>>(const THilbertMatrixT<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THilbertMatrixT<float>>(const THilbertMatrixT<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THilbertMatrixT<float>>(THilbertMatrixT<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THilbertMatrixTSym<double>
template<> void TComm::ISendObject<THilbertMatrixTSym<double>>(const THilbertMatrixTSym<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THilbertMatrixTSym<double>>(const THilbertMatrixTSym<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THilbertMatrixTSym<double>>(const THilbertMatrixTSym<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THilbertMatrixTSym<double>>(THilbertMatrixTSym<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THilbertMatrixTSym<float>
template<> void TComm::ISendObject<THilbertMatrixTSym<float>>(const THilbertMatrixTSym<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THilbertMatrixTSym<float>>(const THilbertMatrixTSym<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THilbertMatrixTSym<float>>(const THilbertMatrixTSym<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THilbertMatrixTSym<float>>(THilbertMatrixTSym<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THaarMatrixT<double>
template<> void TComm::ISendObject<THaarMatrixT<double>>(const THaarMatrixT<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THaarMatrixT<double>>(const THaarMatrixT<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THaarMatrixT<double>>(const THaarMatrixT<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THaarMatrixT<double>>(THaarMatrixT<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THaarMatrixT<float>
template<> void TComm::ISendObject<THaarMatrixT<float>>(const THaarMatrixT<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THaarMatrixT<float>>(const THaarMatrixT<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THaarMatrixT<float>>(const THaarMatrixT<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THaarMatrixT<float>>(THaarMatrixT<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayC>
template<> void TComm::ISendObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THnSparseT<TArrayC>>(THnSparseT<TArrayC> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayS>
template<> void TComm::ISendObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THnSparseT<TArrayS>>(THnSparseT<TArrayS> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayI>
template<> void TComm::ISendObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THnSparseT<TArrayI>>(THnSparseT<TArrayI> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayL>
template<> void TComm::ISendObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THnSparseT<TArrayL>>(THnSparseT<TArrayL> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayF>
template<> void TComm::ISendObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THnSparseT<TArrayF>>(THnSparseT<TArrayF> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayD>
template<> void TComm::ISendObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THnSparseT<TArrayD>>(THnSparseT<TArrayD> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMD5
template<> void TComm::ISendObject<TMD5>(const TMD5 &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMD5>(const TMD5 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMD5>(const TMD5 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMD5>(TMD5 &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TLorentzVector
template<> void TComm::ISendObject<TLorentzVector>(const TLorentzVector &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TLorentzVector>(const TLorentzVector &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TLorentzVector>(const TLorentzVector &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TLorentzVector>(TLorentzVector &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TQuaternion
template<> void TComm::ISendObject<TQuaternion>(const TQuaternion &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TQuaternion>(const TQuaternion &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TQuaternion>(const TQuaternion &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TQuaternion>(TQuaternion &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TVector2
template<> void TComm::ISendObject<TVector2>(const TVector2 &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TVector2>(const TVector2 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TVector2>(const TVector2 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TVector2>(TVector2 &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TVector3
template<> void TComm::ISendObject<TVector3>(const TVector3 &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TVector3>(const TVector3 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TVector3>(const TVector3 &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TVector3>(TVector3 &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompBK
template<> void TComm::ISendObject<TDecompBK>(const TDecompBK &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TDecompBK>(const TDecompBK &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TDecompBK>(const TDecompBK &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TDecompBK>(TDecompBK &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompBase
template<> void TComm::ISendObject<TDecompBase>(const TDecompBase &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TDecompBase>(const TDecompBase &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TDecompBase>(const TDecompBase &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TDecompBase>(TDecompBase &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompChol
template<> void TComm::ISendObject<TDecompChol>(const TDecompChol &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TDecompChol>(const TDecompChol &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TDecompChol>(const TDecompChol &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TDecompChol>(TDecompChol &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompLU
template<> void TComm::ISendObject<TDecompLU>(const TDecompLU &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TDecompLU>(const TDecompLU &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TDecompLU>(const TDecompLU &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TDecompLU>(TDecompLU &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompQRH
template<> void TComm::ISendObject<TDecompQRH>(const TDecompQRH &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TDecompQRH>(const TDecompQRH &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TDecompQRH>(const TDecompQRH &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TDecompQRH>(TDecompQRH &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompSVD
template<> void TComm::ISendObject<TDecompSVD>(const TDecompSVD &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TDecompSVD>(const TDecompSVD &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TDecompSVD>(const TDecompSVD &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TDecompSVD>(TDecompSVD &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TDecompSparse
template<> void TComm::ISendObject<TDecompSparse>(const TDecompSparse &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TDecompSparse>(const TDecompSparse &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TDecompSparse>(const TDecompSparse &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TDecompSparse>(TDecompSparse &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseArrayChunk
template<> void TComm::ISendObject<THnSparseArrayChunk>(const THnSparseArrayChunk &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THnSparseArrayChunk>(const THnSparseArrayChunk &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THnSparseArrayChunk>(const THnSparseArrayChunk &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THnSparseArrayChunk>(THnSparseArrayChunk &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayC>
template<> void TComm::ISendObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THnSparseT<TArrayC>>(const THnSparseT<TArrayC> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THnSparseT<TArrayC>>(THnSparseT<TArrayC> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayD>
template<> void TComm::ISendObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THnSparseT<TArrayD>>(const THnSparseT<TArrayD> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THnSparseT<TArrayD>>(THnSparseT<TArrayD> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayF>
template<> void TComm::ISendObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THnSparseT<TArrayF>>(const THnSparseT<TArrayF> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THnSparseT<TArrayF>>(THnSparseT<TArrayF> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayI>
template<> void TComm::ISendObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THnSparseT<TArrayI>>(const THnSparseT<TArrayI> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THnSparseT<TArrayI>>(THnSparseT<TArrayI> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayL>
template<> void TComm::ISendObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THnSparseT<TArrayL>>(const THnSparseT<TArrayL> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THnSparseT<TArrayL>>(THnSparseT<TArrayL> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class THnSparseT<TArrayS>
template<> void TComm::ISendObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<THnSparseT<TArrayS>>(const THnSparseT<TArrayS> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<THnSparseT<TArrayS>>(THnSparseT<TArrayS> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixDEigen
template<> void TComm::ISendObject<TMatrixDEigen>(const TMatrixDEigen &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixDEigen>(const TMatrixDEigen &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixDEigen>(const TMatrixDEigen &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixDEigen>(TMatrixDEigen &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixDSymEigen
template<> void TComm::ISendObject<TMatrixDSymEigen>(const TMatrixDSymEigen &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixDSymEigen>(const TMatrixDSymEigen &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixDSymEigen>(const TMatrixDSymEigen &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixDSymEigen>(TMatrixDSymEigen &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixT<double>
template<> void TComm::ISendObject<TMatrixT<double>>(const TMatrixT<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixT<double>>(const TMatrixT<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixT<double>>(const TMatrixT<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixT<double>>(TMatrixT<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixT<float>
template<> void TComm::ISendObject<TMatrixT<float>>(const TMatrixT<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixT<float>>(const TMatrixT<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixT<float>>(const TMatrixT<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixT<float>>(TMatrixT<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTColumn<double>
template<> void TComm::ISendObject<TMatrixTColumn<double>>(const TMatrixTColumn<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTColumn<double>>(const TMatrixTColumn<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTColumn<double>>(const TMatrixTColumn<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTColumn<double>>(TMatrixTColumn<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTColumn<float>
template<> void TComm::ISendObject<TMatrixTColumn<float>>(const TMatrixTColumn<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTColumn<float>>(const TMatrixTColumn<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTColumn<float>>(const TMatrixTColumn<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTColumn<float>>(TMatrixTColumn<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTColumn_const<double>
template<> void TComm::ISendObject<TMatrixTColumn_const<double>>(const TMatrixTColumn_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTColumn_const<double>>(const TMatrixTColumn_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTColumn_const<double>>(const TMatrixTColumn_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTColumn_const<double>>(TMatrixTColumn_const<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTColumn_const<float>
template<> void TComm::ISendObject<TMatrixTColumn_const<float>>(const TMatrixTColumn_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTColumn_const<float>>(const TMatrixTColumn_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTColumn_const<float>>(const TMatrixTColumn_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTColumn_const<float>>(TMatrixTColumn_const<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTDiag<double>
template<> void TComm::ISendObject<TMatrixTDiag<double>>(const TMatrixTDiag<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTDiag<double>>(const TMatrixTDiag<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTDiag<double>>(const TMatrixTDiag<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTDiag<double>>(TMatrixTDiag<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTDiag<float>
template<> void TComm::ISendObject<TMatrixTDiag<float>>(const TMatrixTDiag<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTDiag<float>>(const TMatrixTDiag<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTDiag<float>>(const TMatrixTDiag<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTDiag<float>>(TMatrixTDiag<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTDiag_const<double>
template<> void TComm::ISendObject<TMatrixTDiag_const<double>>(const TMatrixTDiag_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTDiag_const<double>>(const TMatrixTDiag_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTDiag_const<double>>(const TMatrixTDiag_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTDiag_const<double>>(TMatrixTDiag_const<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTDiag_const<float>
template<> void TComm::ISendObject<TMatrixTDiag_const<float>>(const TMatrixTDiag_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTDiag_const<float>>(const TMatrixTDiag_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTDiag_const<float>>(const TMatrixTDiag_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTDiag_const<float>>(TMatrixTDiag_const<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTFlat<double>
template<> void TComm::ISendObject<TMatrixTFlat<double>>(const TMatrixTFlat<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTFlat<double>>(const TMatrixTFlat<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTFlat<double>>(const TMatrixTFlat<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTFlat<double>>(TMatrixTFlat<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTFlat<float>
template<> void TComm::ISendObject<TMatrixTFlat<float>>(const TMatrixTFlat<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTFlat<float>>(const TMatrixTFlat<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTFlat<float>>(const TMatrixTFlat<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTFlat<float>>(TMatrixTFlat<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTFlat_const<double>
template<> void TComm::ISendObject<TMatrixTFlat_const<double>>(const TMatrixTFlat_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTFlat_const<double>>(const TMatrixTFlat_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTFlat_const<double>>(const TMatrixTFlat_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTFlat_const<double>>(TMatrixTFlat_const<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTFlat_const<float>
template<> void TComm::ISendObject<TMatrixTFlat_const<float>>(const TMatrixTFlat_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTFlat_const<float>>(const TMatrixTFlat_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTFlat_const<float>>(const TMatrixTFlat_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTFlat_const<float>>(TMatrixTFlat_const<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTLazy<double>
template<> void TComm::ISendObject<TMatrixTLazy<double>>(const TMatrixTLazy<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTLazy<double>>(const TMatrixTLazy<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTLazy<double>>(const TMatrixTLazy<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTLazy<double>>(TMatrixTLazy<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTLazy<float>
template<> void TComm::ISendObject<TMatrixTLazy<float>>(const TMatrixTLazy<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTLazy<float>>(const TMatrixTLazy<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTLazy<float>>(const TMatrixTLazy<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTLazy<float>>(TMatrixTLazy<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTRow<double>
template<> void TComm::ISendObject<TMatrixTRow<double>>(const TMatrixTRow<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTRow<double>>(const TMatrixTRow<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTRow<double>>(const TMatrixTRow<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTRow<double>>(TMatrixTRow<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTRow<float>
template<> void TComm::ISendObject<TMatrixTRow<float>>(const TMatrixTRow<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTRow<float>>(const TMatrixTRow<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTRow<float>>(const TMatrixTRow<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTRow<float>>(TMatrixTRow<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTRow_const<double>
template<> void TComm::ISendObject<TMatrixTRow_const<double>>(const TMatrixTRow_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTRow_const<double>>(const TMatrixTRow_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTRow_const<double>>(const TMatrixTRow_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTRow_const<double>>(TMatrixTRow_const<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTRow_const<float>
template<> void TComm::ISendObject<TMatrixTRow_const<float>>(const TMatrixTRow_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTRow_const<float>>(const TMatrixTRow_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTRow_const<float>>(const TMatrixTRow_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTRow_const<float>>(TMatrixTRow_const<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparse<double>
template<> void TComm::ISendObject<TMatrixTSparse<double>>(const TMatrixTSparse<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSparse<double>>(const TMatrixTSparse<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSparse<double>>(const TMatrixTSparse<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSparse<double>>(TMatrixTSparse<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparse<float>
template<> void TComm::ISendObject<TMatrixTSparse<float>>(const TMatrixTSparse<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSparse<float>>(const TMatrixTSparse<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSparse<float>>(const TMatrixTSparse<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSparse<float>>(TMatrixTSparse<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag<double>
template<> void TComm::ISendObject<TMatrixTSparseDiag<double>>(const TMatrixTSparseDiag<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSparseDiag<double>>(const TMatrixTSparseDiag<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSparseDiag<double>>(const TMatrixTSparseDiag<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSparseDiag<double>>(TMatrixTSparseDiag<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag<float>
template<> void TComm::ISendObject<TMatrixTSparseDiag<float>>(const TMatrixTSparseDiag<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSparseDiag<float>>(const TMatrixTSparseDiag<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSparseDiag<float>>(const TMatrixTSparseDiag<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSparseDiag<float>>(TMatrixTSparseDiag<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag_const<double>
template<> void TComm::ISendObject<TMatrixTSparseDiag_const<double>>(const TMatrixTSparseDiag_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSparseDiag_const<double>>(const TMatrixTSparseDiag_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSparseDiag_const<double>>(const TMatrixTSparseDiag_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSparseDiag_const<double>>(TMatrixTSparseDiag_const<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseDiag_const<float>
template<> void TComm::ISendObject<TMatrixTSparseDiag_const<float>>(const TMatrixTSparseDiag_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSparseDiag_const<float>>(const TMatrixTSparseDiag_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSparseDiag_const<float>>(const TMatrixTSparseDiag_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSparseDiag_const<float>>(TMatrixTSparseDiag_const<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow<double>
template<> void TComm::ISendObject<TMatrixTSparseRow<double>>(const TMatrixTSparseRow<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSparseRow<double>>(const TMatrixTSparseRow<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSparseRow<double>>(const TMatrixTSparseRow<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSparseRow<double>>(TMatrixTSparseRow<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow<float>
template<> void TComm::ISendObject<TMatrixTSparseRow<float>>(const TMatrixTSparseRow<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSparseRow<float>>(const TMatrixTSparseRow<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSparseRow<float>>(const TMatrixTSparseRow<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSparseRow<float>>(TMatrixTSparseRow<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow_const<double>
template<> void TComm::ISendObject<TMatrixTSparseRow_const<double>>(const TMatrixTSparseRow_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSparseRow_const<double>>(const TMatrixTSparseRow_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSparseRow_const<double>>(const TMatrixTSparseRow_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSparseRow_const<double>>(TMatrixTSparseRow_const<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSparseRow_const<float>
template<> void TComm::ISendObject<TMatrixTSparseRow_const<float>>(const TMatrixTSparseRow_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSparseRow_const<float>>(const TMatrixTSparseRow_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSparseRow_const<float>>(const TMatrixTSparseRow_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSparseRow_const<float>>(TMatrixTSparseRow_const<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSub<double>
template<> void TComm::ISendObject<TMatrixTSub<double>>(const TMatrixTSub<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSub<double>>(const TMatrixTSub<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSub<double>>(const TMatrixTSub<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSub<double>>(TMatrixTSub<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSub<float>
template<> void TComm::ISendObject<TMatrixTSub<float>>(const TMatrixTSub<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSub<float>>(const TMatrixTSub<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSub<float>>(const TMatrixTSub<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSub<float>>(TMatrixTSub<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSub_const<double>
template<> void TComm::ISendObject<TMatrixTSub_const<double>>(const TMatrixTSub_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSub_const<double>>(const TMatrixTSub_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSub_const<double>>(const TMatrixTSub_const<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSub_const<double>>(TMatrixTSub_const<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSub_const<float>
template<> void TComm::ISendObject<TMatrixTSub_const<float>>(const TMatrixTSub_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSub_const<float>>(const TMatrixTSub_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSub_const<float>>(const TMatrixTSub_const<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSub_const<float>>(TMatrixTSub_const<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSym<double>
template<> void TComm::ISendObject<TMatrixTSym<double>>(const TMatrixTSym<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSym<double>>(const TMatrixTSym<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSym<double>>(const TMatrixTSym<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSym<double>>(TMatrixTSym<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSym<float>
template<> void TComm::ISendObject<TMatrixTSym<float>>(const TMatrixTSym<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSym<float>>(const TMatrixTSym<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSym<float>>(const TMatrixTSym<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSym<float>>(TMatrixTSym<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSymLazy<double>
template<> void TComm::ISendObject<TMatrixTSymLazy<double>>(const TMatrixTSymLazy<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSymLazy<double>>(const TMatrixTSymLazy<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSymLazy<double>>(const TMatrixTSymLazy<double> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSymLazy<double>>(TMatrixTSymLazy<double> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TMatrixTSymLazy<float>
template<> void TComm::ISendObject<TMatrixTSymLazy<float>>(const TMatrixTSymLazy<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TMatrixTSymLazy<float>>(const TMatrixTSymLazy<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TMatrixTSymLazy<float>>(const TMatrixTSymLazy<float> &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TMatrixTSymLazy<float>>(TMatrixTSymLazy<float> &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TString
template<> void TComm::ISendObject<TString>(const TString &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TString>(const TString &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TString>(const TString &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TString>(TString &obj,Int_t source, Int_t tag);

//______________________________________________________________________________
//Support for class TStringLong
template<> void TComm::ISendObject<TStringLong>(const TStringLong &obj,Int_t dest, Int_t tag);
template<> void TComm::ISsendObject<TStringLong>(const TStringLong &obj,Int_t dest, Int_t tag);
template<> void TComm::IRsendObject<TStringLong>(const TStringLong &obj,Int_t dest, Int_t tag);
template<> void TComm::IRecvObject<TStringLong>(TStringLong &obj,Int_t source, Int_t tag);

}
}
#endif
