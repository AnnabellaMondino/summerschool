#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	int i, my_id, omp_rank,sizempi,sizeomp,msg;
    	int provided, required = MPI_THREAD_MULTIPLE;

    /* TODO: Initialize MPI with thread support. */
        MPI_Init_thread(&argc, &argv, required, &provided);

    /* Check that the MPI implementation supports MPI_THREAD_MULTIPLE */
    if (provided < MPI_THREAD_MULTIPLE) {
        printf("MPI does not support MPI_THREAD_MULTIPLE\n");
        MPI_Abort(MPI_COMM_WORLD, -1);
        return 0;
    }

	MPI_Comm_rank(MPI_COMM_WORLD,&my_id);
	MPI_Comm_size(MPI_COMM_WORLD,&sizempi);

	#pragma omp parallel private(sizeomp, omp_rank,msg)
	{
	//omp_rank = omp_get_thread_num();
	//sizeomp = omp_get_num_threads();
        sizeomp = omp_get_num_threads();
        omp_rank = omp_get_thread_num();
//	printf("thread: %d rank: %d\n",omp_rank,my_id);	
	if (my_id == 0){
		for (i=1; i<sizempi; i++){
			MPI_Send(&omp_rank, 1, MPI_INTEGER, i, omp_rank, MPI_COMM_WORLD);
		}
        } else {
//		printf("inside-> thread: %d rank: %d\n",omp_rank,my_id);
            	MPI_Recv(&msg, 1, MPI_INTEGER, 0, omp_rank, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
           	printf("Rank %i thread %i received %i\n", my_id, omp_rank, msg);
        }

	}

	MPI_Finalize();
}
