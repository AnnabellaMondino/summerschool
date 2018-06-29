#include <stdio.h>

int main(int argc, char *argv[])
{
    int f0, f1, f2;

    // initialize variables and write the while loop
    // Remember to update all variables within the loop
	f0 = 0;
	f1 = 1;
	
	int N = 16;
	int i = 0;
	printf("\t Fn \t Fn-1 \t Fn-2\n");
	printf("\t ======================\n");
	do{
		f2 = f1 + f0;
		printf("\t %d \t %d \t %d\n",f2,f1,f0);
		f0 = f1;
		f1 = f2;
		i++;
	}while(i<16);

    return 0;
}
