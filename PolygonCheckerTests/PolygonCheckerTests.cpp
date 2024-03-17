#include "pch.h"
#include "CppUnitTest.h"
#include"..\PolygonChecker\rectangleSolver.h"
#include "..\PolygonChecker\triangleSolver.h"

//extern "C" bool validTriangle(int side1, int side2, int side3);
//extern "C" char* analyzeTriangle(int side1, int side2, int side3);
//extern "C" double* calculateTriAngles(int side1, int side2, int side3);

//group4 - cscn71020 - tests

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{

	/*Triangle Solver Test Class - Types of Triangle*/
	TEST_CLASS(TypeOfTriangleTests)
	{
	public:

		TEST_METHOD(Test_validTriangle_invalid)
		{
            /*Arrange*/
            int side1 = 1;
            int side2 = 2;
            int side3 = 3;
            bool expected = false;  //function returns false when the triangle is invalid
            /*Act*/
            bool actual = validTriangle(side1, side2, side3);
            /*Assert*/
            Assert::AreSame(actual, expected);
		}

        TEST_METHOD(Test_validTriangle_valid) 
        {
            /*Arrange*/
            int side1 = 6;
            int side2 = 6;
            int side3 = 4;
            bool expected = true;  //function returns true when the triangle is valid
            /*Act*/
            bool actual = validTriangle(side1, side2, side3);
            /*Assert*/
            Assert::AreSame(actual, expected);
        }

        TEST_METHOD(Test_analyzeTriangles_NotATriangle)
        {
            /*Arrange*/
            int side1 = 1;
            int side2 = 2;
            int side3 = 3;
            char* expected = "Not a triangle";
            /*Act*/
            char* actual = analyzeTriangle(side1, side2, side3);
            /*Assert*/
            Assert::AreSame(actual, expected);
        }

        TEST_METHOD(Test_analyzeTriangles_Equilateral)
        {
            /*Arrange*/
            int side1 = 3;
            int side2 = 3;
            int side3 = 3;
            char* expected = "Equilateral triangle";
            /*Act*/
            char* actual = analyzeTriangle(side1, side2, side3);
            /*Assert*/
            Assert::AreSame(actual, expected);
        }

        TEST_METHOD(Test_analyzeTriangles_Isosceles)
        {
            /*Arrange*/
            int side1 = 5;
            int side2 = 5;
            int side3 = 7;
            char* expected = "Isosceles triangle";
            /*Act*/
            char* actual = analyzeTriangle(side1, side2, side3);
            /*Assert*/
            Assert::AreSame(actual, expected);
        }

        TEST_METHOD(Test_analyzeTriangles_Scalene)
        {
            /*Arrange*/
            int side1 = 5;
            int side2 = 4;
            int side3 = 3;
            char* expected = "Scalene triangle";
            /*Act*/
            char* actual = analyzeTriangle(side1, side2, side3);
            /*Assert*/
            Assert::AreSame(actual, expected);
        }
	};


	/*Triangle Solver Test Class - Calculate Angles*/
	TEST_CLASS(TriangleAnglesTests)
	{
	public:

        TEST_METHOD(Test_calculateTriAngles_equilateral)
        {
            //This function tests calculateTriAngles functionality  
            int side1 = 2;
            int side2 = 2;
            int side3 = 2;
            double expected[] = { 60.00, 60.00, 60.00 };
            double* actual = calculateTriAngles(side1, side2, side3);

            //Compare each angle individually using a for loop
            for (int i = 0; i < MAXSIDES; i++)
            {
                //comparing with a tolerance of 0.01 for accuracy
                Assert::AreEqual(expected[i], actual[i], 0.01);
            }
            /*Assert::AreEqual(expected[1], actual[1], 0.01);
            Assert::AreEqual(expected[2], actual[2], 0.01);*/
        }

        TEST_METHOD(Test_calculateTriAngles_scalene)
        {
            //This function tests calculateTriAngles functionality with
            //a valid scalene triangle as input
            int side1 = 3;
            int side2 = 4;
            int side3 = 5;
            double expected[] = { 36.87, 53.13, 90.00 };
            double* actual = calculateTriAngles(side1, side2, side3);

            //Compare each angle individually
            for (int i = 0; i < MAXSIDES; i++)
            {
                //comparing with a tolerance of 0.01 for accuracy
                Assert::AreEqual(expected[i], actual[i], 0.01);
            }
           /* Assert::AreEqual(expected[1], actual[1], 0.01);
            Assert::AreEqual(expected[2], actual[2], 0.01);*/
        }

        TEST_METHOD(Test_calculateTriAngles_isosceles)
        {
            //This function tests calculateTriAngles functionality with
            //a valid isosceles triangle as input
            int side1 = 6;
            int side2 = 6;
            int side3 = 5;
            double expected[] = { 65.38, 65.38, 49.25 };
            double* actual = calculateTriAngles(side1, side2, side3);

            //Compare each angle individually
            for(int i = 0; i < MAXSIDES; i++)
            {
                //comparing with a tolerance of 0.01 for accuracy
                Assert::AreEqual(expected[i], actual[i], 0.01);
            }
            /*Assert::AreEqual(expected[1], actual[1], 0.01);
            Assert::AreEqual(expected[2], actual[2], 0.01); */
		}
	};
    

    /*Rectangle Solver Test Class*/
    TEST_CLASS(RectangleSolverTests)
    {
    public:

        /* Testing for a zero-area rectangle where all points are the same*/
        TEST_METHOD(TestGetRectanglePoints_ZeroAreaRectangle)
        {
            POINTS testCoordinates[MAX_POINTS] = { {1, 1}, {1, 1}, {1, 1}, {1, 1} };
            POINTS expectedCoordinates[MAX_POINTS] = { {1, 1}, {1, 1}, {1, 1}, {1, 1} };

            /* Calling the function under test*/
            POINTS* result = getRectanglePoints(testCoordinates);

            /*Checking if the result matches the expected coordinates*/
            bool pass = true;
            for (int i = 0; i < MAX_POINTS; i++) {
                if (!(result[i].x == expectedCoordinates[i].x && result[i].y == expectedCoordinates[i].y)) {
                    pass = false;
                    break;
                }
            }

            /* Assert pass when result=coordinates*/
            Assert::IsTrue(pass);
        }

        /* Testing for a horizontal line rectangle*/
        TEST_METHOD(TestGetRectanglePoints_HorizontalLine)
        {
            POINTS testCoordinates[MAX_POINTS] = { {1, 1}, {2, 1}, {3, 1}, {4, 1} };
            POINTS expectedCoordinates[MAX_POINTS] = { {1, 1}, {2, 1}, {3, 1}, {4, 1} };

            /* Calling the function for testing*/
            POINTS* result = getRectanglePoints(testCoordinates);

            /* Checking if result == expected coordinates*/
            bool pass = true;
            for (int i = 0; i < MAX_POINTS; i++) {
                if (!(result[i].x == expectedCoordinates[i].x && result[i].y == expectedCoordinates[i].y)) {
                    pass = false;
                    break;
                }
            }

            /* Assert pass when result=coordinates*/
            Assert::IsTrue(pass);
        }

        /* Testing for a vertical line rectangle*/
        TEST_METHOD(TestGetRectanglePoints_VerticalLine)
        {
            POINTS testCoordinates[MAX_POINTS] = { {1, 1}, {1, 2}, {1, 3}, {1, 4} };
            POINTS expectedCoordinates[MAX_POINTS] = { {1, 1}, {1, 2}, {1, 3}, {1, 4} };

            /* Calling the function being tested*/
            POINTS* result = getRectanglePoints(testCoordinates);

            /* Checking if coordinates==result*/
            bool pass = true;
            for (int i = 0; i < MAX_POINTS; i++) {
                if (!(result[i].x == expectedCoordinates[i].x && result[i].y == expectedCoordinates[i].y)) {
                    pass = false;
                    break;
                }
            }

            /* test passes when result and coordinates are equal*/
            Assert::IsTrue(pass);
        }

        /* Test method for calculateDistance function*/
        TEST_METHOD(TestCalculateDistance)
        {
            // Test case 1: Test with positive coordinates
            POINTS p1 = { 0, 0 };
            POINTS p2 = { 3, 4 };
            int expected = 5;
            int result = calculateDistance(p1, p2);
            Assert::AreEqual(expected, result);

            // Test case 2: Test with negative coordinates
            POINTS p3 = { -1, -1 };
            POINTS p4 = { -4, -5 };
            int expectedNegative = 5;
            int resultNegative = calculateDistance(p3, p4);
            Assert::AreEqual(expectedNegative, resultNegative);
        }

        // Test method for calculateSlope function
        TEST_METHOD(TestCalculateSlope)
        {
            // Test case 1: Test with positive slope
            POINTS p1 = { 1, 1 };
            POINTS p2 = { 4, 5 };
            float expected = 1.3333;
            float result = calculateSlope(p1, p2);
            Assert::IsTrue(fabs(result - expected) < 0.0001);

            // Test case 2: Test with vertical line (undefined slope)
            POINTS p3 = { 2, 2 };
            POINTS p4 = { 2, 5 };
            float expectedVertical = INFINITY;
            float resultVertical = calculateSlope(p3, p4);
            Assert::IsTrue(isinf(resultVertical));
        }

        TEST_METHOD(TestCalculateAngle)
        {
            POINTS p1, p2;
            float expected, result;

            // Test with a 45-degree angle
            p1 = { 0, 0 };
            p2 = { 1, 1 };
            expected = 45.0;
            result = calculateAngle(p1, p2);
            Assert::IsTrue(fabs(result - expected) < 0.001);

            // Test with a 135-degree angle
            p1 = { 0, 0 };
            p2 = { -1, 1 };
            expected = 135.0;
            result = calculateAngle(p1, p2);
            Assert::IsTrue(fabs(result - expected) < 0.001);

            // Test with a -135-degree angle
            p1 = { 0, 0 };
            p2 = { -1, -1 };
            expected = -135.0;
            result = calculateAngle(p1, p2);
            Assert::IsTrue(fabs(result - expected) < 0.001);

            // Test with a -45-degree angle
            p1 = { 0, 0 };
            p2 = { 1, -1 };
            expected = -45.0;
            result = calculateAngle(p1, p2);
            Assert::IsTrue(fabs(result - expected) < 0.001);
        }
    };
}