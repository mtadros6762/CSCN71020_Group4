#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "inputValidation.h"

//Input Validation Implementation

char* inputValidation(int* triangleSides, int MAXARRAY) {
	char* result = "";
	int userInput = 0;
	
	for (int arrayPosition = 0; arrayPosition < MAXARRAY; arrayPosition++) {

		triangleSides[arrayPosition] = userInput;
		
		if (userInput != 1) {

			result = "Not a triangle";
		}
	}

	return result;
}