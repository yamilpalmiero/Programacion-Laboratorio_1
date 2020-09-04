#include <stdio.h>
#include <stdlib.h>
#include "Calculos.h"

int main(void) {
	setbuf(stdout, NULL);

	int num1;
	int num2;
	int suma;
	float radio;
	float area;

	num1 = pedirEntero();
	num2 = pedirEntero();

	suma = num1 + num2;

	printf("\nIngrese el radio del circulo: ");
	scanf("%f", &radio);
	area = calculoArea(radio);

	printf("\n\nEl resultado de la suma es %d", suma);
	printf("\n\nEl area es %.2f", area);

	return EXIT_SUCCESS;
}
