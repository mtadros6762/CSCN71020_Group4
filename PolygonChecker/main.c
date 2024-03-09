#define _CRT_SECURE_NO_WARNINGS
#define TRIANGLEMAX 3
#define RECTANGLEMAX 4

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // Added for exit()
#include "rectangleSolver.h"
#include "main.h"
#include "triangleSolver.h"
#include "inputValidation.h"

int main() {
    bool continueProgram = true;
    while (continueProgram) {
        printWelcome();

        int shapeChoice = printShapeMenu();

        switch (shapeChoice)
        {
        case 1:
            printf("Triangle selected.\n");
            int triangleSides[3] = { 0, 0, 0 };
            int* triangleSidesPtr = getTriangleSides(triangleSides);
            char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
            printf("%s\n", result);
            break;
        case 2:									
            printf("Rectangle selected.\n");
            Points* Coordinates = (Points*)malloc(RECTANGLEMAX * sizeof(Points));
            if (Coordinates == NULL) {
                fprintf(stderr, "Memory allocation issues\n");
                exit(1);
            }
            getRectanglePoints(Coordinates);
            
            int Dist_AB = calculateDistance(Coordinates[0], Coordinates[1]);
            int Dist_BC = calculateDistance(Coordinates[1], Coordinates[2]);
            int Dist_CD = calculateDistance(Coordinates[2], Coordinates[3]);
            int Dist_DA = calculateDistance(Coordinates[3], Coordinates[0]);

            float Slope_AC = calculateSlope(Coordinates[0], Coordinates[2]);
            float Slope_BD = calculateSlope(Coordinates[1], Coordinates[3]);

            float angleAB = calculateAngle(Coordinates[0], Coordinates[1]);
            float angleBC = calculateAngle(Coordinates[1], Coordinates[2]);
            float angleCD = calculateAngle(Coordinates[2], Coordinates[3]);
            float angleDA = calculateAngle(Coordinates[3], Coordinates[0]);

            if (((Slope_AC + Slope_BD) == SLOPE_SUM) && (Dist_AB == Dist_CD) &&
                ((int)angleAB % RIGHT_ANGLE == MIN_VALUE) && ((int)angleBC % RIGHT_ANGLE == MIN_VALUE) &&
                ((int)angleCD % RIGHT_ANGLE == MIN_VALUE) && ((int)angleDA % RIGHT_ANGLE == MIN_VALUE)) {
                
                printf("\nIt's a Valid Rectangle\n");
                int Rectangle_Perimeter = 2 * (Dist_AB + Dist_BC);
                int Rectangle_Area = Dist_AB * Dist_BC;
                printf("Area of Rectangle = %d\n", Rectangle_Area);
                printf("Perimeter of Rectangle = %d \n", Rectangle_Perimeter);
            }
            else 
            {
                printf("Not a Valid Rectangle\n");
            }
            free(Coordinates);
            break;
        case 0:
            continueProgram = false;
            break;
        default:
            printf("Invalid value entered.\n");
            break;
        }
    }
    return 0;
}

void printWelcome() {
    printf("\n");
    printf(" **********************\n");
    printf("**     Welcome to     **\n");
    printf("**   Polygon Checker  **\n");
    printf(" **********************\n");
}

int printShapeMenu() {
    printf("1. Triangle\n");
    printf("2. Rectangle\n"); // Changed to include rectangle option
    printf("0. Exit\n");

    int shapeChoice;

    printf("Enter number: ");
    scanf("%d", &shapeChoice);

    return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
    printf("Enter the three sides of the triangle: ");
    for (int index = 0; index < TRIANGLEMAX; index++)
    {
        scanf("%d", &triangleSides[index]);
    }
    return triangleSides;
}
