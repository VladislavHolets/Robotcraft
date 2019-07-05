/*
 * position.c
 *
 *  Created on: Jul 3, 2019
 *      Author: curab
 */

#include "position.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void printPosition(struct Position* position) {
printf("\nPosition x:%d y:%d",position->x,position->y);
}
struct Position* createPosition(int16_t x, int16_t y) {
	struct Position *newInstance = (struct Position *) malloc(
			sizeof(struct Position));
	newInstance->x = x;
	newInstance->y = y;
	return newInstance;
}
void destroyPosition(struct Position* position) {
	free(position);
}
double distancePositions(struct Position* first, struct Position* second) {
double result;
result=pow((pow(first->x-second->x,2.0)+pow(first->y-second->y,2.0)),0.5);
return result;
}
struct PositionsArray* generateArrayOfPositions(uint16_t size) {
	struct PositionsArray *newInstance = (struct PositionsArray *) malloc(sizeof(struct PositionsArray));

	newInstance->size = size;
	newInstance->array = (struct Position**) malloc(
			sizeof(struct Position*) * size);
	for(uint16_t i=0;i<newInstance->size;++i){
		newInstance->array[i]=(struct Position*)malloc(sizeof(struct Position));
	}
	for (uint16_t i = 0; i <newInstance->size; ++i) {
		newInstance->array[i]->x =rand()%10;
		newInstance->array[i]->y =rand()%10;
	}
	return newInstance;
}
void destroyArrayOfPositions(struct PositionsArray* instance) {
for(uint16_t i=0;i<instance->size;++i){
	free(instance->array[i]);
}
free(instance->array);
free(instance);
}
