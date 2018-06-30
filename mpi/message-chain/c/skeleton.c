#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int i, myid, ntasks;
    int size = 10000000;
    int *message;
    int *receiveBuffer;
    MPI_Status status;

    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    /* Allocate message buffers */
    message = malloc(sizeof(int) * size);
    receiveBuffer = malloc(sizeof(int) * size);
    /* Initialize message */
    for (i = 0; i < size; i++) {
        message[i] = myid;
    }

    /* Start measuring the time spent in communication */
    MPI_Barrier(MPI_COMM_WORLD);
    t0 = MPI_Wtime();

    /* TODO start */
    /* Send and receive messages as defined in exercise */


// ONE ------------------------------------------
   /* if (myid < ntasks - 1) {
	MPI_Send(message,size,MPI_INT,myid+1,myid+1,MPI_COMM_WORLD);
        printf("Sender: %d. Sent elements: %d. Tag: %d. Receiver: %d\n",
               myid, size, myid + 1, myid + 1);
    }

    if (myid > 0) {
	MPI_Recv(receiveBuffer,size,MPI_INT,myid-1,myid,MPI_COMM_WORLD,&status);
        printf("Receiver: %d. first element %d.\n",
               myid, receiveBuffer[0]);
    } */

// TWO -------------------------------------------

	/*if (myid < ntasks - 1 && myid > 0){
		MPI_Sendrecv(message,size,MPI_INT,myid+1,myid+1,receiveBuffer,size,MPI_INT,myid-1,myid, MPI_COMM_WORLD,&status);
	}else if (myid == 0){
		MPI_Send(message,size,MPI_INT,myid+1,myid+1,MPI_COMM_WORLD);
	}else if (myid == ntasks-1){
		MPI_Recv(receiveBuffer,size,MPI_INT,myid-1,myid,MPI_COMM_WORLD,&status);
	}*/

// THREE ----------------------------------------

/*    if (myid < ntasks - 1) {
        MPI_Send(message,size,MPI_INT,myid+1,myid+1,MPI_COMM_WORLD);
        printf("Sender: %d. Sent elements: %d. Tag: %d. Receiver: %d\n",
               myid, size, myid + 1, myid + 1);
    }

    if (myid > 0) {
        MPI_Recv(receiveBuffer,size,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
        printf("Receiver: %d. first element %d.\n",
               myid, receiveBuffer[0]);
    }*/

	/* if (myid < ntasks-1){
		MPI_Sendrecv(message,size,MPI_INT,myid+1,myid+1,receiveBuffer,size,MPI_INT,PROC_ANY_SOURCE,myid, MPI_COMM_WORLD,&status);
	}
	if (myid == ntasks -1){
		MPI_Recv(receiveBuffer,size,MPI_INT,myid-1,myid,MPI_COMM_WORLD,&status);
	} */ //NOT WORKING

	int down = myid -1;
	int up = myid +1;
	if (down<0){
		down = MPI_PROC_NULL;
	}else if (up > ntasks -1){
		up = MPI_PROC_NULL;
	}
        MPI_Sendrecv(message,size,MPI_INT,up,myid+1,receiveBuffer,size,MPI_INT,down,myid, MPI_COMM_WORLD,&status);

// FOUR ---------------------------------------

/*	int datarecv;
        if (myid < ntasks - 1 && myid > 0){
                MPI_Sendrecv(message,size,MPI_INT,myid+1,myid+1,receiveBuffer,size,MPI_INT,myid-1,myid, MPI_COMM_WORLD,&status);
        	MPI_Get_count(&status,MPI_INT,&datarecv);
		printf("I receive %d amount of integers\n",datarecv);
	}else if (myid == 0){
                MPI_Send(message,size,MPI_INT,myid+1,myid+1,MPI_COMM_WORLD);
        }else if (myid == ntasks-1){
                MPI_Recv(receiveBuffer,size,MPI_INT,myid-1,myid,MPI_COMM_WORLD,&status);
                MPI_Get_count(&status,MPI_INT,&datarecv);
                printf("I receive %d amount of integers\n",datarecv);

        }
*/
// ----------------------------------------------
    /* TODO end */

    /* Finalize measuring the time and print it out */
    t1 = MPI_Wtime();
    MPI_Barrier(MPI_COMM_WORLD);
    fflush(stdout);

    printf("Time elapsed in rank %2d: %6.3f\n", myid, t1 - t0);

    free(message);
    free(receiveBuffer);
    MPI_Finalize();
    return 0;
}
