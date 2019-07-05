/*
 ============================================================================
 Name        : Robocraft_third_project.c
 Author      : Vladislav Holets
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
struct Date {
	uint16_t day;
	uint16_t month;
	uint16_t year;
};
struct Person {
	char *name;
	struct Date bithday;
};
struct Person* fillThePerson();
struct Person* oldestFcn(struct Person* first, struct Person* second);
int main(void) {
	struct Person * first;
	struct Person * second;
	struct Person * oldest;
	while (1) {
		printf("Enter the data of the first person:\n");
		first = fillThePerson();
		printf("Enter the data of the second person:\n");
		second = fillThePerson();
		oldest = oldestFcn(first, second);
		printf("The oldest one is ");
		puts(oldest->name);
		free(first->name);
		free(second->name);
		free(first);
		free(second);
//		first=NULL;
//		second=NULL;
		printf("Enter the data of the first person:\n");
		first = fillThePerson();
		printf("Enter the data of the second person:\n");
		second = fillThePerson();
		oldest = oldestFcn(first, second);
		printf("The oldest one is ");
		puts(oldest->name);
		free(first->name);
		free(second->name);
		free(first);
		free(second);

	}
	return EXIT_SUCCESS;
}
struct Person* fillThePerson() {
	struct Person * person = malloc(sizeof(struct Person));
	fflush(stdout);
	fflush(stdin);
	printf("Name:");
	//next line is for Eclipse console, you can comment it while releasing in usual console
	fflush(stdin);
	fflush(stdout);
	person->name = malloc(sizeof(char) * 50);
	gets(person->name);
	//next line is for Eclipse console, you can comment it while releasing in usual console
	fflush(stdout);
	printf("Birthday:\n\t Day:");
	//next line is for Eclipse console, you can comment it while releasing in usual console
	fflush(stdout);
	scanf("%hu",  &(person->bithday.day));
	//next line is for Eclipse console, you can comment it while releasing in usual console
	fflush(stdout);
	printf("\t Month:");
	//next line is for Eclipse console, you can comment it while releasing in usual console
	fflush(stdout);
	scanf("%hu", &(person->bithday.month));
	//next line is for Eclipse console, you can comment it while releasing in usual console
	fflush(stdout);
	printf("\t Year:");
	//next line is for Eclipse console, you can comment it while releasing in usual console
	fflush(stdout);
	scanf("%hu", &(person->bithday.year));
	//next line is for Eclipse console, you can comment it while releasing in usual console
	fflush(stdout);
	return person;
}
struct Person* oldestFcn(struct Person* first, struct Person* second) {
	if (first->bithday.year > second->bithday.year) {
		return second;
	} else if (first->bithday.year < second->bithday.year) {
		return first;
	} else {
		if (first->bithday.month > second->bithday.month) {
			return second;
		} else if (first->bithday.month < second->bithday.month) {
			return first;
		} else {
			if (first->bithday.day > second->bithday.day) {
				return second;
			} else if (first->bithday.day < second->bithday.day) {
				return first;
			}
		}
	}
	return first;
}
