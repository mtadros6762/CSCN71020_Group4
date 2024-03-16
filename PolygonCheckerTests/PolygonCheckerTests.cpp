#include "pch.h"
#include "CppUnitTest.h"
#include"..\PolygonChecker\main.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{
    

	//Triangle Solver Test Class
	TEST_CLASS(TriangleSolverTests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};

	//Rectangle Solver Test Class
	TEST_CLASS(RectangleSolverTests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};

	//Input Validation Test Class
	TEST_CLASS(InputValidationTests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};
    

    //Rectangle Solver Test Class
    TEST_CLASS(RectangleSolverTests)
    {
    public:
       
        TEST_METHOD(TestGetRectanglePoints)
        {
            Points testCoordinates[MAX_POINTS];
            Points expectedCoordinates[MAX_POINTS] = { {1, 2}, {3, 4}, {5, 6}, {7, 8} }; 

            
            for (int i = 0; i < MAX_POINTS; i++) {
                testCoordinates[i] = expectedCoordinates[i];
            }

            
            Points* result = getRectanglePoints(testCoordinates);

            
            bool pass = true;
            for (int i = 0; i < MAX_POINTS; i++) {
                if (!(result[i].x == expectedCoordinates[i].x && result[i].y == expectedCoordinates[i].y)) {
                    pass = false;
                    break;
                }
            }

            
            Assert::IsTrue(pass);
        }



        // Test method for calculateDistance function
        TEST_METHOD(TestCalculateDistance)
        {
            // Test case 1: Test with positive coordinates
            Points p1 = { 0, 0 };
            Points p2 = { 3, 4 };
            int expected = 5;
            int result = calculateDistance(p1, p2);
            Assert::AreEqual(expected, result);

            // Test case 2: Test with negative coordinates
            Points p3 = { -1, -1 };
            Points p4 = { -4, -5 };
            int expectedNegative = 5;
            int resultNegative = calculateDistance(p3, p4);
            Assert::AreEqual(expectedNegative, resultNegative);
        }

        // Test method for calculateSlope function
        TEST_METHOD(TestCalculateSlope)
        {
            // Test case 1: Test with positive slope
            Points p1 = { 1, 1 };
            Points p2 = { 4, 5 };
            float expected = 1.3333;
            float result = calculateSlope(p1, p2);
            Assert::IsTrue(fabs(result - expected) < 0.0001);

            // Test case 2: Test with vertical line (undefined slope)
            Points p3 = { 2, 2 };
            Points p4 = { 2, 5 };
            float expectedVertical = INFINITY;
            float resultVertical = calculateSlope(p3, p4);
            Assert::IsTrue(isinf(resultVertical));
        }

        TEST_METHOD(TestCalculateAngle)
        {
            Points p1, p2;
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