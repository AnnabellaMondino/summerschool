#include <stdio.h>

void main(){
	int a;
	printf("Write an integer number\n");
	scanf("%d",&a);
//	printf("%d",a);
	if (a<0){
		printf("a is negative\n");
	}else if (a==0){
		printf("a is zero\n");
	}else if (a>100){
		printf("a is larger than 100\n");
	}
}
