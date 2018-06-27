#include <stdio.h>
#include <stdlib.h>

#define NX 258
#define NY 258

int main(void)
{
    int i, j;
    // Add here the definition for array with name 'array'
    // of size NX times NY (258x258)
//#error Define the array
	double matrix [NX][NY];
    // Initialize first the zeros
//#error Initialize the zeros for interior
	for (i=1; i<(NX-1); i++){
		for (j=1; j<(NY-1); j++){
			matrix[i][j] = 0.;
		}
	}
    // Initial conditions for left and right
//#error add boundary conditions for left and right
	for (i=0; i<NX; i++){
		matrix[i][0] = 20.;
		matrix[i][NY-1] = 70.;
	}	
    // and top and bottom boundaries
//#error add boundary conditions for top and bottom
	for (j=0; j<NY; j++){
		matrix[0][j] = 85.;
		matrix[NX-1][j] =5.;
	}

	/*for (i=0; i<NX; i++){
		for (j=0; j<NY; j++){
			printf("%e\t",matrix[i][j]);
		}
		printf("\n");
	}*/

    return 0;
}
