#include "main.h"
#include"math.h"




//// Testing function getRectanglePoints
//void testRunner_getRectanglePoints() 
//{
//    if (mostlyEqual(actual, expected))
//        printf("PASS (%0.20lf,%0.20lf) \n", actual, expected);
//    else
//        printf("FAIL (%0.20lf,%0.20lf) \n", actual, expected);
//}

// Testing function calculateDistance
void testCalculateDistance() {
    Points p1 = { 0, 0 };
    Points p2 = { 3, 4 };
    int expected = 5;
    int result = calculateDistance(p1, p2);
    if (result == expected) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }
}

// Testing function CalculateSlope
void testCalculateSlope() {
    Points p1 = { 1, 1 };
    Points p2 = { 4, 5 };
    float expected = 1.333333;
    float result = calculateSlope(p1, p2);
    if (fabs(result - expected) < 0.0001) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }
}

// Testing function CalculateAngle
void testCalculateAngle() {
    Points p1 = { 0, 0 };
    Points p2 = { 1, 1 };
    float expected = 45.0; // degrees
    float result = calculateAngle(p1, p2);
    if (fabs(result - expected) < 0.001) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }
}