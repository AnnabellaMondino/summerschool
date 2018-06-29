#include <stdio.h>

#define NX 8//102400

int main(void)
{
    double vecA[NX], vecB[NX], vecC[NX];
    double sum;
    int i;

    /* Initialization of the vectors */
    for (i = 0; i < NX; i++) {
        vecA[i] = 1.0 / ((double)(NX - i));
        vecB[i] = vecA[i] * vecA[i];
    }

        printf("vecA =\t");
	for (i=0; i<NX; i++){
		printf("%lf\t", vecA[i]);
	}
	printf("\n");

	printf("vecB =\t");
        for (i=0; i<NX; i++){
                printf("%lf\t", vecB[i]);
        }
        printf("\n");

    /* TODO:
     *   Implement here a parallelized version of vector addition,
     *   vecC = vecA + vecB
     */
#pragma omp parallel for 
	for (i=0; i<NX; i++){
		vecC[i] = vecA[i] + vecB[i];
	}

        printf("vecC =\t");
        for (i=0; i<NX; i++){
                printf("%lf\t", vecC[i]);
        }
	printf("\n");


    sum = 0.0;
    /* Compute the check value */
#pragma omp parallel for shared(vecC) private(i) reduction(+:sum)
    for (i = 0; i < NX; i++) {
        sum += vecC[i];
    }
    printf("Reduction sum: %18.16f\n", sum);

    return 0;
}
