#include <stdio.h>
#include <stdlib.h>
#define CANT 3

void iniArrays(int arrayInt[], float arrayFloat[], int cantidad);
int calcularPromedio(float arrayFloat[], int cantidad, float *pResultado);
//int cargarArrays(int arrayInt, float arrayFloat, int cantidad);

int main(void) {
	setbuf(stdout, NULL);

	int edades[CANT];
	float salarios[CANT];
	float promedio;
	int numero;
	int posicion;
	char respuesta;

	iniArrays(edades, salarios, CANT);

	do {
		printf("Ingrese posicion donde cargar los valores: ");
		scanf("%d", &posicion);

		printf("\nIngrese edad: ");
		scanf("%d", &edades[posicion]);
		printf("\nIngrese salario: ");
		scanf("%f", &salarios[posicion]);

		printf("\n\nDesea continuar? s/n: ");
		fflush(stdin);
		scanf("%c", &respuesta);
	} while (respuesta == 's');

	numero = calcularPromedio(salarios, CANT, &promedio);
	if (numero == 0) {
		printf("\nEl salario promedio es: %.2f", promedio);
	}

	printf("\n\n");
	system("pause");

	return EXIT_SUCCESS;
}

void iniArrays(int arrayInt[], float arrayFloat[], int cantidad) {
	int i;
	for (i = 0; i < cantidad; i++) {
		arrayInt[i] = 0;
		arrayFloat[i] = 0;
	}
}

int calcularPromedio(float arrayFloat[], int cantidad, float *pResultado) {
	int i;
	float suma = 0;
	int contador = 0;

	for (i = 0; i < cantidad; i++) {
		if (arrayFloat[i] > 0) {
			suma = suma + arrayFloat[i];
			contador++;
		}
	}
	*pResultado = suma / contador;
	return 0;
}
