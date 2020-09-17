#include <stdio.h>
#include <stdlib.h>
#define CANT 3

int main(void) {
	setbuf(stdout, NULL);

	int edades[CANT];
	float salarios[CANT];
	char sexo[CANT];

	iniArrayEnteros(edades, CANT);
	iniArrayFlotantes(salarios, CANT);
	iniArrayCaracteres(sexo, CANT);

	return EXIT_SUCCESS;
}
