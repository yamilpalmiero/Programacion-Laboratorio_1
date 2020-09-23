#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANT 3

int main(void) {
	setbuf(stdout, NULL);

	int edades[CANT];
	float sueldos[CANT];

	utn_iniArrayEnteros(edades, CANT);
	utn_iniArrayFlotantes(sueldos, CANT);

	utn_cargarArrays(edades, sueldos, CANT);

	utn_imprimirElemento(edades, sueldos, 1);

	return EXIT_SUCCESS;
}
