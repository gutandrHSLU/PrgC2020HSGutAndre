#include <stdio.h>
#include "bitOperation.h"

int main(int argc, char* argv[]){
  unsigned char myNumber = 0x10;
  printf("Before %d, 0x%x \n", (unsigned char)myNumber, (unsigned char)myNumber);
  SetBitNInByte(&myNumber, 1);
  printf("After setting Bit 1 %d, 0x%x\n", (unsigned char)myNumber, (unsigned char)myNumber);
  SetBitNInByte(&myNumber ,7);

	return 0;
}
