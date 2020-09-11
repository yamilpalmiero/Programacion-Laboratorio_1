#include <stdio.h>
#include <stdlib.h>

int calcular(int num1, int num2, int *suma, int *resta);

int main(void) {
	setbuf(stdout, NULL);

	int numero1;
	int numero2;
	int resultadoSuma = 0;
	int resultadoResta = 0;
	int retorno;

	printf("Ingrese el primer numero: ");
	scanf("%d", &numero1);
	printf("Ingrese el segundo numero: ");
	scanf("%d", &numero2);

	retorno = calcular(numero1, numero2, &resultadoSuma, &resultadoResta);

	printf("\nEl resutlado de la suma es: %d", resultadoSuma);
	printf("\nEl resutlado de la resta es: %d", resultadoResta);
	printf("\nRetorno = %d\n\n", retorno);
	system("pause");

	return 0;
}

int calcular(int num1, int num2, int *suma, int *resta) {
	*suma = num1 + num2;
	*resta = num1 - num2;
	return 0;
}
