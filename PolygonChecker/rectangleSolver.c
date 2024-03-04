#include "main.h"

Points* getRectanglePoints(Points* coordinates) {
	printf_s("Enter the 4 points of the rectangle: \n");
	for (int i = 0; i < 4; i++)
	{
		scanf_s("%d %d", &coordinates[i].x, &coordinates[i].y);
	}
	return coordinates;
}