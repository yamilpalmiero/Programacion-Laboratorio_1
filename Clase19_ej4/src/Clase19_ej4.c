#include <stdio.h>
#include <string.h> //para strlen()
#include <stdlib.h> //para system("pause")

#define ARCH	"./Texto.txt"

/*LECTURA-ESCRITURA DE ARCHIVOS TEXTO*/
/*w = lecto/escritura.  Si no existe->Crea. Si Existe->Pisa
 r = lectura. Posición al comienzo.
 a = Si no existe->Crea. Si Existe->Agrega al final
 */

int main(void) {
	FILE *pArch;
	char palabras[30];
	system("pause");
	printf("\nSe va a generar por primera vez el archivo\n");
	if ((pArch = fopen(ARCH, "w")) == NULL) {
		printf("El archivo no puede ser abierto");
		exit(1);
	}

	printf("Ingrese un texto");
	gets(palabras);
	fflush(stdin);

	fwrite(palabras, sizeof(char), strlen(palabras), pArch);

	fclose(pArch);

	return 0;
}

/*
 int main (void)
 {
 FILE  *pArch;
 char palabras[] ="Texto para leer";
 system("pause");
 printf("\nSe va a generar por primera vez el archivo\n");
 if ((pArch=fopen(ARCH,"w"))==NULL)
 {
 printf("El archivo no puede ser abierto");
 exit(1);
 }

 fwrite(palabras,sizeof(char),strlen(palabras),pArch);

 fclose(pArch);

 return 0;
 }
 */
