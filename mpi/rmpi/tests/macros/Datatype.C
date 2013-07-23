#include<RMpi.h>

void Datatype()
{
  struct Position{
    Int_t x;
    Int_t y;
    Int_t z;
  };

  ROOT::Mpi::TEnvironment env(0, 0);
  ROOT::Mpi::TIntracomm world;
  ROOT::Mpi::TDatatype Posdt;
  Posdt = ROOT::Mpi::INT.Create_contiguous(3);
  Posdt.Commit();
  
  if ( world.Get_rank() == 0 ) 
  {
    Position s_point;
    s_point.x = 1;
    s_point.y = 2;
    s_point.z = 3;
    world.Send(&s_point,1,Posdt,1, 0);
    world.Recv(&s_point,1,Posdt,1, 1);
    if((s_point.x==4)&&(s_point.y==5)&&(s_point.z==6))
    {
      cout<<"PASSED"<<endl;
    }
    
  }else if(world.Get_rank() == 1)
  {
    Position r_point;
    world.Recv(&r_point,1,Posdt,0, 0);  
    if((r_point.x==1)&&(r_point.y==2)&&(r_point.z==3))
    {
      cout<<"PASSED"<<endl;
    }
    
    r_point.x = 4;
    r_point.y = 5;
    r_point.z = 6;    
    world.Send(&r_point,1,Posdt,0, 1);
  }
}
