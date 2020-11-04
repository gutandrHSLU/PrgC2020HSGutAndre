#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  unsigned char a = 12;
  unsigned char b = 25;

  printf("bitwise AND &: %d \n", a & b);
  printf("bitwise OR | %d \n", a | b);
  printf("bitwise XOR ^ %d \n", a ^ b);
  printf("bitwise Complement ~: %d \n", (unsigned char)~a);
	return 0;
}
