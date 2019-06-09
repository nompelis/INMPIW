
#ifndef _INMPIW_H_
#define _INMPIW_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mpi.h>


#warning "UNFINISHED"
//
// constants to be used as indices for addressing elements of the array of
// constants stored for the particular implementation
//

enum INMPIW_Index {
   INMPIW_CHAR,
   INMPIW_UCHAR,
   INMPIW_INT,
   INMPIW_LONG,
   INMPIW_FLOAT,
   INMPIW_DOUBLE
};


//
// definitions of variable types and other definitions
// (this header file is provided and is the output of the query code)
//

#include "inmpiw_defs.h"

//
// variables or values built by preprocessor macros
//
INMPIW_Comm INMPIW_COMM_WORLD;
INMPIW_Comm INMPIW_COMM_NULL;



#endif

