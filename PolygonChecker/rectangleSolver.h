#pragma once

//group4 - cscn71020 - rectangle solver interface

//Rectangle Solver library
#ifndef RECTANGLE_SOLVER_LIBRARY_H
#define RECTANGLE_SOLVER_LIBRARY_H

/*Libraries used*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*MACROS USED*/
#define M_PI 3.14159265358979323846
#define MAX_ANGLE 360
#define MIN_VALUE 0
#define RIGHT_ANGLE 90
#define POWER_2 2
#define STRAIGHT_ANGLE 180
#define MAX_POINTS 4
#define SLOPE_SUM 0

/*Structs used*/
typedef struct points{
	int x, y;
}POINTS;

/*Functions Used*/
POINTS* getRectanglePoints(POINTS* coordinates);
float calculateAngle(POINTS p1, POINTS p2);
float calculateSlope(POINTS p1, POINTS p2);
int calculateDistance(POINTS p1, POINTS p2);
 bool isRectangle(POINTS* Coordinates);
#endif //RECTANGLE_SOLVER_LIBRARY_H