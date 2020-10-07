#include <stdio.h>
#include <stdlib.h>

//Deklarierung
long ComputeCubic(long x);

int main(int argc, char* argv[]){
	long input = atoi(argv[1]);
	long xCubed = 0;
	printf("Input Value: %ld\n", input);
	xCubed = ComputeCubic(input);
	
	printf("Cubic Value: %ld\n", xCubed);
	



	return 0;
}


//Implementation
long ComputeCubic(long x){
	long xCubed = 0;
	xCubed = x*x*x;
	return xCubed;
}
