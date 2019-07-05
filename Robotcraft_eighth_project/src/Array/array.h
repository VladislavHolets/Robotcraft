/*
 * array.h
 *
 *  Created on: Jul 3, 2019
 *      Author: curab
 */

#ifndef ARRAY_H_
#define ARRAY_H_
#include <stdint.h>
struct smartIntArray{
	uint16_t size;
	int16_t *array;
};
struct smartIntArray * createIntArray(uint16_t size);
void fillIntArrayRand(struct smartIntArray *instance,uint16_t randMin,uint16_t randMax);
struct smartIntArray * insertIntValue(struct smartIntArray *instance,int16_t value,uint16_t position);
struct smartIntArray * copyArray(struct smartIntArray * instance);
void compareArrays(struct smartIntArray * first,struct smartIntArray *second, struct smartIntArray **similar, struct smartIntArray **different);
uint8_t isInArray(struct smartIntArray * instance,int16_t value);
void printArray(struct smartIntArray * instance);
#endif /* ARRAY_H_ */
