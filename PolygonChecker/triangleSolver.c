#define _CRT_SECURE_NO_WARNINGS 
#include "main.h"
#include "triangleSolver.h"

//group4 - cscn71020 - triangle solver implementation

//This function gets each triangle side individually and stores input into an array
//while simultaneously validating user input
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

//This function defines a valid triangle using the triangle inequality theorem
bool validTriangle(int side1, int side2, int side3) {
	
	if ((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1))
	{
		//if the triangle is valid return true
		return true;
	}
	//if the triangle is invalid return false
	return false;
}

//Function to analyze sides from input and determine if it is a triangle
//if so, determines what type and calculates the angles
void analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	
	//added validTriangle function to analyzeTriangle function
	if ((validTriangle(side1, side2, side3) == false) || (side1 <= 0 || side2 <= 0 || side3 <= 0))
	{
		result = "Not a triangle";
		printf("\n%s\n", result);
	}
	else if (side1 == side2 && side1 == side3) {
		result= "Equilateral triangle";
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
}

/*Function to calculate the angles of a triangle*/
void calculateTri_Angles(int side1, int side2, int side3, double* angle1, double* angle2, double* angle3) {
	*angle1 = acos(((side2*side2) + (side3*side3) - (side1*side1)) / (COSDENOMINATOR * side2 * side3));
	*angle2 = acos(((side1*side1) + (side3*side3) - (side2*side2)) / (COSDENOMINATOR * side1 * side3));
	//*angle3 = MAX_TRI_ANGLES - *angle2 - *angle1;
	*angle3 = acos(((side1*side1) + (side2*side2) - (side3*side3)) / (COSDENOMINATOR * side1 * side2));
}

/*Function to convert angles to degrees and print*/
void anglesOfTriangle(int side1, int side2, int side3) {
	double angle1 = 0;
	double angle2 = 0;
	double angle3 = 0;
	//Calculate the angles of the triangle
	calculateTri_Angles(side1, side2, side3, &angle1, &angle2, &angle3);

	//Convert angles from radians to degrees
	angle1 = angle1 * MAX_TRI_ANGLES / PI;
	angle2 = angle2 * MAX_TRI_ANGLES / PI;
	angle3 = angle3 * MAX_TRI_ANGLES / PI;

	//Print result
	printf("\nThe angles of the triangle are: %.2lf degrees, %.2lf degrees, and %.2lf degrees.\n", angle1, angle2, angle3);
}