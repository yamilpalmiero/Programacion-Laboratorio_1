#include <stdio.h>
#include <stdlib.h>
#define CANT 3

int main(void) {
	setbuf(stdout, NULL);

	int edades[CANT];
	int salarios[CANT];
	char sexo[CANT];
	int posicion;
	char respuesta;
	int i;

	for (i = 0; i < CANT; i++) {
		edades[i] = 0;
		salarios[i] = 0;
		sexo[i] = ' ';
	}

	printf("POS\tLEGAJO\tEDAD\tSALARIO\tSEXO");
	for (i = 0; i < CANT; i++) {
		printf("\n%d\t%d\t%d\t%d\t%c", i, i + 1, edades[i], salarios[i],
				sexo[i]);
	}

	do {
		printf("\n\nIngrese la posicion donde cargar datos: ");
		scanf("%d", &posicion);
		printf("Edad entre 18 y 75 anios: ");
		scanf("%d", &edades[posicion]);
		while (edades[posicion] < 18 || edades[posicion] > 75) {
			printf("Error, reingrese: ");
			scanf("%d", &edades[posicion]);
		}
		printf("Salario: ");
		scanf("%d", &salarios[posicion]);
		while (salarios[posicion] <= 0) {
			printf("Error, reingrese: ");
			scanf("%d", &salarios[posicion]);
		}
		printf("Sexo f/m: ");
		fflush(stdin);
		scanf("%c", &sexo[posicion]);
		while (!(sexo[posicion] == 'f' || sexo[posicion] == 'm')) {
			printf("Error, reingrese: ");
			fflush(stdin);
			scanf("%c", &sexo[posicion]);
		}
		printf("\nDesea continuar? s/n: ");
		fflush(stdin);
		scanf("%c", &respuesta);
		while (!(respuesta == 's' || respuesta == 'n' || respuesta == 'n')) {
			printf("Error, reingrese: ");
			fflush(stdin);
			scanf("%c", &respuesta);
		}

	} while (respuesta == 's' || respuesta == 'S');

	system("cls");

	printf("\n\nPOS\tLEGAJO\tEDAD\tSALARIO\tSEXO");
	for (i = 0; i < CANT; i++) {
		printf("\n%d\t%d\t%d\t%d\t%c", i, i + 1, edades[i], salarios[i],
				sexo[i]);
	}

	printf("\n\n");
	system("pause");

	return EXIT_SUCCESS;
}
