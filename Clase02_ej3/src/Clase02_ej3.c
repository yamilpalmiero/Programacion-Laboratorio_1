#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	char nombre[20];

	printf("Ingrese nombre: ");
	fflush(stdin);
	scanf("%s", nombre);

	printf("Usted ingreso: %s\n\n", nombre);

	system("PAUSE");

	return 0;
}
