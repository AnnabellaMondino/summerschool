#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    printf("Hello world!\n");
    #pragma omp parallel
    {
        printf("X\n");
    }


// Exercise 6 of OpenMP lecture
	int nthreads;
#pragma omp parallel 
{
	int tid;
	tid = omp_get_thread_num();
        printf("thread number: %d\n",tid);
	#pragma omp single
        nthreads = omp_get_num_threads();
}
	printf("There are %d threads working.\n",nthreads);
	
    return 0;
}
