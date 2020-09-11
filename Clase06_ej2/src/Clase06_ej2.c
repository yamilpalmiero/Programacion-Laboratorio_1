#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);

	int edad;
	int respuesta;

	respuesta = utn_getNumero(&edad, "Ingrese la edad: ", "Error, debe ser entre 0 y 150.\n\n", 0, 150, 3);
	if (respuesta == -1) {
		printf("Ya no tiene reintentos.");
	} else {
		printf("Su edad es: %d anios", edad);
	}
	return 0;
}
