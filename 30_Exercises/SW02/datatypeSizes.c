#include <stdio.h>

int main(int argc, char* argv[]){

	printf("Size of Char is: %ld\n", sizeof(char));//1
	printf("Size of Short is: %ld\n", sizeof(short));//2
	printf("Size of Int is: %ld\n", sizeof(int));//4
	printf("Size of Int is: %ld\n", sizeof(int));//4
	printf("Size of Long is: %ld\n", sizeof(long));//4
	printf("Size of Long Long is: %ld\n", sizeof(long));//4
	printf("Size of Float is: %ld\n", sizeof(long long));//8
	printf("Size of Double is: %ld\n", sizeof(double));//8
	printf("Size of Long Double is: %ld\n", sizeof(long double));//16

	return 0;

	// printf("Enter a number between (including) 0 and 9 to dislpay the number as text. Enter 10 to stop the program:\n ");
	// scanf("%d", &readValue);
}
