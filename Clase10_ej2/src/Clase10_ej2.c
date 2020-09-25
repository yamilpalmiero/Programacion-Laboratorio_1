#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nombre[21];
	char apellido[21];
	char calle[21];
	int numero;
} datosPersonales;

int main(void) {
	setbuf(stdout, NULL);

	datosPersonales agenda;

	strcpy(agenda.nombre, "Yamil");
	strcpy(agenda.apellido, "Palmiero");
	strcpy(agenda.calle, "Belgrano");
	agenda.numero = 1260;

	printf("El nombre completo es: %s %s", agenda.nombre, agenda.apellido);
	printf("\nLa direccion es: %s %d", agenda.calle, agenda.numero);
	printf("\n\n");

	system("pause");

	return EXIT_SUCCESS;
}
