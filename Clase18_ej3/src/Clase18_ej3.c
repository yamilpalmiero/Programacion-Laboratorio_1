#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Constructor

typedef struct {
	int legajo;
	char nombre[31];
	char sexo;
	float sueldo;
} eEmpleado;

int mostrarEmpleado(eEmpleado *pUnEmpleado);
eEmpleado* newEmpleado(); //encapsula el malloc
eEmpleado* newEmpleadoParam(int legajo, char *nombre, char sexo, float sueldo); //encapsula el malloc

int main() {
	int retorno;
	//puntero a una estructura en memoria dinámica
	//eEmpleado* pEmpl= (eEmpleado*) malloc(sizeof(eEmpleado));
	eEmpleado *pEmpl = newEmpleado();
	eEmpleado *pEmpl2 = newEmpleadoParam(4321, "Ana", 'f', 4000);

	if (pEmpl != NULL) {
		pEmpl->legajo = 1234;
		strcpy(pEmpl->nombre, "Juan");
		pEmpl->sexo = 'm';
		pEmpl->sueldo = 2000;

		retorno = mostrarEmpleado(pEmpl);
		free(pEmpl);

	}
	if (pEmpl2 != NULL) {
		retorno = mostrarEmpleado(pEmpl2);

		free(pEmpl2);
	}

	return 0;
}

int mostrarEmpleado(eEmpleado *pUnEmpleado) {
	int error = 1;

	if (pUnEmpleado != NULL) {
		error = 0;
		printf("%d  %s  %c  %.2f\n", pUnEmpleado->legajo, pUnEmpleado->nombre,
				pUnEmpleado->sexo, pUnEmpleado->sueldo);

	}

	return error;
}
eEmpleado* newEmpleado() {
	eEmpleado *nuevoEmpleado = NULL;
	nuevoEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));

	if (nuevoEmpleado != NULL) {
		nuevoEmpleado->legajo = 0;
		strcpy(nuevoEmpleado->nombre, " ");
		nuevoEmpleado->sexo = ' ';
		nuevoEmpleado->sueldo = 0;
	}

	return nuevoEmpleado;

}

eEmpleado* newEmpleadoParam(int legajo, char *nombre, char sexo, float sueldo) {
	//Antes de cargar deben validarse los datos
	eEmpleado *nuevoEmpleado = NULL;
	nuevoEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));

	if (nuevoEmpleado != NULL) {
		nuevoEmpleado->legajo = legajo;
		strcpy(nuevoEmpleado->nombre, nombre);
		nuevoEmpleado->sexo = sexo;
		nuevoEmpleado->sueldo = sueldo;
	}

	return nuevoEmpleado;

}
