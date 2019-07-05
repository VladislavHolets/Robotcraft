/*
 ============================================================================
 Name        : Robocraft_first_project.c
 Author      : Vladislav Holets
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdint.h>
#include <stdio.h>

uint8_t verifyOddEven(int16_t number);
int16_t readNumber();

int main(void) {
	int16_t number1 = 0;
	int16_t number2 = 0;
	while (1) {
		number1 = readNumber();
		number2 = readNumber();
		if (number1 > number2) {
			int16_t temp = number2;
			number2 = number1;
			number1 = temp;
		}
		for (; number1 <= number2; ++number1) {
			printf("\nthe number %d is ", number1);
			verifyOddEven(number1);

		}
	}
}

uint8_t verifyOddEven(int16_t number) {
	if (number % 2) {
		printf("odd");
		return 1;
	} else {
		printf("even");
		return 0;
	}
}
int16_t readNumber() {
	int16_t number = 0;
	printf("\nPlease, enter a number here:");
	//next line is for Eclipse console, you can comment it while releasing in usual console
	fflush(stdout);
	scanf("%hd", &number);
	//next line is for Eclipse console, you can comment it while releasing in usual console
	fflush(stdout);
	return number;
}
