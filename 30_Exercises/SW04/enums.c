#include <stdio.h>
#include <stdlib.h>

typedef enum{
	einfraenkler = 1,
	zweifraenkler = 2,
	fuenfliber = 5,
} SwissCoin;

typedef enum{
	nickle = 5,
	dime = 10,
	quater = 25
} USAcoin;



int main(int argc, char* argv[]){
	SwissCoin chCoin = nickle;
	USAcoin usCoin = nickle;
	
	printf("%d, %d", chCoin, usCoin);	
	return 0;
}

