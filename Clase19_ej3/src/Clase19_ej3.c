#include <stdio.h>
#include <stdlib.h> //para exit(1)
#include <conio.h> //para funcion getche()

#define ARCH	".\\bin.dat"
#define ESC 27

/*LECTURA-ESCRITURA DE ARCHIVOS BINARIOS que tiene datos*/
/*wb = lecto/escritura.  Si no existe->Crea. Si Existe->Pisa
 rb = lectura. Posición al comienzo.
 ab = Si no existe->Crea. Si Existe->Agrega al final
 */

struct a {
	char nombre[31];
	int edad;
};

int main(void) {
	FILE *bin;
	struct a pers, pers1;
	int cant;
	/*Para crear un archivo por primera vez se debe usar el modo w,
	 pero primero nos debemos asegurar que el archivo no exista,
	 ya que en ese caso el contenido del archivo se pisa.*/

	if ((bin = fopen(ARCH, "rb+")) == NULL) {
		if ((bin = fopen(ARCH, "wb+")) == NULL) {
			printf("No se pudo abrir el archivo");
			exit(1);
		}
	}
	/*cargo la estructura y escribo el archivo*/
	do {
		printf("\nIngrese el nombre: ");
		gets(pers.nombre);

		printf("Ingrese la edad: ");
		scanf("%d", &pers.edad);

		fflush(stdin);
		/*int fseek (FILE* fichero, long desplazamiento, int desde);
		 Desplaza la posición actual de lectura/escritura del fichero
		 a otro punto. El desplazamiento puede ser positivo (avanzar),
		 cero o negativo (retroceder).
		 La posición de origen se puede indicar con la ayuda de tres
		 constantes:
		 SEEK_SET (0, comienzo),
		 SEEK_CUR (1, actual),
		 SEEK_END (2, final)*/
		fseek(bin, 0L, SEEK_END);
		fwrite(&pers, sizeof(pers), 1, bin);

		printf("\nPresione ESC para terminar");
	} while ((getche()) != ESC);

	//se lleva el indicador de posición al principio para comenzar a leer
	rewind(bin);

	while (!feof(bin)) {
		cant = fread(&pers1, sizeof(pers1), 1, bin);

		if (cant != 1) {
			if (feof(bin)) {
				break;
			} else {
				printf("No leyo el ultimo registro");
				break;
			}
		}

		printf("\n%s\t%d", pers1.nombre, pers1.edad);
	}

	fclose(bin);
	getch();

	return 0;
}
