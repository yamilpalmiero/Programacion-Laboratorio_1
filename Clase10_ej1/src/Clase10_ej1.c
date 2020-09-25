#include <stdio.h>
#include <stdlib.h>
#define CANT_CLIENTES 3

void getCadena(char *mensaje, char *input);
void imprimirArrayCadena(char pArray[][21], int limite);

int main(void) {
	setbuf(stdout, NULL);

	char arrayNombres[CANT_CLIENTES][21];
	char arrayApellidos[CANT_CLIENTES][21];
	char auxNombre[21];
	char auxApellido[21];
	int i;

	for (i = 0; i < CANT_CLIENTES; i++) {
		getCadena("Nombre: ", auxNombre);
	}
	imprimirArrayCadena(arrayNombres[i], CANT_CLIENTES);

	for (i = 0; i < CANT_CLIENTES; i++) {
		getCadena("Apellido: ", auxApellido);
	}
	imprimirArrayCadena(arrayApellidos[i], CANT_CLIENTES);

	return EXIT_SUCCESS;
}

void getCadena(char *mensaje, char *input) {
	printf("%s", mensaje);
	gets(input);
}

void imprimirArrayCadena(char pArray[][21], int limite) {
	int i;

	if (pArray != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			printf("%s", pArray[i]);
			printf("\n");
		}
	}
}
