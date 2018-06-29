#include <stdio.h>

#define NX 102400

int main(void)
{
    long vecA[NX];
    long sumex,sum;//, psum, sum;
    int i;

    /* Initialization of the vectors */
    for (i = 0; i < NX; i++) {
        vecA[i] = (long) i + 1;
    }

    sumex = (long) NX * (NX + 1) / ((long) 2);
    printf("Arithmetic sum formula (exact):                  %ld\n",
           sumex);

    sum = 0.0;
    /* TODO: Parallelize computation */
#pragma omp parallel for reduction(+:sum)
    for (i = 0; i < NX; i++) {
        sum += vecA[i]; // The idea is that without reduction you can't obtain the real sum because at each threads the initialization of sum is zero
    }
    printf("Sum: %ld\n", sum);


// Alternative way
	long sum2 = 0.;
#pragma omp parallel
{
	long psum = 0.;
	#pragma omp for
	for (i = 0 ; i<NX; i++){
		psum += vecA[i];
	}
	#pragma omp critical(SUM)
	{
		sum2 += psum; 
	}
}
	//printf("%ld\n",psum);
    	//printf("For checking that psum is not defined outside\n"); REAL-> is shared as default
	printf("Sum: %ld\n", sum2);
    return 0;
}
