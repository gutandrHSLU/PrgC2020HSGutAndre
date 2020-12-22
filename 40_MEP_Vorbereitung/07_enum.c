#include <stdio.h>
//Mit enumerationen können informationen "organisiert" werden.

enum{
  enum1 = 5,
  enum2 = 10,
  enum3 = 2
};

//Wird in der Enumeration kein Wert gegeben, wird einfach weiter gezählt:
enum{
  enum4 = 1,
  enum5, //bekommt den Wert 2
  enum6, //bekommt den Wert 3
  enum7  //bekommt den Wert 4
};

//Eine Enumeration kann auch als typ definiert werden:
typedef enum {
  AUTO = 4,
  TOEFF = 2,
  DREIRAD = 3,
  LASTWAGEN = 6
} Fahrzeug;


void main(){
  int a = enum1;
  printf("a = enum1 = %d\n", a); //5

  printf("enum7 = %d\n", enum7);

  Fahrzeug anzRaederTesla = AUTO;
  printf("Ein Tesla hat %d Raeder\n", anzRaederTesla);
}
