#include <stdio.h>

int main(void){
	int value1 = 0;
	int value2 = 0;
	printf("Enter the first number \n");
	scanf("%d", &value1);
	printf("Enter the second number: \n");
	scanf("%d", &value2);
	if(value1 > value2){
		printf("The first number is bigger than the second one! \n");
	}else if(value2 > value1){
		printf("the second number is bigger than the first one! \n");
	}else{
		printf("The two numbers are equal!\n");
	}
	return 0;
}
