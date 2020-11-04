#include <stdio.h>
#include <stdlib.h>

//Structure of a DataPoint
struct DataPoint{
  long long timestamp;
  unsigned int pressure;
  unsigned char systemState;
  unsigned char alarmState;
  unsigned char pump2;
  unsigned char pump1;
  unsigned char valveOut;
  unsigned char valveIn;
};



int main(int argc, char *argv[]){
	// for reading from binary file
	unsigned char *pCurrentBufferPosition = NULL;
	FILE *fid = fopen("pressureSpike.bin", "rb");
	FILE *fout	= fopen("pressureSpike.csv", "w");

	// check if file opening worked
	if( fid != NULL && fout != NULL)

	{
		// prepare a buffer of correct length
		const int BYTES_IN_LINE = 14;
		unsigned char lineBuffer[BYTES_IN_LINE];

		// print header to file
		fprintf(fout, "time stamp, pressure, Pump 2, Pump 1, Valve Out, Valve In, Alarm\n");

    struct DataPoint myDataPoint;

		while( fread(lineBuffer,BYTES_IN_LINE, 1, fid) )
		{
		 	myDataPoint.timestamp = ((struct DataPoint*)lineBuffer) ->timestamp;
			myDataPoint.pressure = ((struct DataPoint*)lineBuffer) ->pressure;

			myDataPoint.systemState = ((struct DataPoint*)lineBuffer) ->systemState;
			myDataPoint.valveIn = (myDataPoint.systemState & 1 );
			myDataPoint.valveOut = (myDataPoint.systemState & (1 << 1)) >> 1;
			myDataPoint.pump1 = (myDataPoint.systemState & (1 << 2)) >> 2;
			myDataPoint.pump2 = (myDataPoint.systemState & (1 << 3)) >> 3;

			myDataPoint.alarmState = ((struct DataPoint*)lineBuffer) ->alarmState;


			printf("%lld, %d, %d, %d, %d, %d, %d\n", myDataPoint.timestamp, myDataPoint.pressure,\
					myDataPoint.pump2, myDataPoint.pump1, myDataPoint.valveOut, myDataPoint.valveIn, myDataPoint.alarmState);
			fprintf(fout, "%lld, %d, %d, %d, %d, %d, %d\n", myDataPoint.timestamp, myDataPoint.pressure,\
					myDataPoint.pump2, myDataPoint.pump1, myDataPoint.valveOut, myDataPoint.valveIn, myDataPoint.alarmState);
		}
		fclose(fid);
		fclose(fout);
	}
	else
	{
		printf("Cannot open either source or target file.\n");
	}
	return 0;
}
