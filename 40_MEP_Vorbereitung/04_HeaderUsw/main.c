#include <stdio.h>
#include "A.h"
#include "B.h"

//Dem Compiler muss gesagt werden, dass es das A.c und B.c file auch
//compilieren muss!!!
//gcc -Wall main.c A.c B.c -o
int main(int argc, char* argv[]){
  int c = F2(1, 2);
  printf("%d\n", c);
	return 0;
}
