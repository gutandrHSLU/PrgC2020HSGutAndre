//Dieses Programm funktioniert nicht wirklich!
//Es dient zur Erklärung.
#include <stdio.h>

void main(){
  //Folgendes soll in den FRAM geschrieben werden:
  long variable = 69;

  //Pointer deklarieren welcher zum FRAM zeigt: 0x1800 ist die Adresse des FRAMs
  long *pointerZuFRAM = (long*)0x1800;

  //FRAM freigeben:
  SYSCFG0 &= ~DFWP;

  //Information in FRAM schreiben:
  *pointerZuFRAM = variable; //Heisst: Schreibe 69 dort hin, wo der Pointer hin zeigt

  //FRAM wieder blockieren:
  SYSCFG0 |= DFWP;

  //Happy end:)
}
