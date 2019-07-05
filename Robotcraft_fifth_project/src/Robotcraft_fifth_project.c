/*
 ============================================================================
 Name        : Robotcraft_fifth_project.c
 Author      : Vladislav Holets
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main(void) {
	while(1){
	puts("\nEnter the string:\n"); /* prints !!!Hello World!!! */
	char* str=malloc(sizeof(char)*100);
	gets(str);
	uint8_t size1=0;
	uint8_t size2=0;

	while(str[size1]!='\0'){
		size1++;
	}
	while(*str!='\0'){
		str++;
		size2++;
	}
	printf("The size is %d and %d",size1,size2);
	free(str);
}
	return EXIT_SUCCESS;
}
