/*
 ============================================================================
 Name        : Robotcraft_sixth_project.c
 Author      : Vladislav Holets
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
void timeSorter(uint16_t input, uint16_t * hours, uint16_t * minutes);
int main(void) {
	while (1) {
		puts("\nEnter the time:"); /* prints !!!Hello World!!! */
		uint16_t *hours = malloc(sizeof(uint16_t));
		uint16_t *minutes = malloc(sizeof(uint16_t));
		uint16_t input = 0;
		scanf("%d", &input);
		timeSorter(input, hours, minutes);
		printf("\nThe time is %02d:%02d", *hours, *minutes);
		free(hours);
		free(minutes);
	}
	return EXIT_SUCCESS;
}
void timeSorter(uint16_t input, uint16_t * hours, uint16_t * minutes) {
	*hours = input / 60;
	*minutes = input % 60;
}
