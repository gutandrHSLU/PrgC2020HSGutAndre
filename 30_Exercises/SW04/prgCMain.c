#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum{
	MAIN_MENU = 1,
	NUMSTAT,
	CUBIC,
	FACTORIAL,
	NCHOOSEK,
	PRINTBINARY,
	EXIT
}MenuItem;

//Deklarierung von Funktionen
MenuItem PrintMainMenu(void);
long ComputeCubic(long x);
long Factorial(long n);
void Numstat(float value1, float value2);
long Nchoosek(long n, long k);
void PrintBinary(void);
void pb(unsigned int n);

//Main
int main(int argc, char* argv[]){
	MenuItem switchValue = MAIN_MENU;
	int run = 1;
	long input = 0;
	long input2 = 0;
	float value1 = 0; //for Numstat
	float value2 = 0; //for Numstat
	while(run){
		switch(switchValue){
			case MAIN_MENU:
				switchValue = PrintMainMenu();
				break;
			case NUMSTAT:
				printf("Enter two values (Type: float):\n");
				printf("Value 1: ");
				scanf("%f", &value1);
				printf("Value 2: ");
				scanf("%f", &value2);
				Numstat(value1, value2);
				switchValue = MAIN_MENU;
				break;
			case CUBIC:
				printf("Enter the value you want to Cube: ");
				scanf("%ld", &input);
				printf("%ld cubed is: %ld\n\n", input, ComputeCubic(input));
				switchValue = MAIN_MENU;
				break;
			case FACTORIAL:
				printf("Enter the value you want the factorial of: ");
				scanf("%ld", &input);
				printf("%ld! is: %ld\n\n", input, Factorial(input));
				switchValue = MAIN_MENU;
				break;
			case NCHOOSEK:
				printf("Enter two values (Type: int):\n");
				printf("Value 1: ");
				scanf("%ld", &input);
				printf("Value 2: ");
				scanf("%ld", &input2);
				printf("%ld tief %ld beträgt %ld\n\n", input, input2, Nchoosek(input, input2));
				switchValue = MAIN_MENU;
				break;
			case PRINTBINARY:
				PrintBinary();
				//printf("Enter the value you want to see in binary form: ");
				//scanf("%ld", &input);
				//pb(input);
				switchValue = MAIN_MENU;
				break;
			case EXIT:
				printf("Good Bye!\n\n");
				switchValue = MAIN_MENU;
				run = 0;
				break;
			default:
				printf("default\n");
				break;
		}
	}
	return 0;
}




// function implementations:
MenuItem PrintMainMenu( void ){
	MenuItem selection = MAIN_MENU;
	printf("Main Menu\n");
	printf("***********************************\n\n");
	printf("Select from the following options:\n");
	printf("%d - NumStat\n", NUMSTAT);
	printf("%d - Cubic\n", CUBIC);
	printf("%d - Factorial\n", FACTORIAL);
	printf("%d - NCHOOSEK\n", NCHOOSEK);
	printf("%d - PRINTBINARY\n", PRINTBINARY);
	printf("%d - Exit\n", EXIT);
	printf("--> ");
	scanf("%d", (int*)&selection);
	return selection;
}

long ComputeCubic(long x){
	return x*x*x;
}

long Factorial(long n){
	long result = 0;
	if(n){
		result = n*Factorial(n-1);
	}else{
		result = 1;
	}
	return result;
}

void Numstat(float value1, float value2){
	if(value1 < value2){
		printf("Values in ascending order: %.3f %.3f\n", value1, value2);
	} else {
		printf("Values in ascending order: %.3f %.3f\n", value2, value1);
	}
	printf("Sum: %.3f\n", value1 + value2);
	printf("Absolute difference: %.3f\n", fabs(value1 - value2));
	printf("Product: %.3f\n", value1 * value2);
	printf("Ratio: %.3f\n\n", value2 / value1);
}

long Nchoosek(long n, long k){
	long result = 0;
	result = (Factorial(n))/(Factorial(k)*Factorial(n-k));
	return result;
}

void PrintBinary(void){
	int n;
	int bits[4];
	int counter = 0;
	printf("Enter the value you want to see in binary form: ");
	scanf("%d", &n);
	printf("%d in binary form is: 0b", n);
	while(n){
		if(n&1)
			bits[counter] = 1;
		else
			bits[counter] = 0;
		n>>=1;
		counter++;
	}
	//printf("%d", counter);
	for(int i = counter-1; i>=0; i--){
		printf("%d", bits[i]);
	}
	printf("\n\n");
	return;
}
