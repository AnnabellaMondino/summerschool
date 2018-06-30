#include "stdio.h"
#include <mpi.h>

void main(int argc, char *argv[]){
	int rc, rank, cores;

	rc = MPI_Init(&argc, &argv);
	rc = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("Hello world from %d core.\n", rank);

	if (rank==0){
		rc = MPI_Comm_size(MPI_COMM_WORLD, &cores);
		printf("Hi! I am core %d, and we are %d processors in total.\n", rank, cores);
	}

	rc = MPI_Finalize();

}
