#ifndef CARRERA_H_
#define CARRERA_H_

typedef struct {
	int idCarrera; //(PK)
	char descripcion[51];
	int isEmpty;
} eCarrera;

#endif /* CARRERA_H_ */

/*
 * brief Indica que todas las posiciones del array estan vacias
 * param eCarrera Array de carreras
 * param len Tamaño del array
 * return Retorna 0 si pudo inicializar bien y -1 si no
 */
int initCarreras(eCarrera *array, int len);

/*
 * brief Recibe una estructura e imprime sus datos
 * param array Estructura que recibe
 */
void printCarrera(eCarrera carrera);

/*
 * brief Recibe un array de tipo estructura e imprime los datos de cada estructura
 * param array Array de estructuras
 * param len Tamaño del array
 */
void printCarreras(eCarrera *array, int len);

/*
 * brief Recibe un id y valida que exista
 * param array Array de tipo estructura con todas las carreras
 * param len Tamaño del array
 * param idCarrera Dato id que se desea validar
 * return Retorna 0 si en el array encuentra un id como el pasado por parametro y -1 si no lo encuentra
 */
int validarIdCarrera(eCarrera *array, int len, int idCarrera);

/*
 * brief Recibe el id de una carrera y devuelve su descripcion
 * param idCarrera Id de la carrera
 * param array Array de estructuras de carreras
 * param len Tamaño del array
 * param *descripcion Puntero a la posicion de memoria donde se guardara la descripcion de la carrera
 * return Retorna 0 si salio ok y -1 si no
 */
int cargarDescripcionCarrera(int idCarrera, eCarrera *array, int len,
		char *descripcion);
