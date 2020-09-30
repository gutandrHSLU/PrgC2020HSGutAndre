#include <stdio.h>
#include <stdlib.h>

//Declaring comparing function
int cmpfunc (const void * a, const void *b){
	return( *(int*)a - *(int*)b );
}

int main(int argc, char* argv[]){
	int value1 = 0, value2 = 0, value3 = 0;
	//Making sure that we have exactly three arguments
	if(argc != 4){
		//usage message
		printf("usage: logicOperators val1, val2, val3\n");
	}else{
		value1 = atoi(argv[1]);
		value2 = atoi(argv[2]);
		value3 = atoi(argv[3]);
		printf("Value1 %d Value2 %d, Value3 %d\n\n", value1, value2, value3);
		
		//sorting the array with the initial values
		int values[] = {value1, value2, value3};
		qsort(values, sizeof(values) / sizeof(values[0]), sizeof(int), cmpfunc);
		
		//give output
		if(value1 < 0 && value2 < 0 && value3 < 0){
			printf("The entered values are not all positive. Exiting.");
		}else{
			printf("The smallest of the entered values is: %d \n", values[0]);
			printf("The largest of the entered values is: %d \n", values[2]);
		}
	}
	return 0;
}
