#include <stdio.h>

//Deklaration von func1. Ausgabe ist ein int:
int func1 (int a, int b);
//Deklaration von func2. Ausgabe ist ein float:
float func2 (int a, float b);
//Deklaration von func3 ohne Ausgabe:
void func3 (int a);
//Deklaration von func4 ohne Eingabe:
int func4(void);

//==================== Mehr als ein Ausgabewert ====================
//Der Funktion werden Pointer mitgegeben. Das resultat der Funktion wird dort hin geschrieben
//Wo der Pointer hin zeigt.
void func5(int a, int b, int *summe, int *produkt);

//==================== Rekursion ====================
long Factorial(long n);

//Deklaration in allgemeiner Form:
//<ausgabeformat> <Funtionsname> (<typ des Eingabewertes> <Eingabewert>, ... );

//Unterschied Parameter und Argument!
//Beispiel:
int func99 (int parameter1);
//Parameter ist in der Deklaration und Implementation! vgl. Implementation weiter unten
//Argument wird beim Aufruf der Funktion verwendet vgl. Funktion func99 im main

int main(void){
  int result1 = func1(1, 2);//result1 wird = 3
  float result2 = func2(1, 6.9);//result2 wird = 7.9
  func3(69);//Hier wird 69 geprinted
  int nice = func4();//nice wird = 420;

  //==================== Mehr als ein Ausgabewert ====================
  int summe;
  int produkt;
  func5(5, 10, &summe, &produkt);
  printf("%d %d\n", summe, produkt);//15 50

  //==================== Rekursion ====================
  long n = 4;
  long resultat = Factorial(n);
  printf("%ld factorial is: %ld\n", n, resultat); //4 factorial is: 24

  //==================== Unterschied Argument und Parameter ====================
  int argument1 = 1;
  resultat = func99(argument1);
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

void func5(int a, int b, int *summe, int *produkt){
  *summe = a + b;//Schreibt das Resultat dort hin, wo der pointer hin zeigt.
  *produkt = a * b;
}

long Factorial(long n){
	long result = 0;
	if(n){
		result = n*Factorial(n-1); //Hier wird die Funktion in sich selbst aufgerufen!
	}else{
		result = 1;
	}
	return result;
}

int func99(int parameter1){
  int res = parameter1 + 1;
  return res;
}
