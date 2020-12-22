#include <stdio.h>

int main(void){
	for (int i = 0; i < 5; i++){
		printf("i currently is: %d\n", i);
	}
	//Ausgabe:
	// i currently is: 0
	// i currently is: 1
	// i currently is: 2
	// i currently is: 3
	// i currently is: 4

	//Das alles kann man auch verkehrt herum machen:
	for (int i = 5; i > 0; i--){
		printf("i currently is: %d\n", i);
	}
	//Ausgabe:
	// i currently is: 5
	// i currently is: 4
	// i currently is: 3
	// i currently is: 2
	// i currently is: 1

	//Man kann dies auch z.B. in 2er Schritten machen:
	for (int i = 0; i < 10; i+= 2){
		printf("i currently is: %d\n", i);
	}
	//Ausgabe:
	// i currently is: 0
	// i currently is: 2
	// i currently is: 4
	// i currently is: 6
	// i currently is: 8

	//Loops können auch mit "break" gestoppt werden:
	for (int i = 0; i < 100; i++){
		printf("i currently is: %d\n", i);
		if (i == 5){
			printf("Loop wurde bei i = %d gestoppt!\n", i);
			break;
		}
	}
	//Ausgabe:
	// i currently is: 0
	// i currently is: 1
	// i currently is: 2
	// i currently is: 3
	// i currently is: 4
	// i currently is: 5
	// Loop wurde bei i = 5 gestoppt!
}
