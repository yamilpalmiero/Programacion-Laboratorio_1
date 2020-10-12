#include "alumno.h"
#include "carrera.h"

#ifndef INFORMES_H_
#define INFORMES_H_

#endif /* INFORMES_H_ */

/*
 * brief Muestra todos los alumnos que cursan esa carrera
 * param param arrayAlumnos Array de alumnos
 * param lenAlu Tamaño del array de alumnos
 * param arrayCarreras Array de carreras
 * param lenCar Tamaño del array de carreras
 * return Retorna 0 si salio OK y -1 si no
 */
int listarAlumnosPorCarrera(eAlumno *arrayAlumnos, int lenAlu,
		eCarrera *arrayCarreras, int lenCar);

/*
 * brief Muestra la cantidad de alumnos que cursan esa carrera
 * param param arrayAlumnos Array de alumnos
 * param lenAlu Tamaño del array de alumnos
 * param arrayCarreras Array de carreras
 * param lenCar Tamaño del array de carreras
 * return Retorna 0 si salio OK y -1 si no
 */
int contarAlumnosPorCarrera(eAlumno *arrayAlumnos, int lenAlu,
		eCarrera *arrayCarreras, int lenCar);

/*
 * brief Muestra todos los alumnos que cursan esa carrera en particular
 * param param arrayAlumnos Array de alumnos
 * param lenAlu Tamaño del array de alumnos
 * param arrayCarreras Array de carreras
 * param lenCar Tamaño del array de carreras
 * param idCarrera Dato id de esa carrera especifica
 * return Retorna 0 si salio OK y -1 si no
 */
int cargarAlumnosPorCarrera(eAlumno *arrayAlumnos, int lenAlu,
		eCarrera *arrayCarreras, int lenCar, int idCarrera);

/*
 * brief Muestra los alumnos que tienen un promedio determinado
 * param arrayAlumnos Array de alumnos
 * param lenAlu Tamaño del array de alumnos
 * param arrayCarreras Array de carreras
 * param lenCar Tamaño del array de carreras
 * return Retorna 0 si salio OK y -1 si no
 */
int listarAlumnosPorPromedio(eAlumno *arrayAlumnos, int lenAlu,
		eCarrera *arrayCarreras, int lenCar);

/*
 * brief Muestra todas las carreras y los datos de los alumnos que cursan cada una de ellas
 * param arrayAlumnos Array de alumnos
 * param lenAlu Tamaño del array de alumnos
 * param arrayCarreras Array de carreras
 * param lenCar Tamaño del array de carreras
 * return Retorna 0 si salio OK y -1 si no
 */
int listarAlumnosParaCadaCarrera(eAlumno *arrayAlumnos, int lenAlu,
		eCarrera *arrayCarreras, int lenCar);

/*
 * brief Muestra todas las carreras con la cantidad de alumnos que tiene cada una
 * param arrayAlumnos Array de alumnos
 * param lenAlu Tamaño del array de alumnos
 * param arrayCarreras Array de carreras
 * param lenCar Tamaño del array de carreras
 * return Retorna 0 si salio OK y -1 si no
 */
int cargarAlumnosParaCadaCarrera(eAlumno *arrayAlumnos, int lenAlu,
		eCarrera *arrayCarreras, int lenCar);
