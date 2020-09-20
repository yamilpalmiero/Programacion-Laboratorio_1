#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANT 3

int main(void) {
	setbuf(stdout, NULL);

	int edades[CANT];
	float salarios[CANT];
	int posicion;
	char respuesta;
	float promedio;

	utn_iniArrayEnteros(edades, CANT);
	utn_iniArrayFlotantes(salarios, CANT);

	do {
		printf("Ingrese posicion donde cargar los valores: ");
		scanf("%d", &posicion);

		printf("\nIngrese edad: ");
		scanf("%d", &edades[posicion]);

		printf("\nIngrese salario: ");
		scanf("%f", &salarios[posicion]);

		printf("\n\nDesea continuar? s/n: ");
		fflush(stdin);
		scanf("%c", &respuesta);
	} while (respuesta == 's');

	utn_calcularPromedio(salarios, CANT, &promedio);
	utn_imprimirArrayEnteros(edades, CANT);
	utn_imprimirArrayFlotantes(salarios, CANT);

	printf("\nEl salario promedio es: %.2f", promedio);

	printf("\n\n");
	system("pause");

	return EXIT_SUCCESS;
}
