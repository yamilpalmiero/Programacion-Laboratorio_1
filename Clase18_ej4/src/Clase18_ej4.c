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
int empleadoSetLegajo(eEmpleado *pEmpleado, int legajo);
int empleadoSetNombre(eEmpleado *pEmpleado, char *nombre);
int empleadoSetSueldo(eEmpleado *pEmpleado, float sueldo);
int empleadoSetSexo(eEmpleado *pEmpleado, char sexo);
int empleadoGetLegajo(eEmpleado *this);
char* empleadoGetNombre(eEmpleado *this);
float empleadoGetSueldo(eEmpleado *this);
char empleadoGetSexo(eEmpleado *this);

int main() {

	//puntero a una estructura en memoria dinámica
	//eEmpleado* pEmpl= (eEmpleado*) malloc(sizeof(eEmpleado));
	eEmpleado *pEmpl = newEmpleado();

	if (pEmpl == NULL) {
		printf("No se pudo crear empleado 1");
		exit(EXIT_FAILURE);
	} else {
		pEmpl->legajo = 1234;
		strcpy(pEmpl->nombre, "Juan");
		pEmpl->sexo = 'm';
		pEmpl->sueldo = 2000;

		mostrarEmpleado(pEmpl);

		free(pEmpl);

	}

	eEmpleado *pEmpl2 = newEmpleadoParam(4321, "Ana", 'f', 4000);
	if (pEmpl2 == NULL) {
		printf("No se pudo crear empleado 2");
		exit(EXIT_FAILURE);
	} else {

		mostrarEmpleado(pEmpl2);
		free(pEmpl2);

	}

	return 0;
}

int mostrarEmpleado(eEmpleado *pUnEmpleado) {
	int error = 1;

	if (pUnEmpleado != NULL) {

		error = 0;
		printf("%d  %s  %c  %.2f\n", empleadoGetLegajo(pUnEmpleado),
				empleadoGetNombre(pUnEmpleado), empleadoGetSexo(pUnEmpleado),
				empleadoGetSueldo(pUnEmpleado));

	}

	return error;
}

eEmpleado* newEmpleado() {    //Pide memoria dinámica e inicializa los datos
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
	eEmpleado *nuevoEmpleado = newEmpleado();

	if (nuevoEmpleado != NULL) {
		if (!(empleadoSetLegajo(nuevoEmpleado, legajo)
				&& empleadoSetNombre(nuevoEmpleado, nombre)
				&& empleadoSetSexo(nuevoEmpleado, sexo)
				&& empleadoSetSueldo(nuevoEmpleado, sueldo))) {
			free(nuevoEmpleado);
			nuevoEmpleado = NULL;
		}
	}

	return nuevoEmpleado;

}
int empleadoSetLegajo(eEmpleado *pEmpleado, int legajo) {
	//Validan datos
	int retorno = 0;

	if (pEmpleado != NULL && legajo > 0) {
		pEmpleado->legajo = legajo;
		retorno = 1;
	}

	return retorno;
}
int empleadoSetSueldo(eEmpleado *pEmpleado, float sueldo) {
	int retorno = 0;

	if (pEmpleado != NULL && sueldo > 0) {
		pEmpleado->sueldo = sueldo;
		retorno = 1;
	}

	return retorno;
}
int empleadoSetSexo(eEmpleado *pEmpleado, char sexo) {
	int retorno = 0;

	if (pEmpleado != NULL && (sexo == 'm' || sexo == 'f')) {
		pEmpleado->sexo = sexo;
		retorno = 1;
	}

	return retorno;
}
int empleadoSetNombre(eEmpleado *pEmpleado, char *nombre) {
	int retorno = 0;

	if (pEmpleado != NULL && nombre != NULL) {
		strcpy(pEmpleado->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}
int empleadoGetLegajo(eEmpleado *this) {

	return this->legajo;

}
char* empleadoGetNombre(eEmpleado *this) {

	return this->nombre;

}
float empleadoGetSueldo(eEmpleado *this) {

	return this->sueldo;

}
char empleadoGetSexo(eEmpleado *this) {

	return this->sexo;

}
