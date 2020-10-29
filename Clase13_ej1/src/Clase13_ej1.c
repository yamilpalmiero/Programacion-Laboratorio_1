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
	int opcionMenuPrincipal;
	int opcionMenuInformes;
	int contadorLegajoAlumno;
	char salir = 'n';
	char salirSub = 'n';

	if (initAlumnos(lista, TAMALU) == 0) {
		printf("\nLa lista se inicializo correctamente.");
	} else {
		printf("\nError al inicializar.");
	}

	legajo = legajo + hardcodearAlumnos(lista, TAMALU, 10); //Ahora legajo va a valer 20009 y asi el proximo ingresado va a ser 20010 y no se van a repetir legajos

	do {
		opcionMenuPrincipal = menu();

		switch (opcionMenuPrincipal) {
		case 1:
			addAlumno(lista, TAMALU, carreras, TAMCAR, &contadorLegajoAlumno);
			break;
		/*case 2:
			if (arrayVacio(lista, TAMALU)) {
				printf("\nAun no se cargo ningun alumno.\n\n");
				system("pause");
			} else {
				modifyEmployee(lista, TAMALU);
			}
			break;
		case 3:
			if (arrayVacio(list, CANTIDAD_EMPLEADOS)) {
				printf("\nAun no se cargo ningun empleado.\n\n");
				system("pause");
			} else {
				removeEmployee(list, CANTIDAD_EMPLEADOS);
			}
			break;
		case 4:
			utn_getEntero(&opcionSubmenu,
					"\n\n1) Empleados ordenados por apellido y sector \n2) Total y promedio de salarios y cuantos empleados superan el salario promedio",
					"\nError", 1, 2, 2);
			switch (opcionSubmenu) {
			case 1:
				sortEmployees(list, CANTIDAD_EMPLEADOS, ORDEN_ASCENDENTE);
				printEmployees(list, CANTIDAD_EMPLEADOS);
				break;
			case 2:
				calcularPromedioSalario(list, CANTIDAD_EMPLEADOS,
						&promedioSalarios, &sumaSalarios);
				printf(
						"\nSuma total de salarios: %.2f\nPromedio: %.2f\nEmpleados con salario mayor al promedio: %d",
						sumaSalarios, promedioSalarios,
						salarioMayorPromedio(list, CANTIDAD_EMPLEADOS,
								promedioSalarios));
				break;
			}
			break;
		case 5:
			printf("\nSalio!\n\n");
			system("pause");
			break;*/
		}
	} while (opcionMenuPrincipal != 9);

	return EXIT_SUCCESS;
}
