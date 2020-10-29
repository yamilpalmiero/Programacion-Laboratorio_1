#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int vec[5];
	int *p;
	int i;

	p = vec; //El puntero p apunta al primer elemento del array vec

	printf("--> Direccion de p: %p", &p);
	printf("\n--> Elemento de p: %p", p);
	printf("\n--> Direccion de vec: %p", p);

	for (i = 0; i < 5; i++) {
		vec[i] = i;
	}

	for (i = 0; i < 5; i++) {
		printf("\n\nElemento Nomenclatura vectorial: %d", vec[i]);
		printf("\nElemento Aritmetica de punteros: %d", *(p + i));
		printf("\nDireccion de vec[i]: %p", &vec[i]);
		printf("\nDireccion de Punteros: %p", (p + i));
	}

	return EXIT_SUCCESS;
}
