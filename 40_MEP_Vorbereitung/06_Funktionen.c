#include <stdio.h>

//Deklaration von func1. Ausgabe ist ein int:
int func1 (int a, int b);
//Deklaration von func2. Ausgabe ist ein float:
float func2 (int a, float b);
//Deklaration von func3 ohne Ausgabe:
void func3 (int a);
//Deklaration von func4 ohne Eingabe:
int func4(void);

//Deklaration in allgemeiner Form:
//<ausgabeformat> <Funtionsname> (<typ des Eingabewertes> <Eingabewert>, ... );

//Unterschied Parameter und Argument!
//Beispiel:
int func99 (int parameter1);
//Parameter ist in der Deklaration und Implementation!
//Argument wird beim Aufruf der Funktion verwendet

int main(void){
  int result1 = func1(1, 2);//result1 wird = 3
  float result2 = func2(1, 6.9);//result2 wird = 7.9
  func3(69);//Hier wird 69 geprinted
  int nice = func4();//nice wird = 420;

  int argument1 = 1;
  int resultat = func99(argument1);
}

//Implementierung func1:
int func1(int a, int b){
  int res = 3 * a - b;
  return res;
}

//implementierung func2
float func2(int a, float b){
  float res = a + b;
  return res;
}

void func3(int a){
    printf("%d\n", a);
}

int func4(void){
  return 420;
}

int func99(int parameter1){
  int res = parameter1 + 1;
  return res;
}
