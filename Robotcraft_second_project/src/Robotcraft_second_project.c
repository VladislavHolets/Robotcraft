/*
 ============================================================================
 Name        : Robotcraft_second_project.c
 Author      : Vladislav Holets
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t isPrime(int16_t number);
int16_t readNumber();
void identifyPrimes(uint16_t number1,uint16_t number2);
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
			 identifyPrimes(number1,number2);
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
uint8_t isPrime(int16_t number){
	for (int i=2;i<number;++i){
		if ((number%i)==0 || number==1){
			fflush(stdout);
			printf("NOT prime. ");
			fflush(stdout);
			return 0;
		}
	}

	fflush(stdout);
	printf("prime. ");
	fflush(stdout);
	return 1;

}
void identifyPrimes(uint16_t number1,uint16_t number2){
	for (; number1 <= number2; ++number1) {
					printf("\nThe number %d is ", number1);
					isPrime(number1);

				}
}
