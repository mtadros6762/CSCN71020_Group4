#pragma once

//group4 - cscn71020 - main interface

//Main Library
#ifndef MAIN_LIBRARY_H
#define MAIN_LIBRARY_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "rectangleSolver.h"
#include "triangleSolver.h"
#include "rectangleTests.h"
#include "triangleTests.h"

/*Menu Functions*/
void printWelcome();
int printShapeMenu();
char getCharInput(char message[]);

/*Functions for Rectangle*/
POINTS* getRectanglePoints(POINTS* coordinates);
float calculateAngle(POINTS p1, POINTS p2); 
float calculateSlope(POINTS p1, POINTS p2);
int calculateDistance(POINTS p1, POINTS p2);

#endif //MAIN_LIBRARY_H