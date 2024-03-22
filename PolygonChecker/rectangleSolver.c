#include "main.h"
#include "rectangleSolver.h"

//group4 - cscn71020 - rectangle solver implementation

/*Function to get the input for Coordinates*/
POINTS* getRectanglePoints(POINTS* coordinates) {
    printf("Enter the 4 points of the rectangle (x, y):\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // flushing input buffer before entering loop
    for (int i = 0; i < MAX_POINTS; i++) {
        while (true) {
            printf("Enter coordinates for point %d: ", i + 1);
            char input[100];
            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("Error reading input. Please try again.\n");
                continue;
            }
            if (sscanf(input, "%d %d", &coordinates[i].x, &coordinates[i].y) == 2) {
                break;
            }
            printf("Invalid input. Please enter two integers separated by a space.\n");
        }
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

#include <stdbool.h>
#include "rectangleSolver.h"

 bool isRectangle(POINTS* Coordinates) {
    /*Finding the distance between each point using the distance formula (A to B , B to C. etc)  */
    int Dist_AB = calculateDistance(Coordinates[0], Coordinates[1]);
    int Dist_BC = calculateDistance(Coordinates[1], Coordinates[2]);
    int Dist_CD = calculateDistance(Coordinates[2], Coordinates[3]);
    int Dist_DA = calculateDistance(Coordinates[3], Coordinates[0]);

    /*Finding the slopes of the diagonals*/
    float Slope_AC = calculateSlope(Coordinates[0], Coordinates[2]);
    float Slope_BD = calculateSlope(Coordinates[1], Coordinates[3]);

    /*Finding the angles of each point*/
    float angleAB = calculateAngle(Coordinates[0], Coordinates[1]);
    float angleBC = calculateAngle(Coordinates[1], Coordinates[2]);
    float angleCD = calculateAngle(Coordinates[2], Coordinates[3]);
    float angleDA = calculateAngle(Coordinates[3], Coordinates[0]);

    /*Approximating so that all the angles are in between 0 and 360 . This just makes it easier to compare the angles*/
    if (angleAB < MIN_VALUE) angleAB += MAX_ANGLE;
    if (angleBC < MIN_VALUE) angleBC += MAX_ANGLE;
    if (angleCD < MIN_VALUE) angleCD += MAX_ANGLE;
    if (angleDA < MIN_VALUE) angleDA += MAX_ANGLE;

    /*Comparison of all 3 points for the validity of the rectangle*/
    if (((Slope_AC + Slope_BD) == SLOPE_SUM) && (Dist_AB == Dist_CD) &&
        ((int)angleAB % RIGHT_ANGLE == MIN_VALUE) && ((int)angleBC % RIGHT_ANGLE == MIN_VALUE) &&
        ((int)angleCD % RIGHT_ANGLE == MIN_VALUE) && ((int)angleDA % RIGHT_ANGLE == MIN_VALUE)) {
        return true; // All conditions met, it's a rectangle
    }
    else {
        return false; // Not a rectangle
    }
}




