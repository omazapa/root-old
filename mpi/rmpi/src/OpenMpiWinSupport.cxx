
//this methods are defined in openmpi like extern in the definitions and it is not linked in vc2010
#ifdef _WIN32
#include<mpi.h>
MPI::Comm::Comm()
{
}

MPI::Comm::Comm(const Comm_Null& data) : Comm_Null(data)
{
}

void MPI::Datatype::Free()
{
   (void)MPI_Type_free(&mpi_datatype);
}

void ompi_mpi_cxx_op_intercept(void *invec, void *outvec, int *len, MPI_Datatype *datatype, MPI_User_function *c_fn)
{
   MPI::Datatype cxx_datatype = *datatype;
   MPI::User_function *cxx_callback = (MPI::User_function*) c_fn;
   cxx_callback(invec, outvec, *len, cxx_datatype);
}

#endif
