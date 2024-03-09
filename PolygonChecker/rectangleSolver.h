#pragma once
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
typedef struct {
	int x, y;
}Points;


Points* getRectanglePoints(Points* coordinates);
float calculateAngle(Points p1, Points p2);
float calculateSlope(Points p1, Points p2);
int calculateDistance(Points p1, Points p2);