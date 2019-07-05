/*
 * position.h
 *
 *  Created on: Jul 3, 2019
 *      Author: curab
 */

#ifndef POSITION_H_
#define POSITION_H_
#include <stdint.h>
struct Position{
	int16_t x;
	int16_t y;
};
struct PositionsArray{
	uint16_t size;
	struct Position **array;
};
void printPosition(struct Position* position);
struct Position* createPosition(int16_t x,int16_t y);
void destroyPosition(struct Position* position);
double distancePositions(struct Position* first,struct Position* second);
struct PositionsArray* generateArrayOfPositions(uint16_t size);
void destroyArrayOfPositions(struct PositionsArray* instance);
#endif /* POSITION_H_ */
