#include<RMpi.h>

void Datatype()
{
  struct Position{
    Int_t x;
    Int_t y;
    Int_t z;
  };

  ROOT::Mpi::TEnvironment env(gApplication->Argc(), gApplication->Argv());
  ROOT::Mpi::TIntracomm world;
  ROOT::Mpi::TDatatype PositionDatatype;
  PositionDatatype = ROOT::Mpi::INT.Create_contiguous(3);
  PositionDatatype.Commit( );
  
  if ( world.Rank() == 0 ) 
  {
    Position s_point;
    s_point.x = 1;
    s_point.y = 2;
    s_point.z = 3;
    world.SendDatatype (1, 0,&s_point,PositionDatatype );
    cout<<"Sending x="<<s_point.x<<" y="<<s_point.y<<" z="<<s_point.z<<" to rank 1\n";
    world.RecvDatatype(1, 0,&s_point, PositionDatatype);
    cout<<"Recving x="<<s_point.x<<" y="<<s_point.y<<" z="<<s_point.z<<" from rank 1\n";
  }else
  {
    Position r_point;
    world.RecvDatatype(0, 0,&r_point, PositionDatatype);  
    cout<<"Recving x="<<r_point.x<<" y="<<r_point.y<<" z="<<r_point.z<<" from rank 0\n";
    world.SendDatatype (0, 0,&r_point,PositionDatatype);
    
    r_point.x = 4;
    r_point.y = 5;
    r_point.z = 6;    
    cout<<"Sending x="<<r_point.x<<" y="<<r_point.y<<" z="<<r_point.z<<" to rank 0\n";
  }
   env.Finalize();
}
