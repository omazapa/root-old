// @(#)root/mpi:$Id: LinkDef.h  -- :: $

/*************************************************************************
 * Copyright (C) 2012 , Omar Andres Zapata Mesa           .               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

#pragma link C++ namespace ROOT;
#pragma link C++ namespace ROOT::Mpi;

#pragma link C++ enum    ROOT::Mpi::EComparationType;
#pragma link C++ typedef ROOT::Mpi::User_function;
#pragma link C++ typedef ROOT::Mpi::Aint;
#pragma link C++ typedef ROOT::Mpi::Fint;
#pragma link C++ typedef ROOT::Mpi::Offset;

//REDUCE OPERATIONS
#pragma link C++ global ROOT::Mpi::MAX;    //maximum
#pragma link C++ global ROOT::Mpi::MIN;    //minimum
#pragma link C++ global ROOT::Mpi::SUM;    //sum
#pragma link C++ global ROOT::Mpi::PROD;   //product
#pragma link C++ global ROOT::Mpi::LAND;   //logical and
#pragma link C++ global ROOT::Mpi::BAND;   //bit-wise and
#pragma link C++ global ROOT::Mpi::LOR;    //logical or
#pragma link C++ global ROOT::Mpi::BOR;    //bit-wise or
#pragma link C++ global ROOT::Mpi::LXOR;   //logical xor
#pragma link C++ global ROOT::Mpi::BXOR;   //bit-wise xor
#pragma link C++ global ROOT::Mpi::MAXLOC; //max value and location
#pragma link C++ global ROOT::Mpi::MINLOC; //min value and location

// elementary datatypes (C / C++)
#pragma link C++ global ROOT::Mpi::CHAR;
#pragma link C++ global ROOT::Mpi::SHORT;
#pragma link C++ global ROOT::Mpi::INT;
#pragma link C++ global ROOT::Mpi::LONG;
#pragma link C++ global ROOT::Mpi::SIGNED_CHAR;
#pragma link C++ global ROOT::Mpi::UNSIGNED_CHAR;
#pragma link C++ global ROOT::Mpi::UNSIGNED_SHORT;
#pragma link C++ global ROOT::Mpi::UNSIGNED;
#pragma link C++ global ROOT::Mpi::UNSIGNED_LONG;
#pragma link C++ global ROOT::Mpi::FLOAT;
#pragma link C++ global ROOT::Mpi::DOUBLE;
#pragma link C++ global ROOT::Mpi::LONG_DOUBLE;
#pragma link C++ global ROOT::Mpi::BYTE;
#pragma link C++ global ROOT::Mpi::PACKED;
#pragma link C++ global ROOT::Mpi::WCHAR;

/*
 * Error classes and codes
 */
#pragma link C++ global ROOT::Mpi::SUCCESS;
#pragma link C++ global ROOT::Mpi::ERR_BUFFER;
#pragma link C++ global ROOT::Mpi::ERR_COUNT;
#pragma link C++ global ROOT::Mpi::ERR_TYPE;
#pragma link C++ global ROOT::Mpi::ERR_TAG;
#pragma link C++ global ROOT::Mpi::ERR_COMM;
#pragma link C++ global ROOT::Mpi::ERR_RANK;
#pragma link C++ global ROOT::Mpi::ERR_REQUEST;
#pragma link C++ global ROOT::Mpi::ERR_ROOT;
#pragma link C++ global ROOT::Mpi::ERR_GROUP;
#pragma link C++ global ROOT::Mpi::ERR_OP;
#pragma link C++ global ROOT::Mpi::ERR_TOPOLOGY;
#pragma link C++ global ROOT::Mpi::ERR_DIMS;
#pragma link C++ global ROOT::Mpi::ERR_ARG;
#pragma link C++ global ROOT::Mpi::ERR_UNKNOWN;
#pragma link C++ global ROOT::Mpi::ERR_TRUNCATE;
#pragma link C++ global ROOT::Mpi::ERR_OTHER;
#pragma link C++ global ROOT::Mpi::ERR_INTERN;
#pragma link C++ global ROOT::Mpi::ERR_IN_STATUS;
#pragma link C++ global ROOT::Mpi::ERR_PENDING;
#pragma link C++ global ROOT::Mpi::ERR_ACCESS;
#pragma link C++ global ROOT::Mpi::ERR_AMODE;
#pragma link C++ global ROOT::Mpi::ERR_ASSERT;
#pragma link C++ global ROOT::Mpi::ERR_BAD_FILE;
#pragma link C++ global ROOT::Mpi::ERR_BASE;
#pragma link C++ global ROOT::Mpi::ERR_CONVERSION;
#pragma link C++ global ROOT::Mpi::ERR_DISP;
#pragma link C++ global ROOT::Mpi::ERR_DUP_DATAREP;
#pragma link C++ global ROOT::Mpi::ERR_FILE_EXISTS;
#pragma link C++ global ROOT::Mpi::ERR_FILE_IN_USE;
#pragma link C++ global ROOT::Mpi::ERR_FILE;
#pragma link C++ global ROOT::Mpi::ERR_INFO_KEY;
#pragma link C++ global ROOT::Mpi::ERR_INFO_NOKEY;
#pragma link C++ global ROOT::Mpi::ERR_INFO_VALUE;
#pragma link C++ global ROOT::Mpi::ERR_INFO;
#pragma link C++ global ROOT::Mpi::ERR_IO;
#pragma link C++ global ROOT::Mpi::ERR_KEYVAL;
#pragma link C++ global ROOT::Mpi::ERR_LOCKTYPE;
#pragma link C++ global ROOT::Mpi::ERR_NAME;
#pragma link C++ global ROOT::Mpi::ERR_NO_MEM;
#pragma link C++ global ROOT::Mpi::ERR_NOT_SAME;
#pragma link C++ global ROOT::Mpi::ERR_NO_SPACE;
#pragma link C++ global ROOT::Mpi::ERR_NO_SUCH_FILE;
#pragma link C++ global ROOT::Mpi::ERR_PORT;
#pragma link C++ global ROOT::Mpi::ERR_QUOTA;
#pragma link C++ global ROOT::Mpi::ERR_READ_ONLY;
#pragma link C++ global ROOT::Mpi::ERR_RMA_CONFLICT;
#pragma link C++ global ROOT::Mpi::ERR_RMA_SYNC;
#pragma link C++ global ROOT::Mpi::ERR_SERVICE;
#pragma link C++ global ROOT::Mpi::ERR_SIZE;
#pragma link C++ global ROOT::Mpi::ERR_SPAWN;
#pragma link C++ global ROOT::Mpi::ERR_UNSUPPORTED_DATAREP;
#pragma link C++ global ROOT::Mpi::ERR_UNSUPPORTED_OPERATION;
#pragma link C++ global ROOT::Mpi::ERR_WIN;
#pragma link C++ global ROOT::Mpi::ERR_LASTCODE;
#pragma link C++ global ROOT::Mpi::ERR_SYSRESOURCE;

/*
 * Error-handling specifiers
 */
#pragma link C++ global ROOT::Mpi::ERRORS_ARE_FATAL;
#pragma link C++ global ROOT::Mpi::ERRORS_RETURN;
#pragma link C++ global ROOT::Mpi::ERRORS_THROW_EXCEPTIONS;

/*
 * Null handles
 */
#pragma link C++ global ROOT::Mpi::GROUP_NULL;
#pragma link C++ global ROOT::Mpi::WIN_NULL;
#pragma link C++ global ROOT::Mpi::INFO_NULL;
#pragma link C++ global ROOT::Mpi::COMM_NULL;
#pragma link C++ global ROOT::Mpi::DATATYPE_NULL;
#pragma link C++ global ROOT::Mpi::REQUEST_NULL;
#pragma link C++ global ROOT::Mpi::OP_NULL;
#pragma link C++ global ROOT::Mpi::ERRHANDLER_NULL;
#pragma link C++ global ROOT::Mpi::FILE_NULL;



/*
 * environmental inquiry keys
 */
#pragma link C++ global ROOT::Mpi::TAG_UB;
#pragma link C++ global ROOT::Mpi::HOST;
#pragma link C++ global ROOT::Mpi::IO;
#pragma link C++ global ROOT::Mpi::WTIME_IS_GLOBAL;
#pragma link C++ global ROOT::Mpi::APPNUM;
#pragma link C++ global ROOT::Mpi::LASTUSEDCODE;
#pragma link C++ global ROOT::Mpi::UNIVERSE_SIZE;
#pragma link C++ global ROOT::Mpi::WIN_BASE;
#pragma link C++ global ROOT::Mpi::WIN_SIZE;
#pragma link C++ global ROOT::Mpi::WIN_DISP_UNIT;

/*
 * assorted constants
 */

#pragma link C++ global ROOT::Mpi::BOTTOM;
#pragma link C++ global ROOT::Mpi::IN_PLACE;
#pragma link C++ global ROOT::Mpi::PROC_NULL;
#pragma link C++ global ROOT::Mpi::ANY_SOURCE;
#pragma link C++ global ROOT::Mpi::ROOT_RANK;
#pragma link C++ global ROOT::Mpi::ANY_TAG;
#pragma link C++ global ROOT::Mpi::UNDEFINED;
#pragma link C++ global ROOT::Mpi::BSEND_OVERHEAD;
#pragma link C++ global ROOT::Mpi::KEYVAL_INVALID;
#pragma link C++ global ROOT::Mpi::ORDER_C;
#pragma link C++ global ROOT::Mpi::ORDER_FORTRAN;
#pragma link C++ global ROOT::Mpi::DISTRIBUTE_BLOCK;
#pragma link C++ global ROOT::Mpi::DISTRIBUTE_CYCLIC;
#pragma link C++ global ROOT::Mpi::DISTRIBUTE_NONE;
#pragma link C++ global ROOT::Mpi::DISTRIBUTE_DFLT_DARG;

/*
 * MPI-2 IO
 */
#pragma link C++ global ROOT::Mpi::MODE_CREATE;
#pragma link C++ global ROOT::Mpi::MODE_RDONLY;
#pragma link C++ global ROOT::Mpi::MODE_WRONLY;
#pragma link C++ global ROOT::Mpi::MODE_RDWR;
#pragma link C++ global ROOT::Mpi::MODE_DELETE_ON_CLOSE;
#pragma link C++ global ROOT::Mpi::MODE_UNIQUE_OPEN;
#pragma link C++ global ROOT::Mpi::MODE_EXCL;
#pragma link C++ global ROOT::Mpi::MODE_APPEND;
#pragma link C++ global ROOT::Mpi::MODE_SEQUENTIAL;
#pragma link C++ global ROOT::Mpi::DISPLACEMENT_CURRENT;
#pragma link C++ global ROOT::Mpi::SEEK_SET;
#pragma link C++ global ROOT::Mpi::SEEK_CUR;
#pragma link C++ global ROOT::Mpi::SEEK_END;
#pragma link C++ global ROOT::Mpi::MAX_DATAREP_STRING;

/*
 * thread constants
 */
#pragma link C++ global ROOT::Mpi::THREAD_SINGLE;
#pragma link C++ global ROOT::Mpi::THREAD_FUNNELED;
#pragma link C++ global ROOT::Mpi::THREAD_SERIALIZED;
#pragma link C++ global ROOT::Mpi::THREAD_MULTIPLE;

/*
 * results of communicator and group comparisons
 */
#pragma link C++ global ROOT::Mpi::IDENT;
#pragma link C++ global ROOT::Mpi::CONGRUENT;
#pragma link C++ global ROOT::Mpi::SIMILAR;
#pragma link C++ global ROOT::Mpi::UNEQUAL;

#endif
