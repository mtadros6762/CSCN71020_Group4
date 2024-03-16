#include "pch.h"
#include "CppUnitTest.h"
#include"..\PolygonChecker\rectangleSolver.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{
    

	//Triangle Solver Test Class
	TEST_CLASS(TypeOfTriangleTests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};

	
	TEST_CLASS(TriangleAnglesTests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};

	//Input Validation Test Class
	TEST_CLASS(RectangleFourPointsTests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
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