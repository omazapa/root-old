/*******************************************************************************/
/*Author: Omar Andres Zapata Mesa  Ago 2012                                    */
/*this example calculate parallel wave animation                               */
/*work with any number(n) of processes but the wave is splitted into n-1 parts */
/*******************************************************************************/
#include <Rtypes.h>
#include <Math/Math.h>
#include <TF1.h>
#include <TPolyMarker3D.h>
Double_t delta=0.1;
Double_t min=0,max=6*M_PI;
Double_t angle=M_PI;

Double_t init,end;
Int_t counter=0;

UInt_t rep=1000;
UInt_t delay=100;

/********************/
/*Mpi initialization*/
/********************/
ROOT::Mpi::TEnvironment env(gApplication->Argc(), gApplication->Argv());
ROOT::Mpi::TIntracomm world;

TCanvas *canvas = NULL;
TView   *view   = NULL;


void Init()
{
 gStyle->SetCanvasPreferGL(true);
 gStyle->SetFrameFillColor(42);
 canvas = new TCanvas("canvas", "canvas", 300, 10, 700, 500);
 canvas->SetFillColor(14);
 view = TView::CreateView(1, 0, 0);
 view->RotateView(90,0);
}

void Animate()
{
     if (!gROOT->GetListOfCanvases()->FindObject("canvas")){
       world.Abort(ROOT::Mpi::SUCCESS);
    };
     gPad->Clear();
     for(int i=1;i<world.Get_size();i++)
      {
      //getting wave sections from ranks>1
      TPolyMarker3D *Section = new TPolyMarker3D();
      ROOT::Mpi::TMpiMessage msg;
      world.RecvObject(msg,i, 1);
      Section=(TPolyMarker3D *)msg.ReadObject(msg.GetClass());
      Section->Draw();
      }
      gPad->Modified();
      gPad->Update();
      angle += 0.05*M_PI;
}


void wave()
{   
   /**************************************************/
   /*rank zero(root) dont calculate wave, init viewer*/
   /*and recv wave sections from other processes     */
   /**************************************************/

   if (world.Get_rank() == 0) {
      Init();
      TTimer *timer = new TTimer(delay);
      timer->SetCommand("Animate()");
      Char_t timeStr[60];
      Char_t pointsStr[100];
      Char_t deltaStr[100];      
      timer->TurnOn();
  }else{
   Double_t step = fabs(min - max) / (world.Get_size()-1); 

   init = min + (world.Get_rank()-1) * step;
   end  = init + step;
   cout<<"rank="<<world.Get_rank()<<" init="<<init<<" end="<<end<<"\n";
   Int_t flag=true;
   while(flag){
     TPolyMarker3D *Section=new TPolyMarker3D();
     counter=0;
          for(Double_t t=init;t<end;t+=delta)
          {
                Section->SetPoint(counter,t,sin(t+angle),0);
                counter++;
	  }
      // set marker size, color & style
      Section->SetMarkerSize(1);
      Section->SetMarkerColor(world.Get_rank());
      Section->SetMarkerStyle(8);
      //send segment of points to root process
      ROOT::Mpi::TMpiMessage msg;
      msg.WriteObject(Section);
      world.SendObject(msg,0,1);
      angle += 0.05*M_PI;
      delete Section;
      }
       world.Abort(ROOT::Mpi::SUCCESS);
  }
}
