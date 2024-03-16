#pragma once

//group4 - cscn71020 - triangle solver interface

//Triangle Solver library
#ifndef TRIANGLE_SOLVER_LIBRARY_H
#define TRIANGLE_SOLVER_LIBRARY_H

/*Libraries Used*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*MACROS USED*/
#define COSDENOMINATOR 2.0	//law of cosines, '.0' to avoid truncation
#define PI 3.14159265358979323846
#define MAX_TRI_ANGLES 180
#define MAXSIDES 3

/*Functions Used*/
int* getTriangleSides(int* triangleSides);
bool validTriangle(int side1, int side2, int side3);
char* analyzeTriangle(int side1, int side2, int side3);
double* calculateTriAngles(int side1, int side2, int side3);
void anglesOfTriangle(int side1, int side2, int side3);

#endif //TRIANGLE_SOLVER_H