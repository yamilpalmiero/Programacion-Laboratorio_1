#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANT 3

int main(void) {
	setbuf(stdout, NULL);

	int edades[CANT];
	int sueldos[CANT];
	float suma = 0;
	float promedio;
	int i;

	for (i = 0; i < CANT; i++) {
		edades[i] = 0;
		sueldos[i] = 0;
	}

	for (i = 0; i < CANT; i++) {
		printf("Ingrese edad para el legajo %d: ", i + 1);
		scanf("%d", &edades[i]);
		printf("Ingrese sueldo para el legajo %d: ", i + 1);
		scanf("%d", &sueldos[i]);
	}

	for (i = 0; i < CANT; i++) {
		suma = suma + sueldos[i];
	}

	promedio = suma / CANT;

	system("cls");

	for (i = 0; i < CANT; i++) {
		printf("\nLegajo %d", i + 1);
		printf("\nEdad: %d", edades[i]);
		printf("\nSueldo: %d\n", sueldos[i]);
	}

	printf("\nEl sueldo promedio es %.2f\n", promedio);

	printf("\n");
	system("pause");

	return EXIT_SUCCESS;
}
