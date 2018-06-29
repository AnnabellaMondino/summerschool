#include <stdio.h>

void main(){
	int a;
	float b = 2.43;
	float* p;
	double c;

	a = 10;
	c = b*a;
	printf("%d\t%f\t%e\n",a,b,c);
	p = &b;
	b -=20;
	printf("%f\t%f\n",b,*p);
}
