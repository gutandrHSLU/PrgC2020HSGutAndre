#include <stdio.h>

#define MEINE_VORDEFINIERTE_ARRAYLAENGE 5;

void main(){
  //Arrays initialisieren:
  int arr1[3];              //leeres array: [ , , ]
  int arr2[]  = {1, 2, 3};  //Direkt gefülltes array: [1, 2, 3] Länge wird selber angepasst
  int arr3[5] = {1, 2, 3};  //Halb gefülltes array: [1, 2, 3, , ]
  int arr4[3] = {0};        //Array gefüllt mit "0": [0, 0, 0]
  float arr5[MEINE_VORDEFINIERTE_ARRAYLAENGE]; //Macht folgendes Array: [ , , , , ]

  //In arrays schreiben und auslesen:
  arr1[0] = 69;// arr1 wird zu [69, , ]
  printf("%d\n", arr1[0]); //69

  //Per "scanf" in array schreiben:
  printf("Gib eine Zahl ein: ");
  scanf("%d", &arr1[1]);
  printf("\nDie Zahl %d ist jetzt im Array gespeichert\n", arr1[1]);

  //Durch ein array loopen:
  for (int i = 0; i < (sizeof arr1 /sizeof arr1[0]); i++){
    printf("Zahl %d: %d\n", i, arr1[i]);
  }
  //Ausgabe:
  //Zahl 0: 69
  //Zahl 1: *deine eingegebene Zahl*
  //Zahl 2: *Die letzte Zahl wurde nicht definiert und ist somit zufällig*
}
