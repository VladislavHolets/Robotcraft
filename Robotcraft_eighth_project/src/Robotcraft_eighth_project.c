/*
 ============================================================================
 Name        : Robotcraft_eighth_project.c
 Author      : Vladislav Holets
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Array\array.h"
#include <time.h>
int main(void) {
	srand(time(NULL));
	//while(1){
	uint16_t size1 = 0;
	uint16_t size2 = 0;
	printf("Enter the size of the first array:\n");
//	fflush(stdin);
//	fflush(stdout);

	scanf("%hu",&size1);
//	fflush(stdin);
//	fflush(stdout);
	printf("Enter the size of the second array:\n");
//	fflush(stdin);
//	fflush(stdout);
	scanf("%hu", &size2);
//	fflush(stdin);
//	fflush(stdout);
	struct smartIntArray * first;
	first = createIntArray(size1);
	struct smartIntArray * second;
	second = createIntArray(size2);
	fillIntArrayRand(first, 256,300 );
	fillIntArrayRand(second, 256,300);
	printArray(first);
	printArray(second);
	struct smartIntArray * similar;
	similar = createIntArray(0);
//	puts("Similar:");
//	printArray(similar);
	struct smartIntArray * different;
	different = createIntArray(0);
//	puts("Different:");
//	printArray(different);
	//puts("Entering compareArrays:");
	struct smartIntArray **similarPtr=&similar;
	struct smartIntArray **differentPtr=&different;
	compareArrays(first, second, similarPtr, differentPtr);
	printf("Similar:");
	printArray(similar);
	printf("Different:");
	printArray(different);

//	//}
}
