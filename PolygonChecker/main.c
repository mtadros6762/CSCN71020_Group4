#include <stdio.h>
#include <stdbool.h>
#include"rectangleSolver.h"
#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 2:									//created rectangle switch case
			printf("Rectangle selected.\n");
			/*Dynamically allocating memory to store points for the rectangle and also defining Coordinates as a Points*/
			Points* Coordinates = (Points*)malloc(MAX_POINTS * sizeof(Points));
			if (Coordinates == NULL) {
				fprintf(stderr, "Memory allocation issues\n");
				exit(1);
			}
			/*Inputting the Coordinates defined as Points struct*/
			getRectanglePoints(Coordinates);
			
			/*We need 3 things to determine the validity of a rectangle
	
			1: The Distance between points.
			2: The slopes of it's diagonals.
			3: Prove each angle is approximately equal to 90 
			********If all are true then the quadlateral is a rectangle*****
			
			*/

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
				
				/*Output when all are TRUE*/
				printf("\nIt's a Valid Rectangle\n");
				/*Finding the Perimeter of the Rectangle and Area of Rectangle*/
				int Rectangle_Perimeter = POWER_2 * (Dist_AB + Dist_BC);
				int Rectangle_Area = Dist_AB * Dist_BC;
				printf("Area of Rectangle = %d\n", Rectangle_Area);
				printf("Perimeter of Rectangle = %d \n", Rectangle_Perimeter);
			}
			else 
			{
				/*Output when FALSE*/
				printf("Not a Valid Rectangle\n");
			}
			/*Deallocating the memory cause honestly I have no idea but steve said it's a good practise*/
			free(Coordinates);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}