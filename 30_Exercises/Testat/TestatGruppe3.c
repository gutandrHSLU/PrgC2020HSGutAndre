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
void PrintTitle(int numberOfTask);

//Funktion für Aufg. 1

//Funktion für Aufg. 2

//Funktion für Aufg. 3

//Funktion für Aufg. 4
void CalcTimeOfPressureIncrease(struct DataPoint dataPoints[], int numberOfPoints);
int ArraySum(int points[], int arrayLength);
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

  //==================== Aufgabe 1 ====================
  PrintTitle(1);

  //==================== Aufgabe 2 ====================
  PrintTitle(2);

  //==================== Aufgabe 3 ====================
  PrintTitle(3);

  //==================== Aufgabe 4 ====================
  PrintTitle(4);
  CalcTimeOfPressureIncrease(myDataPoints, numberOfPoints);

  //==================== Aufgabe 5 ====================
  PrintTitle(5);

  //PrintDataPoints(myDataPoints, numberOfPoints);

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

void PrintTitle(int numberOfTask){
  int n = numberOfTask;
  printf("\n");
  for (int i = 0; i < 30; i++){
    printf("=");
  }
  printf(" Aufgabe %d ", n);
  for (int i = 0; i < 30; i++){
    printf("=");
  }
  printf("\n");
  return;
}


//==================== Funktion für Aufg. 1 ====================

//==================== Funktion für Aufg. 2 ====================

//==================== Funktion für Aufg. 3 ====================

//==================== Funktion für Aufg. 4 ====================
//Calculates the average change in pressure over x Datapoints. The first time a threshold is met, the time is printed
void CalcTimeOfPressureIncrease(struct DataPoint dataPoints[], int numberOfPoints){
  int numberOfDataPoints = 15;
  int pressurePoints[numberOfDataPoints];
  memset(pressurePoints, 0, sizeof(pressurePoints)); //Sets all elements of the array to 0
  int avgGradientThreshold = 1500; //[Pa / 0.25s] if this thershold is met, the time is printed
  for(int i = 0; i < numberOfPoints; i++){
    pressurePoints[i%numberOfDataPoints] = dataPoints[i + 1].pressure - dataPoints[i].pressure; //Calculates the pressure difference and adds it to the pressurePoints array
    int sum = ArraySum(pressurePoints, numberOfDataPoints); //Calculates the sum of the pressurePoint array
    if (sum / numberOfDataPoints > avgGradientThreshold){
      printf("The pressure started to increase at: ");
      PrintTime(dataPoints[i-numberOfDataPoints].timeStamp);
      break;
    }
  }
  return;
}
//Calculates the sum of the array
int ArraySum(int points[], int arrayLength){
  int sum = 0;
  for (int i = 0; i < arrayLength; i++){
    sum += points[i];
  }
  return sum;
}

//==================== Funktion für Aufg. 5 ====================
