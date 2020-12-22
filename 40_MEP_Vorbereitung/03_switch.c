#include <stdio.h>

int main(void){
	int switchValue = 1;//Hier kann irgend ein Wert stehen.

	switch(switchValue){
		case 1:
			printf("The switch state is: %d\n", switchValue);//The switch state is: 1
      switchValue = 2;
      //Hier wird der switchValue geändert
      //So kann zu einem anderen case gesprungen werden.

      //break;
      //Steht "break;" am Ende eines Cases, wird der switchcase verlassen und das Programm beendet.
		case 2:
			printf("The switch state is: %d\n", switchValue);//The switch state is: 2
      switchValue = 3;
		default:
			printf("The switch state is: %d, which is no valid switchstate\n", switchValue);
      //Ist der switchValue in keinem case vorhanden, wird der "default-case"
      //durchgeführt. Dies ist wichtig in sicherheitsrelevanten gebieten.
      break;
	}

  //In diesem Beispiel wird zuerst der case 1, dann der case 2 und am Schluss
  //der default case durchgeführt, in welchem der switchCase mit dem "break;"
  //abgebrochen wird.

  //Die ausgabe des Programmes sieht wie folgt aus:
  // The switch state is: 1
  // The switch state is: 2
  // The switch state is: 3, which is no valid switchstate

	return 0;
}
