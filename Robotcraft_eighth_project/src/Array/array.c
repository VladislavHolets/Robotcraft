/*
 * array
 *
 *  Created on: Jul 3, 2019
 *      Author: curab
 */

#include "array.h"

#include <stdio.h>
#include <stdlib.h>


struct smartIntArray * createIntArray(uint16_t size) {
	struct smartIntArray *newInstance =(struct smartIntArray *) malloc(sizeof(struct smartIntArray));
	newInstance->array =(int16_t*) malloc(sizeof(int16_t) * size);
	newInstance->size = size;
	return newInstance;
}
void fillIntArrayRand(struct smartIntArray * instance, uint16_t randMin,
		uint16_t randMax) {

	if (randMin > randMax) {
		uint16_t temp = randMax;
		randMax = randMin;
		randMin = temp;
	}
	for (uint16_t i = 0; i < instance->size; ++i) {
		instance->array[i] = randMin + rand() % (randMax - randMin);
	}

}
struct smartIntArray * insertIntValue(struct smartIntArray * instance, int16_t value,
		uint16_t position) {
	if (instance->size <= position) {
		struct smartIntArray * newInstance = createIntArray(position);
		for (uint16_t i = 0; i < instance->size; ++i) {
			newInstance->array[i] = instance->array[i];
		}
		for (uint16_t i = instance->size; i < position - 1; ++i) {
			newInstance->array[i] = 0;
		}
		newInstance->array[position - 1] = value;
		free(instance->array);
		free(instance);
		instance=copyArray(newInstance);
		//printArray(instance);
		free(newInstance->array);
		free(newInstance);
		return instance;
	} else {
		struct smartIntArray * newInstance = createIntArray(instance->size+1);
		for (uint16_t i = 0; i < position - 1; ++i) {
			newInstance->array[i] = instance->array[i];
		}
		newInstance->array[position - 1] = value;
		for (uint16_t i = position; i < instance->size + 1; ++i) {
			newInstance->array[i] = instance->array[i - 1];
		}
		free(instance->array);
		free(instance);
		instance = newInstance;
		return instance;
	}

}
struct smartIntArray * copyArray(struct smartIntArray * instance) {
	struct smartIntArray *newInstance = createIntArray(instance->size);
	newInstance->array = malloc(sizeof(int16_t) * instance->size);
	for (uint16_t i = 0; i < newInstance->size; ++i) {
		newInstance->array[i] = instance->array[i];
	}
	return newInstance;
}
void compareArrays(struct smartIntArray * first, struct smartIntArray *second,
		struct smartIntArray **similar, struct smartIntArray **different) {
//	printf("\nFirst {%hu }:",first->size);
//	puts("before for:");
//	puts("\nFirst:");
//	printArray(first);
//	puts("\nSecond:");
//	printArray(second);
//	puts("\nSimilar:");
//	printArray(similar);
//	puts("\nDifferent:");
//	printArray(different);

	for (uint16_t i = 0; i < first->size; ++i) {
//		puts("before ifs");
//		puts("\nFirst:");
//		printArray(first);
//		puts("\nSecond:");
//		printArray(second);
//		puts("\nSimilar:");
//		printArray(similar);
//		puts("\nDifferent:");
//		printArray(different);
		if (isInArray(second, first->array[i])==1
				&& isInArray(*similar, first->array[i])==0) {
			//puts("FOUND SIMILAR, ATTEMPT TO ADD IT TO THE Similar ARRAY");
			//printf("\nsimilar {%hu }:",similar->size);
			*similar=insertIntValue(*similar, first->array[i], (*similar)->size + 1);
			//printf("\nsimilar {%hu }:",similar->size);
		}
		if (isInArray(second, first->array[i])==0
				&& isInArray(*different, first->array[i])==0) {
			//puts("FOUND DIFFERENT, ATTEMPT TO ADD IT TO THE Different ARRAY");
			*different = insertIntValue(*different, first->array[i], (*different)->size + 1);
		}
	}
}
uint8_t isInArray(struct smartIntArray * instance, int16_t value) {
	for (uint16_t i = 0; i < instance->size; ++i) {
		if (instance->array[i] == value) {
			//printf("\nisInArray->true");
			return 1;
		}
	}
	//printf("\nisInArray->false");
	return 0;
}
void printArray(struct smartIntArray * instance) {
	printf("\n{\n\t{ %d }\n\t{",instance->size);
	for (uint16_t i = 0; i < instance->size; ++i) {
		if (i%20==0){
			printf("\n");
		}
		printf("%d |", instance->array[i]);
	}
	printf("\n\t}\n}");
}
