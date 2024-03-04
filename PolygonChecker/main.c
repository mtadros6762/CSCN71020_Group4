#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

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
			printf("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf("%s\n", result);
			break;
		case 2:									//created rectangle switch case
			printf("Rectangle selected.\n");


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
	printf("\n");
	printf(" **********************\n");
	printf("**     Welcome to     **\n");
	printf("**   Polygon Checker  **\n");
	printf(" **********************\n");
}

int printShapeMenu() {
	printf("1. Triangle\n");
	printf("2. Rectangle\n");		//added rectangle option to menu 
	printf("0. Exit\n");

	int shapeChoice;

	printf("Enter number: ");
	scanf("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &triangleSides[i]);
	}
	return triangleSides;
}