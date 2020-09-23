#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANT 3

int main(void) {
	setbuf(stdout, NULL);

	int edades[CANT] = { 30, 20, 40 };
	float sueldos[CANT] = { 300, 200, 400 };
	int i;

	printf("DESORDENADO");
	for (i = 0; i < CANT; i++) {
		printf("\nEdad: %d", edades[i]);
		printf("\nSueldo: %.2f", sueldos[i]);
	}

	utn_ordenarArraysPorEntero(edades, sueldos, CANT);

	printf("\n\nORDENADO");
	for (i = 0; i < CANT; i++) {
		printf("\nEdad: %d", edades[i]);
		printf("\nSueldo: %.2f", sueldos[i]);
	}

	printf("\n\n");
	system("pause");

	return EXIT_SUCCESS;
}
