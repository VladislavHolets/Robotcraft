/*
 ============================================================================
 Name        : Robotcraft_nineth_project.c
 Author      : Vladislav Holets
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "Position/position.h"

int main(void) {
	int16_t x1,x2,y1,y2;
	printf("\n Enter the coordinates of the first position:");
	scanf("%"SCNd16,&x1);
	scanf("%"SCNd16,&y1);
	struct Position *first = createPosition(x1, y1);
	printf("\n Enter the coordinates of the second position:");
	scanf("%"SCNd16,&x2);
	scanf("%"SCNd16,&y2);
	struct Position *second = createPosition(x2, y2);
	printf("\nFirst:");
	printPosition(first);
	printf("\nSecond:");
	printPosition(second);
	printf("\n Distance is:%lf", distancePositions(first, second));

	printf("\n Enter the amount of generated positions:");
	uint16_t size;
	scanf("%"SCNu16 ,&size);
	struct PositionsArray *third = generateArrayOfPositions(size);
	printf("\n>>>SUCCESS!!!\n\n>>>LETS PRINT");

	for (uint16_t i = 0; i < third->size; ++i) {
		printPosition(third->array[i]);
	}
	printf("\n>>>SUCCESS!!!\n\n>>>LETS DESTROY");

	destroyArrayOfPositions(third);
	printf("\n>>>SUCCESS!!!\n\n>>>BYE");

	return EXIT_SUCCESS;
}
