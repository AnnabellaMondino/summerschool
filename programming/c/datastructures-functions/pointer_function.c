#include <stdio.h>

void add_one_to_both(int *a, int *b){
	(*a)++;
	(*b)++;
}

void main(){
	int a, b;
	a = 10;
	b = 20;

	printf("The initial values are: %d\t%d\n",a,b);

	add_one_to_both(&a,&b);

	printf("After adding 1, the values are: %d\t%d\n", a,b);

}
