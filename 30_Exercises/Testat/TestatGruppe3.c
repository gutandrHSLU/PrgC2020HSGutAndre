#include <stdio.h>
#include <stdlib.h>

//Struktur eines "Datenpunktes"
struct DataPoint{
  long long timeStamp;
  int pressure;
  char systemState;
  char alarmState;
}__attribute__((packed));

//Initialisierung der Funktionen
void PrintDataPoints(struct DataPoint array[], long numberOfPoints);

int main(int argc, char *argv[]){
  //Öffnet das File und initialisiert einen Pointer:
	FILE *fid = fopen("pressureSpike.bin", "rb");

  //Sucht das Ende des Files und berechnet die Anzahl Datenpunkte:
  long numberOfPoints;
  fseek (fid , 0 , SEEK_END);
  numberOfPoints = (ftell (fid)/sizeof(struct DataPoint));
  rewind (fid);

  //Array mit DataPoints wird generiert
  struct DataPoint myDataPoints[numberOfPoints];

  //Daten werden in das Array mit den DataPoints "abgefüllt":
  fread(myDataPoints, sizeof(struct DataPoint), numberOfPoints, fid);

  PrintDataPoints(myDataPoints, numberOfPoints);
  return 0;
}

//Implementierung der Funktionen
void PrintDataPoints(struct DataPoint array[], long numberOfPoints){
  for(int i = 0; i < numberOfPoints; i+= 1){
    printf("%lld \t%d \t%d \t%d \n", array[i].timeStamp, array[i].pressure, array[i].systemState, array[i].alarmState);
  }
}
