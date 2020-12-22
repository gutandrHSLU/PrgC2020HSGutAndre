#include <stdio.h>

int main(void){
  int i = 0;
  while(i < 5){
    printf("i currently is: %d\n", i);
    i++;
  }
  //Ausgabe:
  // i currently is: 0
  // i currently is: 1
  // i currently is: 2
  // i currently is: 3
  // i currently is: 4


  //Und auch das noch verkehrt:
  i = 5;
  while(i > 0){
    printf("i currently is: %d\n", i);
    i--;
  }
  //Ausgabe:
  // i currently is: 5
  // i currently is: 4
  // i currently is: 3
  // i currently is: 2
  // i currently is: 1

	//Loops können auch mit "break" gestoppt werden:
  i = 0;
  while(i < 100){
    printf("i currently is: %d\n", i);
    i++;
    if(i == 5){
      printf("Loop wurde bei i = %d gestoppt!\n", i);
      break;
    }
  //Ausgabe:
  // i currently is: 0
  // i currently is: 1
  // i currently is: 2
  // i currently is: 3
  // i currently is: 4
  // Loop wurde bei i = 5 gestoppt!
  }
}
