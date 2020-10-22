#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Struktur eines "Datenpunktes"
struct DataPoint{
  long long timeStamp;
  int pressure;
  char systemState;
  char alarmState;
}__attribute__((packed));

//Initialisierung der Funktionen
void PrintDataPoints(struct DataPoint dataPoints[], int numberOfPoints);
void PrintTime(long long timeStamp);

//Funktion für Aufg. 1

//Funktion für Aufg. 2

//Funktion für Aufg. 3

//Funktion für Aufg. 4
void CalcTimeOfPressureIncrease(struct DataPoint dataPoints[], int numberOfPoints);
int arraySum(int points[], int arrayLength);
//Funktion für Aufg. 5


int main(int argc, char *argv[]){
  //Öffnet das File und initialisiert einen Pointer:
	FILE *fid = fopen("pressureSpike.bin", "rb");

  //Sucht das Ende des Files und berechnet die Anzahl Datenpunkte:
  int numberOfPoints;
  fseek (fid , 0 , SEEK_END);
  numberOfPoints = ftell (fid) / sizeof(struct DataPoint);
  rewind (fid);

  //Array mit DataPoints wird generiert
  struct DataPoint myDataPoints[numberOfPoints];

  //Daten werden in das Array mit den DataPoints "abgefüllt":
  fread(myDataPoints, sizeof(struct DataPoint), numberOfPoints, fid);

  //Aufgabe 1

  //Aufgabe 2

  //Aufgabe 3

  //Aufgabe 4
  PrintDataPoints(myDataPoints, numberOfPoints);
  CalcTimeOfPressureIncrease(myDataPoints, numberOfPoints);

  //Aufgabe 5

  //PrintDataPoints(myDataPoints, numberOfPoints);
  //printTime(myDataPoints[0].timeStamp);
  //
  return 0;
}

//Implementierung der Funktionen
void PrintDataPoints(struct DataPoint dataPoints[], int numberOfPoints){
  for(int i = 0; i < numberOfPoints; i+= 1){
    printf("%d %lld \t%d \t%d \t%d \n", i, dataPoints[i].timeStamp, dataPoints[i].pressure, dataPoints[i].systemState, dataPoints[i].alarmState);
  }
  return;
}

void PrintTime(long long timeStamp){
  time_t rawtime = timeStamp / 1000;
  printf("%s", ctime(&rawtime));
  return;
}


//Funktion für Aufg. 1

//Funktion für Aufg. 2

//Funktion für Aufg. 3

//Funktion für Aufg. 4
//Calculates the average change in Pressure over x Datapoints. The first time a threshold is met, the time is being printet
void CalcTimeOfPressureIncrease(struct DataPoint dataPoints[], int numberOfPoints){
  int numberOfDataPoints = 20;
  int pressurePoints[numberOfDataPoints];
  memset(pressurePoints, 0, sizeof(pressurePoints));
  int avgPressureDiffThreshold = 400; //[Pa]
  for(int i = 0; i < numberOfPoints - 1; i++){
    pressurePoints[i%5] = dataPoints[i + 1].pressure - dataPoints[i].pressure;
    int sum = arraySum(pressurePoints, numberOfDataPoints);
    if (sum / numberOfDataPoints > avgPressureDiffThreshold){
      printf("The pressure started to increase at: ");
      printf("%lld \n", dataPoints[i-numberOfDataPoints].timeStamp);
      PrintTime(dataPoints[i-numberOfDataPoints].timeStamp);
      break;
    }
  }
  return;
}

int arraySum(int points[], int arrayLength){
  int sum = 0;
  for (int i = 0; i < arrayLength; i++){
    sum += points[i];
  }
  return sum;
}

//Funktion für Aufg. 5
