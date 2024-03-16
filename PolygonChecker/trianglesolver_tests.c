#include "main.h"

//group4 - cscn71020 - triangle solver tests implementation

/*Test the getTriangleSides function and input validation*/
void testGetTriangleSides() {
	int testSides[MAXSIDES];
	int expectedSides[MAXSIDES] = { 3, 6, 6 };

	//Call function and pass in test data
	getTriangleSides(testSides);

	bool result = true;

	for (int i = 0; i < MAXSIDES; i++) {
		//check each side, if there is one mismatch set result flag to false and break loop
		if (expectedSides[i] != testSides[i]) {
			result = false;
			break;
		}
	}
	//Print test result based on the value of result flag
	if (result == true)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");	//at least one mismatch
	}
}

/*Test the validTriangle function using invalid side lengths*/
void testValidTriangle() {
	int side1 = 1;
	int side2 = 2;
	int side3 = 3;
	bool expected = false;
	bool actual = validTriangle(side1, side2, side3);

	//Print test result
	if (actual == expected)
	{
		printf("PASS\n");
	}
	else 
	{
		printf("FAIL\n");
	}
}

/*Test the analyzeTriangle function using an isosceles triangle*/
void testAnalyzeTriangle() {
	int side1 = 1;
	int side2 = 2;
	int side3 = 2;
	char* expected = "Isosceles triangle";
	char* actual = analyzeTriangle(side1, side2, side3);

	//Print test result
	if (actual == expected) 
	{
		printf("PASS\n"); 
	}
	else
	{
		printf("FAIL\n"); 
	}
}

/*Test the calculateTriAngles function using an equilateral triangle*/
void testCalculateTriAngles() {
	int side1 = 2;
	int side2 = 2;
	int side3 = 2;
	double expected[MAXSIDES] = {60.00, 60.00, 60.00};
	double* actual = calculateTriAngles(side1, side2, side3);

	//Print test result
	if (actual == expected)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
}