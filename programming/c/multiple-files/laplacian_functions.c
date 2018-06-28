#include <stdio.h>
#include <stdlib.h>
#include "pngwriter.h"

#define DX 0.01
#define DY 0.01

#include "laplacian.h"

int main(void)
{
    	int i, j;
	temp_field T;
	T.Nx	= NX;
	T.Ny	= NY;
	T.dx	= 0.01;
	T.dy	= 0.01;
	T.dx2	= T.dx*T.dx;
	T.dy2	= T.dy*T.dy;

	array(&T);

	double lapla[T.Nx*T.Ny];
	laplacian(&T,&lapla[0]);

 return 0;
}
