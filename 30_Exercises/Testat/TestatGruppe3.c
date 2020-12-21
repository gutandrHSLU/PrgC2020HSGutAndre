#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Structure of a DataPoint
struct DataPoint{
  long long timeStamp;
  int pressure;
  char systemState;
  char alarmState;
}__attribute__((packed));

//Initialisierung der allgemeinen Funktionen
void PrintDataPoints(struct DataPoint dataPoints[], int numberOfPoints);
void PrintTime(long long timeStamp);
void PrintTitle(int numberOfTask);
void WriteDataTotxt(struct DataPoint dataPoints[], int numberOfPoints, int* pointer);
int* IntToBinaryArray(int num, int* bitsArray);

//Funktion für Aufg. 1

//Funktion für Aufg. 2
void OldPoints(struct DataPoint array[]);
int PrintBinary (char State);

//Funktion für Aufg. 3
void Print250Bar(struct DataPoint dataPoints[], int numberOfPoints);
void PrintPressureOfExplosion(struct DataPoint dataPoints[], int numberOfPoints);

//Funktion für Aufg. 4
void CalcTimeOfPressureIncrease(struct DataPoint dataPoints[], int numberOfPoints);
int ArraySum(int points[], int arrayLength);

//Funktion für Aufg. 5
void PrintSystemstateChange(struct DataPoint dataPoints[], int numberOfPoints);



int main(int argc, char *argv[]){
	FILE *fid = fopen("pressureSpike.bin", "rb"); //Öffnet das bressureSpike.bin File und initialisiert einen Pointer:
  FILE *txtFileP; //Initialisiert den Pointer zum leeren .txt file
  txtFileP = fopen("pressureSpike.txt", "w"); //Öffnet das neue .txt file

  //Sucht das Ende des Files und berechnet die Anzahl Datenpunkte:
  int numberOfPoints;
  fseek (fid , 0 , SEEK_END);
  numberOfPoints = ftell (fid) / sizeof(struct DataPoint);
  rewind (fid); //Setzt den Pointer zurück (das glaube ich zumindest...)

  struct DataPoint myDataPoints[numberOfPoints];   //Array mit DataPoints wird generiert
  fread(myDataPoints, sizeof(struct DataPoint), numberOfPoints, fid); //Daten werden in das Array "myDataPoints" abgefüllt:

  WriteDataTotxt(myDataPoints, numberOfPoints, txtFileP); //Daten werden von "myDataPoints" in das .txt file geschriben
  fclose(txtFileP); //.txt file wird geschlossen

  //==================== Aufgabe 1 ====================
  PrintTitle(1);
  printf("First timestamp: ");
  PrintTime(myDataPoints[0].timeStamp);
  printf("Last timestamp: ");
  PrintTime(myDataPoints[numberOfPoints - 1].timeStamp);
  //==================== Aufgabe 2 ====================
  PrintTitle(2);
  OldPoints(myDataPoints);
  //==================== Aufgabe 3 ====================
  PrintTitle(3);
  Print250Bar(myDataPoints, numberOfPoints);
  PrintPressureOfExplosion(myDataPoints, numberOfPoints);
  //==================== Aufgabe 4 ====================
  PrintTitle(4);
  CalcTimeOfPressureIncrease(myDataPoints, numberOfPoints);
  //==================== Aufgabe 5 ====================
  PrintTitle(5);
  PrintSystemstateChange(myDataPoints, numberOfPoints);

  return 0;
}

//Implementierung der Funktionen

//==============================================================
//==================== Funktion für Aufg. 2 ====================
//==============================================================
void OldPoints(struct DataPoint array[]){
	time_t rawtimeStart = array[0].timeStamp / 1000;
	time_t rawtimeEnd = array[299].timeStamp / 1000;

	printf("Starting time: \t\t %s", ctime(&rawtimeStart));
	printf("End time: \t\t %s\n", ctime(&rawtimeEnd));
	long long pressure=0;
	char systemState=0;
	char alarmState=1;

	for(int i = 0; i < 299; i+= 1){
		pressure += array[i].pressure;
	}
 	float pressureAvg= (pressure/300)/(100000);

 	printf("Average pressure: \t %f bar\n\n", pressureAvg);

 	for(int i = 0; i < 299; i+= 1){
 		if (systemState!=array[i].systemState){
 		time_t rawtimeChange = array[i].timeStamp / 1000;
		printf("Systemstate: \t\t %d\n", PrintBinary(array[i].systemState));
		printf("Time of change: \t %s\n", ctime(&rawtimeChange));
		systemState=array[i].systemState;
		}
	}

	for(int i = 0; i < 299; i+= 1){
 		if (alarmState!=array[i].alarmState){
 		time_t rawtimeChangeAlarm = array[i].timeStamp / 1000;
		printf("Alarmstate: \t\t %d\n", array[i].alarmState);
		printf("Time of change: \t %s", ctime(&rawtimeChangeAlarm));
		alarmState=array[i].alarmState;
		}
	 }
 	return;
}

int PrintBinary (char input){
	int binary=0;
	int rem=0;
	int i=1;

	int n=input;

	while (n !=0){
		rem=n%2;
		n= n/2;
		binary= binary+rem*i;
		i=i*10;
	}
	return binary;
}

//==============================================================
//==================== Funktion für Aufg. 3 ====================
//==============================================================
void Print250Bar(struct DataPoint dataPoints[], int numberOfPoints){
	int toSearch = 25000000;
	int found;
	int i;
	for(i = 0; i < numberOfPoints; i++){
		if(dataPoints[i].pressure >= toSearch){
			found = 1;
			break;
			}
		}
		if(found == 1){
			printf("The pressure rose to over 250 bar at ");
      PrintTime(dataPoints[i].timeStamp);
		}else{
			printf("the pressure never rose above 250 bar");
		}
  return;
}

void PrintPressureOfExplosion(struct DataPoint dataPoints[], int numberOfPoints){
  printf("The pressure at which the signal breaks off is %d [Pa]", dataPoints[numberOfPoints - 1].pressure);
  printf("\n");
}

//==============================================================
//==================== Funktion für Aufg. 4 ====================
//==============================================================
//Calculates the average change in pressure over x Datapoints. The first time the avgGradient threshold is met, the time of the current dataPoint is printed
void CalcTimeOfPressureIncrease(struct DataPoint dataPoints[], int numberOfPoints){
  int numberOfDataPoints = 15;
  int pressurePoints[numberOfDataPoints];
  memset(pressurePoints, 0, sizeof(pressurePoints)); //Sets all elements of the array to 0
  int avgGradientThreshold = 1500; //[Pa / 0.25s] if this thershold is met, the time is printed

  for(int i = 0; i < numberOfPoints; i++){
    pressurePoints[i % numberOfDataPoints] = dataPoints[i + 1].pressure - dataPoints[i].pressure; //Calculates the pressure difference and adds it to the pressurePoints array
    int sum = ArraySum(pressurePoints, numberOfDataPoints); //Calculates the sum of the pressurePoint array
    if (sum / numberOfDataPoints > avgGradientThreshold){
      printf("The pressure started to increase at ");
      PrintTime(dataPoints[i-numberOfDataPoints].timeStamp);
      break;
    }
  }
  return;
}

//Calculates the sum of an array
int ArraySum(int points[], int arrayLength){
  int sum = 0;
  for (int i = 0; i < arrayLength; i++){
    sum += points[i];
  }
  return sum;
}

//==============================================================
//==================== Funktion für Aufg. 5 ====================
//==============================================================
void PrintSystemstateChange(struct DataPoint dataPoints[], int numberOfPoints){
  char initialState = 0;
  for(int i = 0; i < numberOfPoints - 1; i++){
    if(dataPoints[i].alarmState != initialState){
      printf("The alarmstate changed from %d to %d at: ", initialState, dataPoints[i].alarmState);
      PrintTime(dataPoints[i].timeStamp);
      initialState = dataPoints[i].alarmState;
    }
  }
}

//==============================================================
//==================== Restliche Funktionen ====================
//==============================================================
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

void WriteDataTotxt(struct DataPoint dataPoints[], int numberOfPoints, int* pointer){
  for(int i = 0; i < numberOfPoints-1; i++){
    time_t rawtime = dataPoints[i].timeStamp / 1000;
    int bits[4];
    int* bitsP = IntToBinaryArray(dataPoints[i].systemState, &bits);
    fprintf (pointer, "%.24s; %d; %d; %d; %d; %d; %d; \n", ctime(&rawtime), dataPoints[i].pressure, bitsP[3], bitsP[2], bitsP[1], bitsP[0], dataPoints[i].alarmState);
  }
  return;
}

int* IntToBinaryArray(int num, int* bitsArray){
	int counter = 0;
	while(num){
		if(num&1)
			bitsArray[counter] = 1;
		else
			bitsArray[counter] = 0;
		num>>=1;
		counter++;
	}
	return bitsArray;
}
