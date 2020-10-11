#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "carrera.h"
#include "alumno.h"

//---------------------------------------------------------------------------------------------------------------------------------------
int initCarreras(eCarrera *array, int len) {
	int retorno = -1;
	int i;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			array[i].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printCarrera(eCarrera carrera) {

	printf("%d\t%s", carrera.idCarrera, carrera.descripcion);

}
//---------------------------------------------------------------------------------------------------------------------------------------
void printCarreras(eCarrera *array, int len) {
	int i;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			printCarrera(array[i]);
		}
		printf("\n");
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
int validarIdCarrera(eCarrera *array, int len, int idCarrera) {
	int retorno = -1;
	int i;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (array[i].idCarrera == idCarrera) {
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int cargarDescripcionCarrera(int idCarrera, eCarrera *array, int len,
		char *descripcion) {
	int retorno = -1;
	int i;

	if (array != NULL && len > 0 && descripcion != NULL) {
		for (i = 0; i < len; i++) {
			if (array[i].idCarrera == idCarrera) {
				strncpy(descripcion, array[i].descripcion, 51);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
