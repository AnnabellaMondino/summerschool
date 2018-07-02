#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int my_id, omp_rank, sizempi, sizeomp;
    int provided, required = MPI_THREAD_SINGLE;//MULTIPLE;//SERIALIZED(done, but slowly);//FUNNELED;

    /* TODO: Initialize MPI with thread support. */
	MPI_Init_thread(&argc, &argv, required, &provided);
    /* TODO: Find out the MPI rank and thread ID of each thread and print
     _*       out the results. */
	MPI_Comm_size(MPI_COMM_WORLD,&sizempi);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_id);

	#pragma omp parallel
	{
		omp_rank = omp_get_thread_num();
		sizeomp = omp_get_num_threads();
		printf("I am thread %d of rank %d. We are %d threads in each of the %d ranks.\n",omp_rank,my_id,sizeomp,sizempi);
	}
    /* TODO: Investigate the provided thread support level. */

    MPI_Finalize();
    return 0;
}
