#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
	short largeShort = 32760;
	printf("before: %d ", largeShort);
	largeShort = largeShort + 12345;
	printf("after: %d \n\n", largeShort);
	
	int numerator = 19, denominator = 5, result = 0;
	printf("before: %d ", result);
	result = numerator / denominator;
	printf("after: %d \n\n", result);
	
	float e = 2.71821828f;
	printf("before: %f ", e);
	e++;
	printf("after: %f ", e);
	e--;
	printf("afterafter: %f \n", e);
	
	double dblNumber = 12.8;
	printf("before: %f ", dblNumber);
	dblNumber = dblNumber%#3;
	printf("after: %f \n", dblNumber);
	
	return 0;
}
