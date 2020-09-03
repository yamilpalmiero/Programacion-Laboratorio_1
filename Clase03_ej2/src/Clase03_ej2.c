#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  //getchar()
#include <conio.h>  //console input-output getch()

int main() {
	setbuf(stdout, NULL);
	/*  char x='q';
	 printf("Se ingreso el valor: %d", x); // muestra el ASCII

​

​
getchar(): Permite ingresar un caracter. Espera que presione enter y lee el 1er caracter
char x;
	 printf("Ingrese un caracter: ");
	 //scanf("%c", &x);
	 x = getchar();
	 printf("\nSe ingreso el valor: %c" ,x );

​
​
​
	getch(): Permite ingresar un caracter, no espera que presione enter.
	 Se usa para pausar sin asignar su resultado
	   char x;
	 printf("Ingrese un caracter: ");
	 //scanf("%c", &x);
	 x = getch();
	 printf("\nSe ingreso el valor: %c" ,x );
	 */

//getche(): Permite ingresar un caracter, no espera que presione enter pero lo muestra
	char x;
	printf("Ingrese un caracter: ");
	//scanf("%c", &x);
	x = getche();
	printf("\nSe ingreso el valor: %c", x);

	return 0;
}

