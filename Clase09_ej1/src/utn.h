#ifndef UTN_H_
#define UTN_H_

#endif /* UTN_H_ */

/*
 * brief Toma un numero entero por teclado y lo devuelve por puntero
 * param Direccion de memoria donde se guardara el entero
 * param Mensaje que pide el dato numerico
 * param Mensaje de error cuando lo que se ingresa por teclado no es lo solicitado
 * param Valor minimo posible
 * param Valor maximo posible
 * param Cantidad de intentos para ingresar el dato correctamente
 */
int utn_getEntero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);

/*
 * brief Toma un numero con decimales por teclado y lo devuelve por puntero
 * param Direccion de memoria donde se guardara el flotante
 * param Mensaje que pide el dato numerico
 * param Mensaje de error cuando lo que se ingresa por teclado no es lo solicitado
 * param Valor minimo posible
 * param Valor maximo posible
 * param Cantidad de intentos para ingresar el dato correctamente
 */
float utn_getFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);

/*
 * brief Recibe un array de enteros y lo inicializa en cero
 * param Array de enteros
 * param Cantidad de elementos del array
 */
void utn_iniArrayEnteros(int array[], int cantidad);

/*
 * brief Recibe un array de flotantes y lo inicializa en cero
 * param Array de flotantes
 * param Cantidad de elementos del array
 */
void utn_iniArrayFlotantes(float array[], int cantidad);

/*
 * brief Recibe un array de caracteres y lo inicializa en blanco
 * param Array de caracteres
 * param Cantidad de elementos
 */
void utn_iniArrayCaracteres(char array[], int cantidad);

/*
 * brief Imprime un array de enteros
 * param Array de enteros
 * param Array de flotantes
 * param Cantidad de elementos de los array
 */
void utn_imprimirElemento(int arrayInt[], float arrayFloat[], int cantidad);

/*
 * brief Imprime un array de enteros
 * param Array de enteros
 * param Cantidad de elementos
 */
void utn_imprimirElementos(float array[], int cantidad);

/*
 * brief Recibe un array de flotantes y devuelve el promedio por puntero
 * param Array de numeros flotantes
 * param Cantidad de elementos
 * param Posicion de memoria de la variable donde se guardara el resultado del promedio
 */
void utn_calcularPromedio(float arrayFloat[], int cantidad, float *pResultado);

/*
 * brief Recibe arrays para ser cargado con sus valores de manera aleatoria
 * param Array de enteros
 * param Array de flotantes
 * param Cantidad de elementos de los array paralelos
 */
void utn_cargarArrays(int arrayInt[], float arrayFloat[], int cantidad);
