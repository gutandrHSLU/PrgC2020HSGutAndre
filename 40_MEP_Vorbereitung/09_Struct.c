#include <stdio.h>

//Hier wird eine Struktur definiert. Die Struktur heisst "punkt"
struct punkt {
  int x;
  int y;
};

//Hier wird eine Struktur definiert, welche Strukturen enthält. Sie heisst "rechteck"
struct rechteck {
  struct punkt P1;
  struct punkt P2;
};

int main(){
  //hier werden Punkte mit der Struktur "punkt" erzeugt
  struct punkt punkt1 = {69, 10};
  struct punkt punkt2 = {10, 420};
  printf("X-Koordinate von Punkt1: %d\n", punkt1.x); //69
  printf("Y-Koordinate von Punkt2: %d\n\n", punkt2.y); //420

  //Hier wird ein Rechteck mit der Struktur "rechteck" erzeugt
  struct rechteck meinRechteck = {punkt1, punkt2};
  printf("Y-Koordinate des ersten Punktes: %d\n", meinRechteck.P1.y); //10

  //So kann auch ein Rechteck erstellt werden
  struct rechteck neuesRechteck = {{1, 2}, {3, 4}};
  printf("X-Koordinate des zweiten Punktes%d", neuesRechteck.P2.x); //3

}
