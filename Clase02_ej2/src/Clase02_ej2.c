#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	char letra1;
	char letra2;
	char nombre[5] = "Pepe"; //el 5to caracter seria para el \0 que marca el final

	printf("Ingrese una letra: ");
	fflush(stdin); // esto va siempre antes de tomar por teclado caracteres o strings
	scanf("%c", &letra1);
	printf("Ingrese otra letra: ");
	fflush(stdin);
	scanf("%c", &letra2);

	printf("\nEl valor de nombre es: %s", nombre);
	printf("\nLa primera letra es: %c", letra1);
	printf("\nLa segunda letra es: %c\n\n", letra2);

	system("PAUSE");

	return 0;
}
