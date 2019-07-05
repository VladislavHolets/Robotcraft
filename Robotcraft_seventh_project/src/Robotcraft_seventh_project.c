/*
 ============================================================================
 Name        : Robotcraft_seventh_project.c
 Author      : Vladislav Holets
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void sphereCalculator(double radS, double * areaS, double * volS);
int main(void) {
	while (1) {
		puts("\nEnter the radius:"); /* prints !!!Hello World!!! */
		double volS = 0;
		double areaS = 0;
		double radS = 0;
		scanf("%lf", &radS);
		sphereCalculator(radS, &areaS, &volS);
		printf("\nThe areas is:%lf \nThe volume is:%lf", areaS, volS);
	}
	return EXIT_SUCCESS;
}
void sphereCalculator(double radS, double * areaS, double * volS) {
	*areaS = 4.0 * M_PI * pow(radS,2.0) ;
	*volS = 4.0 * M_PI * pow(radS,3.0)/3 ;
}
