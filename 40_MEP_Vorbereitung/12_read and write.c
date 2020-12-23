#include <stdio.h>







// Funktioniert (noch) nicht!!!!







void main(){
  //========== Daten Lesen ==========
  int myData[5]; //Generiert ein leeres Array
  char c[20];
  //generiert ein Pointer, welcher zum File zeigt
  //Öffnet das File data.txt im "read" modus
  FILE *pointerToData = fopen("12_data.txt", "r");
  fread(myData, sizeof(int), 5, pointerToData);

  // fscanf(pointerToData, "%[^\n]", c);
  // printf("Data from the file: %s\n", c);
  // fclose(pointerToData);
  for (int i = 0; i < 5; i++){
    printf("%d\n", myData[i]);
  }
}
