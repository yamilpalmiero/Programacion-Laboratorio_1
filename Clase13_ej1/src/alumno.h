#ifndef ALUMNO_H_
#define ALUMNO_H_

typedef struct {
	int dia;
	int mes;
	int anio;
} eFecha;

typedef struct {
	int legajo; //(PK)
	char nombre[51];
	int edad;
	char sexo;
	int nota1;
	int nota2;
	float promedio;
	eFecha fechaIngreso;
	int idCarrera; //(FK) Cada alumno estudia una carrera pero cada carrera es estudiada por varios alumnos (1,n), entonces me traigo la PK de la entidad eCarrera
	int isEmpty;
} eAlumno;

#endif /* ALUMNO_H_ */

/*
 * brief Indica que todas las posiciones del array estan vacias
 * param eAlumno Array de alumnos
 * param len Tamaño del array
 * return Retorna 0 si pudo inicializar bien y -1 si no
 */
int initAlumnos(eAlumno *array, int len);

/*
 * brief Hardcodea uno o varios datos de tipo eAlumno con un maximo de 10 elementos
 * param array Array de alumnos
 * param len Tamaño del array de alumnos
 * param cantidad Cantidad de datos que se desean hardcodear
 * return Retorna 0 si pudo realizar la accion correctamente y -1 si no
 */
int hardcodearAlumnos(eAlumno *array, int len, int cantidad);

/*
 * brief Recibe una estructura e imprime sus datos
 * param array Estructura que recibe
 */
void printAlumno(eAlumno alumno, eCarrera *arrayCarrera, int len);

/*
 * brief Recibe un array de tipo estructura e imprime los datos de cada estructura
 * param array Array de estructuras
 * param len Tamaño del array
 */
void printAlumnos(eAlumno *arrayAlumno, int lenAle, eCarrera *arrayCarrera,
		int lenCar);

/*
 * brief Recibe un array y lo ordena segun orden y criterio
 * param arrayAlumno Array de estructuras de alumnos
 * param lenAlu Tamaño del array de alumnos
 * param arrayCarrera Array de estructuras de carreras
 * param lenCar Tamaño del array de carreras
 * param orden Ordena de manera ascendente (1) o descendente (-1)
 * param criterio Ordena con criterio promedio (1) o apellido (-1)
 */
void sortAlumnos(eAlumno *arrayAlumno, int lenAlu, int orden, int criterio);

