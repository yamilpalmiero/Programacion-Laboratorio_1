#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	char opcion;
	char respuesta;
	int flag = 0;
	int flag2 = 0;

	printf("*****MENU*****");

	do {
		printf("\na- Saludar.");
		printf("\nb- Brindar.");
		printf("\nc- Despedirse.");
		printf("\nd- Salir.");
		printf("\n\nIngrese una opcion: ");
		fflush(stdin);
		scanf("%c", &opcion);

		switch (opcion) {
		case 'a':
			printf("Hola!\n");
			flag = 1;
			break;

		case 'b':
			if (flag == 0) {
				printf("Debe saludar antes de brindar.\n");
				system("pause");
			} else {
				printf("Chin Chin!\n");
				flag2 = 1;
			}
			break;

		case 'c':
			if (flag == 0) {
				printf("Debe saludar antes de irse.\n");
				system("pause");
			} else {
				printf("Chau!\n");
			}
			break;

		case 'd':
			if (flag2 == 0) {
				printf("Debe brindar antes de despedirse.\n");
				system("pause");
			} else {
				printf("Esta seguro que desea salir? s/n: ");
				fflush(stdin);
				scanf("%c", &respuesta);
			}
		}

	} while (opcion != 's');
	return EXIT_SUCCESS;
}
