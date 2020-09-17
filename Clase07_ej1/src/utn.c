#include <stdio.h>
#include <stdlib.h>

int utn_getEntero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int numero;
	int ret;

	while (reintentos > 0) {

		printf(mensaje);
		fflush(stdin);

		if (scanf("%d", &numero) == 1) {
			if (numero >= minimo && numero <= maximo) {
				break;
			} else {
				reintentos--;
				printf(mensajeError);
				fflush(stdin);
			}
		}
	}
	if (reintentos == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResultado = numero;
	}

	return ret;
}

float utn_getFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {
	float numero;
	int ret;

	while (reintentos > 0) {

		printf(mensaje);
		fflush(stdin);

		if (scanf("%f", &numero) == 1) {
			if (numero >= minimo && numero <= maximo) {
				break;
			} else {
				reintentos--;
				printf(mensajeError);
				fflush(stdin);
			}
		}
	}
	if (reintentos == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResultado = numero;
	}

	return ret;
}

