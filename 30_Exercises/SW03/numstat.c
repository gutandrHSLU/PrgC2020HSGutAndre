#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]){
	float value1 = 0, value2 = 0;
	//Making sure that we have exactly three arguments
	if(argc != 3){
		//usage message
		printf("usage: logicOperators val1, val2\n");
	}else{ //converts input string to float
		value1 = strtof(argv[1], NULL);
		value2 = strtof(argv[2], NULL);
		//printf("Value1 %f Value2 %f\n\n", value1, value2);
		
		//a) Inputs (in ascending order)
		if(value1 < value2){
			printf("%.3f %.3f\n", value1, value2);
		} else {
			printf("%.3f %.3f\n", value2, value1);
		}
		
		//b) Sum
		printf("%.3f\n", value1 + value2);
		
		//c) Absolute Difference
		printf("%.3f\n", fabs(value1 - value2));
		
		//d) Product
		printf("%.3f\n", value1 * value2);
		
		//e) Ratio
		printf("%.3f\n", value2 / value1);
	}
	return 0;
}
