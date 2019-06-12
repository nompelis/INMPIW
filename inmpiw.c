#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mpi.h>

#include "inmpiw.h"

// static int *global_INMPIW_constants;


void INMPIWi_Init( void )
{
   MPI_Comm comm;



   comm = MPI_COMM_WORLD;
   memcpy( &INMPIW_COMM_WORLD, &comm, sizeof( MPI_Comm ) );

   comm = MPI_COMM_NULL;
   memcpy( &INMPIW_COMM_NULL, &comm, sizeof( MPI_Comm ) );

}


int INMPIW_Init( int *argc, char ***argv )
{
   int ier;

   (void) INMPIWi_Init();

   ier = MPI_Init( argc, argv );

   return( ier );
}


int INMPIW_Init_thread( int *argc, char ***argv,
                        int irequired, int * iprovided )
{
   int ier;

   (void) INMPIWi_Init();

   ier = MPI_Init_thread( argc, argv, irequired, iprovided );

   return( ier );
}


int INMPIW_Finalize()
{
   int ier;

   ier = MPI_Finalize();

   return( ier );
}


int INMPIW_Info_create( INMPIW_Info *info_w )
{
   int ier;

   ier = MPI_Info_create( (MPI_Info *) info_w );

   return( ier );
}


int INMPIW_Comm_size( INMPIW_Comm comm_w, int *nrank )
{
   int ier;
   MPI_Comm comm;

   memcpy( &comm, &comm_w, sizeof(MPI_Comm) );

   ier = MPI_Comm_size( comm, nrank );

   return( ier );
}


int INMPIW_Comm_rank( INMPIW_Comm comm_w, int *rank )
{
   int ier;
   MPI_Comm comm;

   memcpy( &comm, &comm_w, sizeof(MPI_Comm) );

   ier = MPI_Comm_rank( comm, rank );

   return( ier );
}


int INMPIW_Comm_dup( INMPIW_Comm comi_w, INMPIW_Comm *commo_w )
{
   int ier;
   MPI_Comm comm;

   memcpy( &comm, &comi_w, sizeof( MPI_Comm ) );

   ier = MPI_Comm_dup( comm, (MPI_Comm *) commo_w );

   return( ier );
}


int INMPIW_Comm_split( INMPIW_Comm comi_w, int color, int key,
                       INMPIW_Comm *como_w )
{
   int ier;
   MPI_Comm comm;

   memcpy( &comm, &comi_w, sizeof( MPI_Comm ) );
   ier = MPI_Comm_split( comm, color, key, (MPI_Comm *) como_w );

   return( ier );
}


int INMPIW_Comm_free( INMPIW_Comm *comm_w )
{
   int ier;

   ier = MPI_Comm_free( (MPI_Comm *) comm_w );

   return( ier );
}


int INMPIW_Get_processor_name( char hname[], int *hlen )
{
   int ier;

   ier = MPI_Get_processor_name( hname, hlen );

   return( ier );
}



#ifdef _DEMO_
//
// Demo driver
//

int main( int argc, char *argv[] )
{
   INMPIW_Comm comm,com2,com3;
   INMPIW_Info info;
   int rank,nrank;
   char hname[INMPIW_MAX_PROCESSOR_NAME];
   int hlen;


   INMPIW_Init( &argc, &argv );

   comm = INMPIW_COMM_WORLD;
   INMPIW_Comm_size( comm, &nrank );
   INMPIW_Comm_rank( comm, &rank );
   INMPIW_Info_create( &info );
   INMPIW_Get_processor_name( hname, &hlen );

   INMPIW_Comm_dup( comm, &com2 );

   INMPIW_Comm_size( com2, &nrank );
   INMPIW_Comm_rank( com2, &rank );
   if( rank == 0 ) printf("Rank %d size %d \n",rank,nrank);
   if( rank == 0 ) printf("Hostname: \"%s\" \n", hname);
   INMPIW_Comm_free( &com2 );

   INMPIW_Comm_split( comm, 1, 2, &com3 );
   INMPIW_Comm_free( &com3 );

   INMPIW_Finalize();

   return( EXIT_SUCCESS );
}
#endif

