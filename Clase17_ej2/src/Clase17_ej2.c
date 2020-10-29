#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int i;
	int var1 = 100, var2 = 200, var3 = 300, var4 = 400, var5 = 500;
	int *vec[5];

	vec[0] = &var1;
	vec[1] = &var2;
	vec[2] = &var3;
	vec[3] = &var4;
	vec[4] = &var5;

	printf("\nDireccion de memoria de var1: %p", &var1);
	printf("\nDireccion de memoria de var2: %p", &var2);
	printf("\nDireccion de memoria de var3: %p", &var3);
	printf("\nDireccion de memoria de var4: %p", &var4);
	printf("\nDireccion de memoria de var5: %p", &var5);
	printf("\n");

	for (i = 0; i < 5; i++) {
		printf("\nValor del vector %p", vec[i]);
	}
	printf("\n");

	printf("\nValor de var1: %d", var1);
	printf("\nValor de var2: %d", var2);
	printf("\nValor de var3: %d", var3);
	printf("\nValor de var4: %d", var4);
	printf("\nValor de var5: %d", var5);
	printf("\n");

	for (i = 0; i < 5; i++) {
		printf("\nValores de lo apuntado por cada elemento del vector: %d",
				*vec[i]);
		printf("\nPunteros: Valores de cada elemento del vector: %p",
				*(vec + i));
		printf(
				"\nPunteros: Valores de lo apuntado por cada elemento del vector: %d",
				**(vec + i));
		printf("\n");
	}

	system("pause");

	return EXIT_SUCCESS;
}
