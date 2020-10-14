#include <stdio.h>

typedef struct {
	int x;
	int y;
} Point2D;

typedef struct  {
	Point2D pointTopLeft;
	Point2D pointBottomRight;
	double area;
}Rectangle;

#define NUM_RECTANGLES 10
Rectangle myRectangles[NUM_RECTANGLES];

void PrintRectangleArray(Rectangle myRectangles[], int ArrayLength);
void PrintRectangle(Rectangle myRectangle);
double ComputeRectangleArea(Rectangle myRectangle);

int main(int argc, char* argv[]){
	//Init random number generator
	srand(42);

	//init rectangles with random numbers
	for (int i = 0; i < NUM_RECTANGLES; i++){
		myRectangles[i].pointTopLeft.x = rand() % 500 -250;
		myRectangles[i].pointTopLeft.y = rand() % 500 -250;

		myRectangles[i].pointBottomRight.x = myRectangles[i].pointTopLeft.x + rand() % 100 +1;
		myRectangles[i].pointBottomRight.y = myRectangles[i].pointTopLeft.y - rand() % 100 +1;

		myRectangles[i].area = ComputeRectangleArea(myRectangles[i]);

	}
	PrintRectangleArray(myRectangles, NUM_RECTANGLES);
	return 0;
}

void PrintRectangleArray(Rectangle myRectangles[], int ArrayLength){
	for( int i = 0; i< NUM_RECTANGLES; i++){
		PrintRectangle(myRectangles[i]);
	}
}
void PrintRectangle(Rectangle myRectangle){
	printf("%d\t%d\t  \t%d\t%d\t \t%f\n", \
		myRectangle.pointTopLeft.x, myRectangle.pointTopLeft.y, \
		myRectangle.pointBottomRight.x, myRectangle.pointBottomRight.y, \
		myRectangle.area);
}

double ComputeRectangleArea(Rectangle myRectangle){
	double retValue = 0.0;
	Point2D p1 = myRectangle.pointTopLeft;
	Point2D p2 = myRectangle.pointBottomRight;
	int dx = (p2.x - p1.x);
	int dy = (p1.y - p2.y);
	retValue = dx * dy;
	return retValue;
}
