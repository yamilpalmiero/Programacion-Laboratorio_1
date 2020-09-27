#include <stdio.h>
#include <stdlib.h>

int esNumerico(char *array);
int esSoloLetras(char *array);
int esAlfaNumerico(char *array);
int esTelefono(char *array);

int main(void) {
	setbuf(stdout, NULL);

	char input[20];

	printf("Ingrese dato: ");
	fflush(stdin);
	gets(input);

	if (esNumerico(input) == 0) {
		printf("\nEs una cadena numerica.");
	}
	if (esSoloLetras(input) == 0) {
		printf("\nEs una cadena de caracteres.");
	}
	if (esAlfaNumerico(input) == 0) {
		printf("\nNumeros y caracteres.");
	}
	if (esTelefono(input) == 0) {
		printf("\nEs un telefono.");
	}

	printf("\n\n");
	system("pause");

	return EXIT_SUCCESS;
}

int esNumerico(char *array) {
	int retorno = 0;
	int i = 0;

	while (array[i] != '\0') {
		if (array[i] < '0' || array[i] > '9') {
			retorno = -1;
		}
		i++;
	}
	return retorno;
}

int esSoloLetras(char *array) {
	int retorno = 0;
	int i = 0;

	while (array[i] != '\0') {
		if ((array[i] != ' ') && (array[i] < 'a' || array[i] > 'z')
				&& (array[i] < 'A' || array[i] > 'Z')) {
			retorno = -1;
		}
		i++;
	}
	return retorno;
}

int esAlfaNumerico(char *array) {
	int retorno = 0;
	int i = 0;

	while (array[i] != '\0') {
		if ((array[i] != ' ') && (array[i] < '0' || array[i] > '9')
				&& (array[i] < 'a' || array[i] > 'z')
				&& (array[i] < 'A' || array[i] > 'Z')) {
			retorno = -1;
		}
		i++;
	}
	return retorno;
}

int esTelefono(char *array) {
	int i = 0;
	int retorno = 0;
	int contadorGuiones = 0;
	int contadorEspacios = 0;

	while (array[i] != '\0') {
		if ((array[i] != ' ') && (array[i] != '-')
				&& (array[i] < '0' || array[i] > '9')) {
			retorno = -1;
		}
		if (array[i] == '-') {
			contadorGuiones++;
		}
		if (array[i] == ' ') {
			contadorEspacios++;
		}
		i++;
	}
	if (contadorGuiones > 1) {
		retorno = -2;
	}
	if (contadorEspacios > 2) {
		retorno = -3;
	}
	return retorno;
}
