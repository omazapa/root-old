/*************************************************************************
 * Copyright (C) 2012,  Gfif Developers                                   *
 * Grupo de Fenomenologia de Interacciones Fundamentales                  *
 * http://gfif.udea.edu.co                                                *
 * División de ciencias de la computación Gfifdev                         *
 * http://gfifdev.udea.edu.co                                             *
 * Class Created and Maintained By Omar Andres Zapata Mesa                *
 * All rights reserved.                                                   *
 *                                                                        *
 *                                                                        *
 * For the list of contributors see $ROOTSYS/README/CREDITS.              *
 *************************************************************************/


#ifndef ROOT_MTypes
#define ROOT_MTypes


#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif

/******************************************
 * Defines for messages color on terminal *
 *****************************************/
#ifdef _WIN32

#define MSG_RED(_MSG)  TString(""+TString(_MSG)+"")

#define MSG_GREEN(_MSG)  TString(""+TString(_MSG)+"")

#define MSG_YELLOW(_MSG)  TString(""+TString(_MSG)+"")

#define MSG_BLUE(_MSG)  TString(""+TString(_MSG)+"")

#define MSG_PURPLE(_MSG)  TString(""+TString(_MSG)+"")

#define MSG_CYAN(_MSG)  TString(""+TString(_MSG)+"")

#else
#define MSG_RED(_MSG)  TString("\033[01;31m"+TString(_MSG)+"\033[00m")

#define MSG_GREEN(_MSG)  TString("\033[01;32m"+TString(_MSG)+"\033[00m")

#define MSG_YELLOW(_MSG)  TString("\033[01;33m"+TString(_MSG)+"\033[00m")

#define MSG_BLUE(_MSG)  TString("\033[01;34m"+TString(_MSG)+"\033[00m")

#define MSG_PURPLE(_MSG)  TString("\033[01;35m"+TString(_MSG)+"\033[00m")

#define MSG_CYAN(_MSG)  TString("\033[01;36m"+TString(_MSG)+"\033[00m")
#endif

#ifndef __CINT__
#define __METHOD_INT__  TString(__FUNCTION__)+" Int_t"

#define __METHOD_FLOAT__  TString(__FUNCTION__)+" Float_t"

#define __METHOD_DOUBLE__  TString(__FUNCTION__)+" Double_t"

#define __METHOD_LONG__  TString(__FUNCTION__)+" Long_t"

#define __METHOD_CHAR__  TString(__FUNCTION__)+" Char_t"
#endif


namespace ROOT {
   namespace Mpi {
      enum EComparationType {Iqual, Greater, Less, GreaterIqual, LessIqual};
   }
}


#ifdef __CINT__
struct MPI_Aint;
struct MPI_Fint;
#else
#include<mpi.h>
#endif

namespace ROOT {
   namespace Mpi {
      typedef MPI_Aint Aint;
      typedef MPI_Fint Fint;
      typedef long long Offset;
   }
}

namespace ROOT {
   namespace Mpi {
      // return  codes
      R__EXTERN const Int_t SUCCESS;
      R__EXTERN const Int_t ERR_BUFFER;
      R__EXTERN const Int_t ERR_COUNT;
      R__EXTERN const Int_t ERR_TYPE;
      R__EXTERN const Int_t ERR_TAG;
      R__EXTERN const Int_t ERR_COMM;
      R__EXTERN const Int_t ERR_RANK;
      R__EXTERN const Int_t ERR_REQUEST;
      R__EXTERN const Int_t ERR_ROOT;
      R__EXTERN const Int_t ERR_GROUP;
      R__EXTERN const Int_t ERR_OP;
      R__EXTERN const Int_t ERR_TOPOLOGY;
      R__EXTERN const Int_t ERR_DIMS;
      R__EXTERN const Int_t ERR_ARG;
      R__EXTERN const Int_t ERR_UNKNOWN;
      R__EXTERN const Int_t ERR_TRUNCATE;
      R__EXTERN const Int_t ERR_OTHER;
      R__EXTERN const Int_t ERR_INTERN;
      R__EXTERN const Int_t ERR_IN_STATUS;
      R__EXTERN const Int_t ERR_PENDING;
      R__EXTERN const Int_t ERR_ACCESS;
      R__EXTERN const Int_t ERR_AMODE;
      R__EXTERN const Int_t ERR_ASSERT;
      R__EXTERN const Int_t ERR_BAD_FILE;
      R__EXTERN const Int_t ERR_BASE;
      R__EXTERN const Int_t ERR_CONVERSION;
      R__EXTERN const Int_t ERR_DISP;
      R__EXTERN const Int_t ERR_DUP_DATAREP;
      R__EXTERN const Int_t ERR_FILE_EXISTS;
      R__EXTERN const Int_t ERR_FILE_IN_USE;
      R__EXTERN const Int_t ERR_FILE;
      R__EXTERN const Int_t ERR_INFO_KEY;
      R__EXTERN const Int_t ERR_INFO_NOKEY;
      R__EXTERN const Int_t ERR_INFO_VALUE;
      R__EXTERN const Int_t ERR_INFO;
      R__EXTERN const Int_t ERR_IO;
      R__EXTERN const Int_t ERR_KEYVAL;
      R__EXTERN const Int_t ERR_LOCKTYPE;
      R__EXTERN const Int_t ERR_NAME;
      R__EXTERN const Int_t ERR_NO_MEM;
      R__EXTERN const Int_t ERR_NOT_SAME;
      R__EXTERN const Int_t ERR_NO_SPACE;
      R__EXTERN const Int_t ERR_NO_SUCH_FILE;
      R__EXTERN const Int_t ERR_PORT;
      R__EXTERN const Int_t ERR_QUOTA;
      R__EXTERN const Int_t ERR_READ_ONLY;
      R__EXTERN const Int_t ERR_RMA_CONFLICT;
      R__EXTERN const Int_t ERR_RMA_SYNC;
      R__EXTERN const Int_t ERR_SERVICE;
      R__EXTERN const Int_t ERR_SIZE;
      R__EXTERN const Int_t ERR_SPAWN;
      R__EXTERN const Int_t ERR_UNSUPPORTED_DATAREP;
      R__EXTERN const Int_t ERR_UNSUPPORTED_OPERATION;
      R__EXTERN const Int_t ERR_WIN;
      R__EXTERN const Int_t ERR_LASTCODE;
      R__EXTERN const Int_t ERR_SYSRESOURCE;

      class TIntracomm;
      class TGroup;
      class TWin;
      class TInfo;
      class TDatatype;
      class TOp;
      class TErrhandler;
      class TFile;
      class TRequest;

      // null handles
      R__EXTERN const TGroup         GROUP_NULL;
      R__EXTERN const TWin           WIN_NULL;
      R__EXTERN const TInfo          INFO_NULL;
      R__EXTERN TIntracomm           COMM_NULL;
      R__EXTERN const TDatatype      DATATYPE_NULL;
      R__EXTERN TRequest             REQUEST_NULL;
      R__EXTERN const TOp            OP_NULL;
      R__EXTERN const TErrhandler    ERRHANDLER_NULL;
      R__EXTERN const TFile          FILE_NULL;


      // constants specifying empty or ignored input
      R__EXTERN const char**       ARGV_NULL;
      R__EXTERN const char***      ARGVS_NULL;

      // empty group
      R__EXTERN const TGroup  GROUP_EMPTY;

      // topologies
      R__EXTERN const Int_t GRAPH;
      R__EXTERN const Int_t CART;

      // environmental inquiry keys
      R__EXTERN const Int_t TAG_UB;
      R__EXTERN const Int_t HOST;
      R__EXTERN const Int_t IO;
      R__EXTERN const Int_t WTIME_IS_GLOBAL ;
      R__EXTERN const Int_t APPNUM ;
      R__EXTERN const Int_t LASTUSEDCODE ;
      R__EXTERN const Int_t UNIVERSE_SIZE;
      R__EXTERN const Int_t WIN_BASE;
      R__EXTERN const Int_t WIN_SIZE;
      R__EXTERN const Int_t WIN_DISP_UNIT;

// assorted constants
      R__EXTERN const void*  BOTTOM;
      R__EXTERN const void* IN_PLACE;
      R__EXTERN const Int_t PROC_NULL;
      R__EXTERN const Int_t ANY_SOURCE;
      R__EXTERN const Int_t ROOT_RANK;
      R__EXTERN const Int_t ANY_TAG;
      R__EXTERN const Int_t UNDEFINED;
      R__EXTERN const Int_t BSEND_OVERHEAD;
      R__EXTERN const Int_t KEYVAL_INVALID;
      R__EXTERN const Int_t ORDER_C;
      R__EXTERN const Int_t ORDER_FORTRAN;
      R__EXTERN const Int_t DISTRIBUTE_BLOCK;
      R__EXTERN const Int_t DISTRIBUTE_CYCLIC;
      R__EXTERN const Int_t DISTRIBUTE_NONE;
      R__EXTERN const Int_t DISTRIBUTE_DFLT_DARG;

// MPI-2 IO
      R__EXTERN const Int_t MODE_CREATE;
      R__EXTERN const Int_t MODE_RDONLY;
      R__EXTERN const Int_t MODE_WRONLY;
      R__EXTERN const Int_t MODE_RDWR;
      R__EXTERN const Int_t MODE_DELETE_ON_CLOSE;
      R__EXTERN const Int_t MODE_UNIQUE_OPEN;
      R__EXTERN const Int_t MODE_EXCL;
      R__EXTERN const Int_t MODE_APPEND;
      R__EXTERN const Int_t MODE_SEQUENTIAL;
      R__EXTERN const Int_t DISPLACEMENT_CURRENT;
      R__EXTERN const Int_t SEEK_SET;
      R__EXTERN const Int_t SEEK_CUR;
      R__EXTERN const Int_t SEEK_END;
      R__EXTERN const Int_t MAX_DATAREP_STRING;

// thread constants
      R__EXTERN const Int_t THREAD_SINGLE;
      R__EXTERN const Int_t THREAD_FUNNELED;
      R__EXTERN const Int_t THREAD_SERIALIZED;
      R__EXTERN const Int_t THREAD_MULTIPLE;

// results of communicator and group comparisons
      R__EXTERN const Int_t IDENT;
      R__EXTERN const Int_t CONGRUENT;
      R__EXTERN const Int_t SIMILAR;
      R__EXTERN const Int_t UNEQUAL;
   }
}

#endif

