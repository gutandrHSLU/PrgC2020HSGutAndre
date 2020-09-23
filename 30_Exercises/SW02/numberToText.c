#include <stdio.h>

int main(int argc, char* argv[]){
	//List of numbers
	char numbers[10][10] = {"zero", "one", "two", "three", "four", "five", 
				"six", "seven", "eight", "nine"};
	

	//Value Input
	int inputValue = 0;
	while(inputValue !=10){
		printf("Enter a number between (including) 0 and 9 to dislpay the number as text. Enter 10 to stop the program:\n ");
		scanf("%d", &inputValue);
		if(inputValue < 0 || inputValue > 10){
			printf("invalid -> try again \n");
		}else if(inputValue == 10){
			printf("Thank you. Good bye.\n");
		}else{
			printf("%d as text is '%s' \n", inputValue, numbers[inputValue]);
		}
	}
	return 0;
}
