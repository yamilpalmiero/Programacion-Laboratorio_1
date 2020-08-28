#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numero;
	int acumulador = 0;
	char respuesta;

	do {
		printf("Ingrese numero: ");
		scanf("%d", &numero);

		if (numero > 0) {
			acumulador = acumulador + numero;
		}
		printf("Desea continuar??? s/n: ");
		fflush(stdin);
		scanf("%c", &respuesta);

	} while (respuesta == 's');

	printf("\nLa suma de todos los numeros positivos es: %d\n\n", acumulador);

	system("PAUSE");

	return EXIT_SUCCESS;
}
