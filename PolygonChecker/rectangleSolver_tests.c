#include "main.h"
#include <math.h> 

//group4 - cscn71020 - rectangle solver tests implementation

// Testing function getRectanglePoints
void testGetRectanglePoints() {
    POINTS testCoordinates[MAX_POINTS];
    POINTS expectedCoordinates[MAX_POINTS] = { {1, 2}, {3, 4}, {5, 6}, {7, 8} }; // expected results for the test

    // normally getRectanglePoints would get its input from the user
    // here we are simulating that by directly setting the testCoordinates
    for (int i = 0; i < MAX_POINTS; i++) {
        testCoordinates[i] = expectedCoordinates[i];
    }

    // call the function and pass in the test data
    // and return a pointer to the array with the processed coordinates.
    POINTS* result = getRectanglePoints(testCoordinates);

    // if it worked correctly the ouput should match the expectations
    bool pass = true;
    for (int i = 0; i < MAX_POINTS; i++) {
        // check each point. if a point doesn't match, set pass flag to false and exit the loop.
        if (!(result[i].x == expectedCoordinates[i].x && result[i].y == expectedCoordinates[i].y)) {
            pass = false;
            break;
        }
    }

    // print the test result based on the value of pass flag.
    if (pass) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n"); // there was at least one mismatch.
    }
}

// Testing function calculateDistance
void testCalculateDistance() {
    POINTS p1 = { 0, 0 };
    POINTS p2 = { 3, 4 };
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
    POINTS p1 = { 1, 1 };
    POINTS p2 = { 4, 5 };
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
    POINTS p1 = { 0, 0 };
    POINTS p2 = { 1, 1 };
    float expected = 45.0; // degrees
    float result = calculateAngle(p1, p2);
    if (fabs(result - expected) < 0.001) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }
}