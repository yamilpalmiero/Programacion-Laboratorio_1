#include <stdio.h>
#include <stdlib.h>
#define CANT 5

int main(void) {
	setbuf(stdout, NULL);

	char iniNom;
	char iniNomTemp;
	char iniApe;
	char iniApeTemp;
	int temperatura;
	char sexo;
	int edad;
	float acumEdad = 0;
	int contFemenino = 0;
	int contMasculino = 0;
	int tempMax = 0;
	int i;

	for (i = 0; i < CANT; i++) {
		printf("\nInicial del nombre: ");
		fflush(stdin);
		scanf("%c", &iniNom);
		while (!((iniNom >= 65 && iniNom <= 90)
				|| (iniNom >= 97 && iniNom <= 122))) {
			printf("Error, solo puede ingresar letras. Reingrese: ");
			fflush(stdin);
			scanf("%c", &iniNom);
		}

		printf("Inicial del apellido: ");
		fflush(stdin);
		scanf("%c", &iniApe);
		while (!((iniApe >= 65 && iniApe <= 90)
				|| (iniApe >= 97 && iniApe <= 122))) {
			printf("Error, solo puede ingresar letras. Reingrese: ");
			fflush(stdin);
			scanf("%c", &iniApe);
		}

		printf("Temperatura: ");
		scanf("%d", &temperatura);
		while (!(temperatura >= 0 && temperatura <= 50)) {
			printf("Error, el valor de temperatura es invalido. Reingrese: ");
			scanf("%d", &temperatura);
		}

		printf("Sexo: ");
		fflush(stdin);
		scanf("%c", &sexo);
		while (!(sexo == 70 || sexo == 77 || sexo == 102 || sexo == 109)) {
			printf("Error, solo puede ingresar f o m: ");
			fflush(stdin);
			scanf("%c", &sexo);
		}
		if (sexo == 'f' || sexo == 'F') {
			contFemenino++;
			if (temperatura > tempMax) {
				tempMax = temperatura;
				iniNomTemp = iniNom;
				iniApeTemp = iniApe;
			}
		}
		if (sexo == 'm' || sexo == 'M') {
			contMasculino++;
		}

		printf("Edad: ");
		scanf("%d", &edad);
		while (!(edad >= 0 && edad <= 150)) {
			printf("Error, la edad es incorrecta. Reingrese: ");
			scanf("%d", &edad);
		}

		acumEdad = acumEdad + edad;
	}

	printf("\nLa cantidad de mujeres es %d y la cantidad de hombres es %d",
			contFemenino, contMasculino);
	printf("\nLa edad promedio total es de %.2f", acumEdad / CANT);
	printf("\nLa mujner con mayor temperatura es %c%c y tiene %d°C\n\n",
			iniNomTemp, iniApeTemp, tempMax);

	system("pause");

	return 0;
}

/*TAREA
 1)De 5  personas que ingresan al hospital se deben tomar y
 validar los siguientes datos.

 la inicial , temperatura, sexo y edad.

 a)informar la cantidad de personas de cada sexo.
 b)la edad promedio en total
 c)la mujer con más temperatura(si la hay)
 pedir datos y mostrar los resultados
 */
