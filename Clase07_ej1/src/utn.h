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
