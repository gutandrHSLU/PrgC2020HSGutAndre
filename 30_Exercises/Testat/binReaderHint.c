#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	long long timestamp = 0;

	FILE *fid = fopen("pressureSpike.bin", "rb");

	if( fid != NULL )
	{
		fread(&timestamp, sizeof(long long), 1, fid);
		printf("time stamp: %lld\n", timestamp);
	}
	return 0;
}
