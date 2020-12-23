#include <stdio.h>

void PrintBinary(int n);
//!!ACHTUNG!! Mit der Funktion können nur positive int geprintet werden!

void main(){
  int a = 12; //00001100
  int b = 25; //00011001

  //==================== Hex Initialisierung ====================
  a = 0x0C; // 12 = 00001100: 0000 = 0, 1100 = C -> 12 = 0x0C
  b = 0x19; // 25 = 00011001: 0001 = 0, 1001 = 9 -> 25 = 0x19

  //==================== Bin Initialisierung ====================
  a = 0b00001100; // 12
  b = 0b00011001; // 25

  //==================== Bitwise AND ====================
  printf("Bitwise AND: \n");
  int c = a&b;
  PrintBinary(a);
  PrintBinary(b);
  PrintBinary(c);

  //Ausgabe:
  // 12 =    00001100
  // 25 =    00011001
  // 8 =     00001000

  //==================== Bitwise OR ====================
  printf("\nBitwise OR: \n");
  c = a|b;
  PrintBinary(a);
  PrintBinary(b);
  PrintBinary(c);
  //Ausgabe:
  // 12 =    00001100
  // 25 =    00011001
  // 29 =    00011101

  //==================== Bitwise XOR ====================
  printf("\nBitwise XOR: \n");
  c = a^b;
  PrintBinary(a);
  PrintBinary(b);
  PrintBinary(c);
  //Ausgabe:
  // 12 =    00001100
  // 25 =    00011001
  // 21 =    00010101

  //==================== Bitwise complement ====================
  printf("\nBitwise complement: \n");
  c = ~a;
  PrintBinary(a);
  PrintBinary(c);
  // 12 =    00001100
  // 243 =   11110011
  //Ausgabe:

  //==================== Left Shift/Right Shift ====================
  printf("\nLeft Shift/Right Shift: \n");
  PrintBinary(a);
  c = a <<=1;//Alles eins nach links verschoben
  PrintBinary(c);
  c = a >>=2;//Alles *zwei* nach rechts verschoben
  PrintBinary(c);
  //Ausgabe:
  // 12 =    00001100
  // 24 =    00011000
  // 6 =     00000110

  //==================== Bit setzen ====================
  printf("\nBit setzen: \n");
  PrintBinary(a);
  c = a;
  c |= 1 <<7;//Bit 7 setzen
  PrintBinary(c);
  c |= 1 <<5;//Bit 5 auch noch setzen
  PrintBinary(c);
  //Ausgabe:
  // 6 =     00000110
  // 134 =   10000110
  // 166 =   10100110

  //==================== Bit löschen ====================
  printf("\nBit loeschen: \n");
  PrintBinary(a);
  c = a;
  c &= ~(1<<1); //Bit 1 löschen
  PrintBinary(c);
  c &= ~(1<<2); //Bit 2 auch noch löschen
  PrintBinary(c);
  //Ausgabe:
  // 6 =     00000110
  // 134 =   10000110
  // 166 =   10100110

  //==================== Bit invertieren ====================
  printf("\nBit invertieren: \n");
  PrintBinary(a);
  c = a;
  c ^= (1<<4); //Bit 4 invertieren
  PrintBinary(c);
  c ^= (1<<2); //Bit 2 auch noch invertieren
  PrintBinary(c);
  //Ausgabe:
  // 6 =     00000110
  // 22 =    00010110
  // 18 =    00010010

  //==================== Bit abfragen ====================
  printf("\nBit abfragen: \n");
  PrintBinary(a);
  if (a & (1<<4)){
    printf("Bit 4 ist auf 1 gesetzt\n");
  } else{
    printf("Bit 4 ist auf 0 gesetzt\n");
  }

  if (a & (1<<2)){
    printf("Bit 2 ist auf 1 gesetzt\n");
  } else{
    printf("Bit 2 ist auf 0 gesetzt\n");
  }
  //Ausgabe:
  // 6 =     00000110
  // Bit 4 ist auf 0 gesetzt
  // Bit 2 ist auf 1 gesetzt

}

void PrintBinary(int n){
  if (n < 0){
    n += 256;
  }
  printf("%d = \t", n);
  int numberOfBits = 8;
	int bits[numberOfBits];
	int counter = 0;
  for (int i = 0; i < numberOfBits; i++){
    	if(n&1)
    		bits[counter] = 1;
    	else
    		bits[counter] = 0;
    	n>>=1;
    	counter++;
  }
	for(int i = counter-1; i>=0; i--){
		printf("%d", bits[i]);
	}
	printf("\n");
}
