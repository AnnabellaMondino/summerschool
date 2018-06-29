#include <stdio.h>
#include <stdlib.h>
#include "pngwriter.h"

#define NX 258
#define NY 258

#define DX 0.01
#define DY 0.01

#include "laplacian.h"

int main(void)
{
    	int i, j;
	temp_field T;
	T.Nx	= 5;
	T.Ny	= 8;
	T.dx	= 0.01;
	T.dy	= 0.01;
	T.dx2	= T.dx*T.dx;
	T.dy2	= T.dy*T.dy;

	array(&T);

	double lapla[T.Nx*T.Ny];
	laplacian(&T,&lapla);

 return 0;
}
