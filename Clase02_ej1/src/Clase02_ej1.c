#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int num1;
	int num2;
	int suma;

	printf("Ingrese un numero: ");
	scanf("%d", &num1);
	printf("Ingrese otro: ");
	scanf("%d", &num2);
	suma = num1 + num2;
	printf("La suma de %d + %d es %d", num1, num2, suma);

	system("PAUSE");

	return 0;
}
