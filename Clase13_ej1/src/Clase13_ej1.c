#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "alumno.h"
#include "carrera.h"

#define TAMALU 3
#define TAMCAR 4

int main(void) {
	setbuf(stdout, NULL);

	eAlumno lista[TAMALU];
	eCarrera carreras[] = { { 1000, "TUP", 0 }, { 1001, "TUSI", 0 }, { 1002,
			"LIC", 0 }, { 1003, "ING", 0 } };
	int legajo = 20000; //Porque me piden que los legajos empíezan en 20000
	char salir = 'n';
	char salirSub = 'n';

	initAlumnos(lista, TAMALU);

	legajo = legajo + hardcodearAlumnos(lista, TAMALU, 10); //Ahora legajo va a valer 20009 y asi el proximo ingresado va a ser 20010 y no se van a repetir legajos

	return EXIT_SUCCESS;
}
