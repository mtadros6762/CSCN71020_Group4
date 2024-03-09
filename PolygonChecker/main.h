#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "rectangleSolver.h"
#include "triangleSolver.h"

#pragma once
void printWelcome();
int printShapeMenu();
int* getTriangleSides(int* triangleSides);
/*Functions for Rectangle*/
Points* getRectanglePoints(Points* coordinates);
float calculateAngle(Points p1, Points p2);
float calculateSlope(Points p1, Points p2);
int calculateDistance(Points p1, Points p2);