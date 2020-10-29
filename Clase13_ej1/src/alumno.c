#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "alumno.h"
#include "carrera.h"

#define TAM 51

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

	if (arrayAlumno != NULL && lenAlu > 0 && (orden == 1 || orden == -1)
			&& (criterio == 1 || criterio == -1)) {
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
											< arrayAlumno[j].promedio) {
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
//---------------------------------------------------------------------------------------------------------------------------------------
int addAlumno(eAlumno *arrayAlumnos, int lenAlu, eCarrera *arrayCarreras,
		int lenCar, int *contadorLegajo) {
	int retorno = -1;
	int posicion;

	if (arrayAlumnos != NULL && lenAlu > 0 && contadorLegajo != NULL) {
		if (buscarLibre(arrayAlumnos, lenAlu, &posicion) == -1) {
			printf("\nNo hay lugares vacios.");
		} else {
			(*contadorLegajo)++;
			arrayAlumnos[posicion].legajo = *contadorLegajo; //Legajo coincide con el indice y es autoincremental
			utn_getCadena(arrayAlumnos[posicion].nombre, "\nIngrese nombre: ",
					"\nError.", 1, TAM, 2);
			printf("\nIngrese sexo f/m: ");
			fflush(stdin);
			scanf("%c", &arrayAlumnos[posicion].sexo);
			utn_getEntero(&arrayAlumnos[posicion].nota1,
					"\nIngrese nota 1er parcial: ", "\nError.", 1, 10, 2);
			utn_getEntero(&arrayAlumnos[posicion].nota2,
					"\nIngrese nota 2do parcial: ", "\nError.", 1, 10, 2);
			arrayAlumnos[posicion].promedio =
					((float) arrayAlumnos[posicion].nota1
							+ arrayAlumnos[posicion].nota2) / 2;
			printf("\nFecha de ingreso: ");
			scanf("%d/%d/%d", arrayAlumnos[posicion].fechaIngreso.dia,
					arrayAlumnos[posicion].fechaIngreso.mes,
					arrayAlumnos[posicion].fechaIngreso.anio);
			printCarreras(arrayCarreras, lenCar);
			utn_getEntero(&arrayAlumnos[posicion].idCarrera,
					"\nIngrese Id de carrera: ", "\nError.", 1000, 1003, 2);
			arrayAlumnos[posicion].isEmpty = 0;
			printf(
					"\nPosicion: %d\nLegajo: %d\nNombre: %s\nEdad: %d\nSexo: %c\nNota 1: %d\nNota 2: %d\nPromedio: %.2f\nFecha de ingreso: %d/%d/%d\nId carrera",
					posicion, arrayAlumnos[posicion].legajo,
					arrayAlumnos[posicion].nombre, arrayAlumnos[posicion].edad,
					arrayAlumnos[posicion].sexo, arrayAlumnos[posicion].nota1,
					arrayAlumnos[posicion].nota2,
					arrayAlumnos[posicion].promedio,
					arrayAlumnos[posicion].fechaIngreso.dia,
					arrayAlumnos[posicion].fechaIngreso.mes,
					arrayAlumnos[posicion].fechaIngreso.anio,
					arrayAlumnos[posicion].idCarrera);
			retorno = 0;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int calcularPromedioTotal(eAlumno *array, int len, float *pResultado) {
	int retorno = -1;
	int i;
	int suma1 = 0;
	int suma2 = 0;
	int contador = 0;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (array[i].isEmpty == 0) {
				suma1 = suma1 + array[i].nota1;
				suma2 = suma2 + array[i].nota2;
				contador++;
				break;
			}
		}
		*pResultado = (float) (suma1 + suma2) / contador;
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int arrayVacio(eAlumno *array, int len) {
	int retorno = 1;
	int i;

	if (array != NULL && len >= 0) {
		for (i = 0; i < len; i++) {
			if (array[i].isEmpty == 0) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int buscarLibre(eAlumno *array, int len, int *posicion) {
	int retorno = -1;
	int i;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (array[i].isEmpty == 1) {
				*posicion = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
