#include <stdio.h>
#include <stdlib.h>

int pedirEntero() {
	int entero;
	printf("\nIngrese numero entero: ");
	scanf("%d", &entero);
	printf("El numero ingresado es: %d", entero);
	return entero;
}

float calculoArea(float x) {
	float resultado;
	resultado = 3.14 * (x * x);
	return resultado;
}
