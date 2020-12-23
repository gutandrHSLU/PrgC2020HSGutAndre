#include <stdio.h>

int main(){
  int a = 10;
  printf("Wert von a: %d\n", a); //Wert von a: 10
  printf("Adresse von a: %d\n\n", &a); //Adresse von a: 65182 (Diese Zahl ändert sich bei jeder Durchführung)
  //"&" bedeutet: Adresse von...

  int *pointer_zu_a;  //mit "*" wird dem compiler gesagt, dass es sich um ein Pointer handelt.
                      // mit "int" wird dem complier gesagt, dass der pointer zu einem int zeigt.
  pointer_zu_a = &a;  //Hier wird dem Pointer die Adresse von a gegeben
  printf("Pointer zeigt zur Adresse: %d\n", pointer_zu_a); //Adresse von a: 65182 (Diese Zahl ändert sich bei jeder Durchführung)
  printf("Wert an dieser Adresse: %d\n\n", *pointer_zu_a); //Wert an dieser Adresse: 10
  //"*" bedeutet: Wert an dieser Adresse...

  // & heisst: Adresse von...
  // * heisst: Das ist ein Pointer oder
  // * heisst: Wert wo der Pointer hin zeigt
  return 0;
}
