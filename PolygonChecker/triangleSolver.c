#define _CRT_SECURE_NO_WARNINGS 
#include "main.h"
#include "triangleSolver.h"

//group4 - cscn71020 - triangle solver implementation

/*Function to get triangle sides input and validate input*/
int* getTriangleSides(int* triangleSides) {
	char* sideNames[MAXSIDES] = { "first", "second", "third" };

	for (int i = 0; i < MAXSIDES; i++)
	{
		int input = 0;
		printf("Enter the %s side of the triangle:\n", sideNames[i]);
		while (scanf("%d", &input) != 1) 
		{
			printf("Invalid input. Please enter an integer for the %s side of the triangle:\n", sideNames[i]);
			//Clear the input buffer
			while (getchar() != '\n');
		}
		//Store input into array
		triangleSides[i] = input; 
	}
	return triangleSides;
}

/*Function to define a valid triangle using the triangle inequality theorem*/
bool validTriangle(int side1, int side2, int side3) {
	
	if ((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1))
	{
		//if the triangle is valid return true
		return true;
	}
	//if the triangle is invalid return false
	return false;
}

//Function to analyze sides from input and determine if it is a triangle,
//if so, determines what type and calculates the angles using a separate function
char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	
	//added validTriangle function to analyzeTriangle function
	if ((validTriangle(side1, side2, side3) == false) || (side1 <= 0 || side2 <= 0 || side3 <= 0))
	{
		result = "Not a triangle";
		printf("\n%s\n", result);
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
		printf("\n%s\n", result);
		anglesOfTriangle(side1, side2, side3);
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2) ||
		(side2 == side3 && side2 != side1))
	{
		result = "Isosceles triangle";
		printf("\n%s\n", result);
		anglesOfTriangle(side1, side2, side3);
	}
	else if((side1 != side2 && side1 != side3 && side2 != side3)) {
		result = "Scalene triangle";
		printf("\n%s\n", result);
		anglesOfTriangle(side1, side2, side3);
	}

	return result;
}

/*Function to calculate the angles of a triangle*/
double* calculateTriAngles(int side1, int side2, int side3) {
	//Dynamically allocate memory for the angles array
	double* angles = (double*)malloc(MAXSIDES * sizeof(double));
	if (angles == NULL) {
		fprintf(stderr, "Memory allocation issues\n");
		exit(1);
	}

	//Perform angle calculations
	angles[0] = acos(((side2 * side2) + (side3 * side3) - (side1 * side1)) / (COSDENOMINATOR * side2 * side3)) * MAX_TRI_ANGLES / PI;
	angles[1] = acos(((side1 * side1) + (side3 * side3) - (side2 * side2)) / (COSDENOMINATOR * side1 * side3)) * MAX_TRI_ANGLES / PI;
	angles[2] = acos(((side1 * side1) + (side2 * side2) - (side3 * side3)) / (COSDENOMINATOR * side1 * side2)) * MAX_TRI_ANGLES / PI;

	return angles;
}

/*Function to print angles*/
void anglesOfTriangle(int side1, int side2, int side3) {
	//Calculate the angles of the triangle
	double* angles = calculateTriAngles(side1, side2, side3);

	// Print result
	printf("\nThe angles of the triangle are: %.2lf degrees, %.2lf degrees, and %.2lf degrees.\n", angles[0], angles[1], angles[2]);

	//Free the dynamically allocated memory
	free(angles);
}