#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "alumno.h"
#include "carrera.h"
#include "informes.h"

//----------------------------------------------------------------------------------------------------------------------------------------
int listarAlumnosPorCarrera(eAlumno *arrayAlumnos, int lenAlu,
		eCarrera *arrayCarreras, int lenCar) {
	int retorno = -1;
	char nombreCarrera[21];
	int idCarrera;

	if (arrayAlumnos != NULL && lenAlu > 0 && arrayCarreras != NULL
			&& lenCar > 0) {
		printCarreras(arrayCarreras, lenCar);
		utn_getCadena(nombreCarrera, "\nIngrese nombre de la carrera:",
				"\nError, debe escribir el nombre tal cual se muestra en la lista.",
				1, 21, 2);
		cargarIdCarrera(nombreCarrera, arrayCarreras, lenCar, &idCarrera);
		cargarAlumnosPorCarrera(arrayAlumnos, lenAlu, arrayCarreras, lenCar,
				idCarrera);

		retorno = 0;
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int contarAlumnosPorCarrera(eAlumno *arrayAlumnos, int lenAlu,
		eCarrera *arrayCarreras, int lenCar) {
	int retorno = -1;
	int i;
	char nombreCarrera[21];
	int idCarrera;
	int contador = 0;

	if (arrayAlumnos != NULL && lenAlu > 0 && arrayCarreras != NULL
			&& lenCar > 0) {
		printCarreras(arrayCarreras, lenCar);
		utn_getCadena(nombreCarrera, "\nIngrese nombre de la carrera:",
				"\nError, debe escribir el nombre tal cual se muestra en la lista.",
				1, 21, 2);
		cargarIdCarrera(nombreCarrera, arrayCarreras, lenCar, &idCarrera);
		for (i = 0; i < lenAlu; i++) { //Agarra todos los alumnos de esa carrera
			if (arrayAlumnos[i].idCarrera == idCarrera
					&& arrayAlumnos[i].isEmpty == 0) {
				contador++;
			}
		}
		if (contador == 0) {
			printf("\nNo hay alumnos anotados en la carrera.");
		} else {
			printf("\nHay %d alumnos cursando.", contador);
		}

		retorno = 0;
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int cargarAlumnosPorCarrera(eAlumno *arrayAlumnos, int lenAlu,
		eCarrera *arrayCarreras, int lenCar, int idCarrera) {
	int retorno = -1;
	int i;
	int flag = 0;

	if (arrayAlumnos != NULL && lenAlu > 0 && arrayCarreras != NULL
			&& lenCar > 0) {
		for (i = 0; i < lenAlu; i++) {
			if (arrayAlumnos[i].idCarrera == idCarrera //Encuentro el id de la carrera
			&& arrayAlumnos[i].isEmpty == 0) { //Esa posicion no esta dada de baja
				printAlumno(arrayAlumnos[i], arrayCarreras, lenCar);
				flag = 1; //Indica que existe un alumno en esa carrera
			}
		}
		if (flag == 0) { //No existe ningun alumno para esa carrera
			printf("\nNo hay alumnos anotados en esa carrera.\n\n");
			system("pause");
		}
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int listarAlumnosPorPromedio(eAlumno *arrayAlumnos, int lenAlu,
		eCarrera *arrayCarreras, int lenCar) { //Le paso las carreras porque lo usa la funcion printAlumno
	int retorno = -1;
	int i;
	float promedio;

	if (arrayAlumnos != NULL && lenAlu > 0 && arrayCarreras != NULL
			&& lenCar > 0) {
		utn_getFlotante(&promedio, "\nIngrese promedio: ",
				"Error, debe ser un numero entre 0 y 10.", 0, 10, 2);
		for (i = 0; i < lenAlu; i++) {
			if (arrayAlumnos[i].promedio >= promedio
					&& arrayAlumnos[i].isEmpty == 0) { //Porque se pide listar los alumnos con mismo promedio o mayor
				printAlumno(arrayAlumnos[i], arrayCarreras, lenCar);

			}
		}
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int listarAlumnosParaCadaCarrera(eAlumno *arrayAlumnos, int lenAlu,
		eCarrera *arrayCarreras, int lenCar) {
	int retorno = -1;
	int c, a; //c=Carrera; a=Alumno
	eCarrera carrera;

	if (arrayAlumnos != NULL && lenAlu > 0 && arrayCarreras != NULL
			&& lenCar > 0) {
		for (c = 0; c < lenCar; c++) { //Recorre cada carrera
			carrera = buscarCarreraPorId(arrayCarreras, lenCar,
					arrayCarreras[c].idCarrera);
			printCarrera(carrera);
			for (a = 0; a < lenAlu; a++) { //Agarra todos los alumnos de esa carrera
				if (arrayAlumnos[a].idCarrera == arrayCarreras[c].idCarrera
						&& arrayAlumnos[a].isEmpty == 0) {
					printAlumno(arrayAlumnos[a], arrayCarreras, lenCar);
				}
			}
		}
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int contarAlumnosParaCadaCarrera(eAlumno *arrayAlumnos, int lenAlu,
		eCarrera *arrayCarreras, int lenCar) {
	int retorno = -1;
	int c, a; //c=Carrera; a=Alumno
	eCarrera carrera;
	int contador = 0;

	if (arrayAlumnos != NULL && lenAlu > 0 && arrayCarreras != NULL
			&& lenCar > 0) {
		for (c = 0; c < lenCar; c++) { //Recorre cada carrera
			carrera = buscarCarreraPorId(arrayCarreras, lenCar,
					arrayCarreras[c].idCarrera);
			printCarrera(carrera);
			for (a = 0; a < lenAlu; a++) { //Agarra todos los alumnos de esa carrera
				if (arrayAlumnos[a].idCarrera == arrayCarreras[c].idCarrera
						&& arrayAlumnos[a].isEmpty == 0) {
					contador++;
				}
			}
			if (contador == 0) {
				printf("\nNohay alumnos anotados en %s", carrera.descripcion);
			} else {
				printf("\nHay %d alumnos en %s.", contador,
						carrera.descripcion);
				printf("\n\n");
			}
			contador = 0;
		}
	}

	return retorno;
}
