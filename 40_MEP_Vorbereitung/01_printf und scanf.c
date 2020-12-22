#include <stdio.h>

int main(void){
  //========== Int einlesen ==========
  int a = 0;
  printf("Gib eine Zahl ein: "); //Jetzt kann eine Zahl eingegeben werden.
  scanf("%d", &a);
  //List den eingegebenen Wert und speichert ihn an der Adresse von a
  // "&a" heisst: An die Adresse von a "schicken".
  //Das wird bei den Pointern noch genauer erklärt:)
  printf("Deine Zahl ist: %d\n\n", a); //Deine Zahl ist: *Die Zahl die du eingegeben hast*

  //========== String einlesen ==========
  char wort[20];
  printf("Gib ein Wort ein: ");
  scanf("%s", &wort);
  printf("Dein Wort ist: %s\n", wort);

}
