#include "A.h"
//Da das "A.h" File hier auch included wird, kann die Funktion F1 aufgerufen werden
int F2(int a, int b){
  int c = F1(a, b) * 2;
  return c;
}
