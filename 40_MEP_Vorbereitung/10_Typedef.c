#include <stdio.h>

//Hier wird ein Type definiert welcher punkt heisst
typedef struct  {
  int x;
  int y;
}punkt;

//Hier wird eine Type definiert, welche Typen enthält und rechteck heisst
typedef struct  {
  punkt P1;
  punkt P2;
}rechteck;

int main(){
  //hier werden Punkte des typs "punkt" definiert
  punkt punkt1 = {69, 10};
  punkt punkt2 = {10, 420};
  printf("X-Koordinate von Punkt1: %d\n", punkt1.x); //69
  printf("Y-Koordinate von Punkt2: %d\n\n", punkt2.y); //420

  //Hier wird ein Rechteck des typs "rechteck" erzeugt
  rechteck meinRechteck = {punkt1, punkt2};
  printf("Y-Koordinate des ersten Punktes: %d\n\n", meinRechteck.P1.y); //10

  //So kann auch ein Rechteck erstellt werden
  rechteck neuesRechteck = {{1, 2}, {3, 4}};
  printf("Y-Koordinate des Ersten Punktes des neuen Rechteckes: %d\n", neuesRechteck.P1.y); //2

}
