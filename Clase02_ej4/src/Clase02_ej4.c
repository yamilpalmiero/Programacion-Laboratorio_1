#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);

	int numero;
	int contador = 0;
	int i;

	printf("Ingrese un numero entero: ");
	scanf("%d", &numero);

	for (i = 1; i < numero; i++)
	{
		if (numero % i == 0)
		{
			printf("\n%d es divisor de %d", i, numero);
			contador++;
		}
	}

	printf("\nLa cantidad de numeros divisores es: %d\n\n", contador);

	system("PAUSE");

	return 0;
}
