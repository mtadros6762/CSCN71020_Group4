#include "main.h"
#include "rectangleSolver.h"

//group4 - cscn71020 - rectangle solver implementation

/*Function to get the input for Coordinates*/
POINTS* getRectanglePoints(POINTS* coordinates) {
	printf_s("Enter the 4 points of the rectangle: \n");
    for (int i = 0; i < MAX_POINTS; i++)
	{
		scanf_s("%d %d", &coordinates[i].x, &coordinates[i].y);
	}
	return coordinates;
}
/*Function to the distance by implementing the distance formula*/
int calculateDistance(POINTS p1, POINTS p2) {
    return sqrt(pow((p2.x - p1.x), POWER_2) + pow((p2.y - p1.y), POWER_2));
}

/*Function to get the slope of diagonals using the slope formula*/
float calculateSlope(POINTS p1, POINTS p2) {
    if (p2.x - p1.x != 0) {
        return (float)(p2.y - p1.y) / (p2.x - p1.x);
    }
    else {
        /*If the denominator is 0 then it get defined Infinity*/
        return INFINITY;
    }
}
/*Function to calculate the angles of each corner*/
float calculateAngle(POINTS p1, POINTS p2) {
    /*atan2 basically calulate the angles in radians*/
    return atan2(p2.y - p1.y, p2.x - p1.x) * STRAIGHT_ANGLE / M_PI;
}

   