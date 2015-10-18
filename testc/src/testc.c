/*
 ============================================================================
 Name        : testc.c
 Author      : Gosia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char str[] = "Ciąg znaków w zmiennej";
	char * str_ptr = &str;
	int num = 10;
	int * num_ptr = &num;

	printf("Ciąg znaków: %s\n", "Statyczy ciąg znaków");
	printf("Ciąg znaków w zmiennej: %s\n", str);
	printf("Ciąg znaków w zmiennej przez wskaźnik: %s\n", str_ptr);
	str_ptr++;
	printf("Ciąg znaków w zmiennej przez wskaźnik++: %s\n", str_ptr);
	printf("Liczba zmiennoprzecinkowa: 1.5*2.7=%f\n", 1.5 * 2.7);
	printf("Liczba całkowita w zmiennej num: %i\n", num);
	printf("Liczba całkowita w zmiennej num_ptr: %i\n", *num_ptr);
	printf("Adres zmiennej num: %i\n", &num);
	printf("Na co wskazuje num_ptr: %i\n", num_ptr);

	return EXIT_SUCCESS;
}
