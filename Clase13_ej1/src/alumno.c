#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "alumno.h"
#include "carrera.h"

//---------------------------------------------------------------------------------------------------------------------------------------
int initAlumnos(eAlumno *array, int len) {
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
int hardcodearAlumnos(eAlumno *array, int len, int cantidad) {
	int contador = 0;
	int i;

	if (array != NULL && len > 0 && cantidad > 0) {

		eAlumno listaAuxiliar[] = { { 20000, "Juan", 21, 'm', 2, 10, 6, { 12,
				05, 2018 }, 1000, 0 }, { 20001, "Ana", 22, 'f', 6, 10, 8, { 15,
				03, 2019 }, 1001, 0 }, { 20002, "Alicia", 20, 'f', 5, 5, 5, {
				10, 05, 2018 }, 1002, 0 }, { 20003, "Miguel", 23, 'm', 6, 7,
				6.5, { 01, 02, 2013 }, 1002, 0 }, { 20004, "Gaston", 20, 'm', 2,
				8, 5, { 12, 05, 2017 }, 1003, 0 }, { 20005, "Amalia", 21, 'f',
				2, 3, 2.5, { 25, 06, 2016 }, 1000, 0 }, { 20006, "Sofia", 27,
				'f', 10, 10, 10, { 15, 10, 2019 }, 1001, 0 }, { 20007, "Diego",
				20, 'm', 9, 10, 9.5, { 12, 06, 2018 }, 1001, 0 }, { 20008,
				"Jorge", 21, 'm', 5, 9, 7, { 02, 02, 2015 }, 1002, 0 }, { 20009,
				"Clara", 25, 'f', 8, 5, 6.5, { 18, 01, 2016 }, 1003, 0 }, };
		if (cantidad <= len && cantidad <= 10) {
			for (i = 0; i < len; i++) {
				array[i] = listaAuxiliar[i]; //Guardo toda la informacion que tengo en mi array auxiliar adentro de mi array verdadero que se pasa por parametro
				contador++;
			}
		}
	}

	return contador;
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printAlumno(eAlumno alumno, eCarrera *arrayCarrera, int len) {
	char descripcionCarrera[51];

	if (arrayCarrera != NULL && len > 0
			&& (cargarDescripcionCarrera(alumno.idCarrera, arrayCarrera, len,
					descripcionCarrera) == 0)) {
		printf("%d\t%s\t%d\t%c\t%d\t%d\t%.2f\t%02d%02d%d\t%s\n", alumno.legajo,
				alumno.nombre, alumno.edad, alumno.sexo, alumno.nota1,
				alumno.nota2, alumno.promedio, alumno.fechaIngreso.dia,
				alumno.fechaIngreso.mes, alumno.fechaIngreso.anio,
				descripcionCarrera);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printAlumnos(eAlumno *arrayAlumno, int lenAlu, eCarrera *arrayCarrera,
		int lenCar) {
	int i;

	if (arrayAlumno != NULL && lenAlu > 0 && arrayCarrera != NULL
			&& lenCar > 0) {
		for (i = 0; i < lenAlu; i++) {
			printAlumno(arrayAlumno[i], arrayCarrera, lenCar);
		}
		printf("\n");
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
void sortAlumnos(eAlumno *arrayAlumno, int lenAlu, int orden, int criterio) {
	eAlumno auxiliarAlumno;
	int i, j;

	if (arrayAlumno != NULL && lenAlu > 0 && (orden = 1 || orden = -1)
			&& (criterio = 1 || criterio = -1)) {
		for (i = 0; i < lenAlu - 1; i++) {
			for (j = i + 1; j < lenAlu; j++) {
				if (arrayAlumno[i].isEmpty == 0
						&& arrayAlumno[j].isEmpty == 0) {
					if (orden == 1) {
						if (orden == 1
								&& arrayAlumno[i].promedio
										> arrayAlumno[j].promedio) {
							auxiliarAlumno = arrayAlumno[i];
							arrayAlumno[i] = arrayAlumno[j];
							arrayAlumno[j] = auxiliarAlumno;
						} else {
							if (orden == -1
									&& arrayAlumno[i].promedio
											< arrayAlumno[j]) {
								auxiliarAlumno = arrayAlumno[i];
								arrayAlumno[i] = arrayAlumno[j];
								arrayAlumno[j] = auxiliarAlumno;
							}
						}
					} else {
						if (orden == -1
								&& strcmp(arrayAlumno[i].nombre,
										arrayAlumno[j].nombre) > 0) {
							auxiliarAlumno = arrayAlumno[i];
							arrayAlumno[i] = arrayAlumno[j];
							arrayAlumno[j] = auxiliarAlumno;
						}
					}
				}
			}
		}
	}
	printf("\nAlumnos ordenados.");
}
