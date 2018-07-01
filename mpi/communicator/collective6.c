#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void print_buffers(int *printbuffer, int *sendbuffer, int buffersize);

void main(int argc, char *argv[]){

	int ntasks, rank;
    	int i, size,color;
	int printbuf[size*2];

	MPI_Comm subcomm;

	size = 8;
	int *array, *recvbuffer;
	array = (int *) malloc(size*sizeof(int));
	recvbuffer = (int *) malloc(size*sizeof(int));

	MPI_Init(&argc, &argv);
    	MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	for (i=0;i<size;i++){
		array[i] = i + size*rank;
		recvbuffer[i] = -1;
	}
//	print_buffers(printbuf, array, size);

//	MPI_Bcast(array,size,MPI_INT,0,MPI_COMM_WORLD);
//        print_buffers(printbuf, array, size);

//	MPI_Scatter(array,2,MPI_INT,recvbuffer,2,MPI_INT,0,MPI_COMM_WORLD);
//        print_buffers(printbuf, recvbuffer, size);

	int *recvcount;
	recvcount = (int *) malloc(ntasks*sizeof(int));
	recvcount[0] = 1;
	recvcount[1] = 1;
	recvcount[2] = 2;
	recvcount[3] = 4;
        int *displs;
        displs = (int *) malloc(ntasks*sizeof(int));
        displs[0] = 0;
        displs[1] = 1;
        displs[2] = 2;
        displs[3] = 4;

//	MPI_Gatherv(array,recvcount[rank],MPI_INT,recvbuffer,recvcount,displs,MPI_INT,1,MPI_COMM_WORLD);
//        print_buffers(printbuf, recvbuffer, size);


//	MPI_Alltoall(array,2,MPI_INT,recvbuffer,2,MPI_INT,MPI_COMM_WORLD);
//        print_buffers(printbuf, recvbuffer, size);

	if (rank/2 == 0){
		color = 0;
	} else {
		color = 1;
	}

	MPI_Comm_split(MPI_COMM_WORLD, color, rank, &subcomm);
	MPI_Reduce(array,recvbuffer,size,MPI_INT,MPI_SUM,0,subcomm);
        print_buffers(printbuf, recvbuffer, size);


	MPI_Finalize;
}

void print_buffers(int *printbuffer, int *sendbuffer, int buffersize)
{
    int i, j, rank, ntasks;

    MPI_Gather(sendbuffer, buffersize, MPI_INT,
               printbuffer, buffersize, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);

    if (rank == 0) {
        for (j = 0; j < ntasks; j++) {
            printf("Task %i:", j);
            for (i = 0; i < buffersize; i++) {
                printf(" %2i", printbuffer[i + buffersize * j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

