
#include <stdio.h>

int main( int argc, char *argv[] )
{d
int myInt1 = 100, myInt2 = 40;
float myFloat = 0.0;

myFloat = myInt1/myInt2;
printf("1. My Float: %f\n", myFloat);

myFloat = (float)(myInt1/myInt2);
printf("2. My Float: %f\n", myFloat);

myFloat = (float)myInt1/myInt2;
printf("3. My Float: %f\n", myFloat);

myFloat = myInt1/(float)myInt2;
printf("4. My Float: %f\n", myFloat);

return 0;
}
