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

int main() {
	int retorno;
	//puntero a una estructura en memoria dinámica
	eEmpleado *pEmpl = (eEmpleado*) malloc(sizeof(eEmpleado));

	pEmpl->legajo = 1234;
	strcpy(pEmpl->nombre, "Juan");
	pEmpl->sexo = 'm';
	pEmpl->sueldo = 2000;

	retorno = mostrarEmpleado(pEmpl);

	free(pEmpl);
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
