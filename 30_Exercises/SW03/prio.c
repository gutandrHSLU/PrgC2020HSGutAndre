#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int a = 0, b = 0;
	printf("a: %d\n", ++a);
	printf("b: %d\n", b++);
	printf("a: %d,  b: %d", a, b);
	
	return 0;
}
