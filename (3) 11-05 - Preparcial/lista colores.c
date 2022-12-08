#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	printf("\n\t\t\tTitle Este es el programa de los colores.\n\n");
	//FILE *flujo = fopen("Lista colores consola.txt", "wt+");
	//char lista[] = "Funcion: system(\"color xx\");\nPrimer caracter fondo.\nSegundo caracter texto.\n\n0 = Black\t8 = Gray\n1 = Blue\t9 = Light Blue\n2 = Green\tA = Light Green\n3 = Aqua\tB = Light Aqua\n4 = Red\t\tC = Light Red\n5 = Purple\tD = Light Purple\n6 = Yellow\tE = Light Yellow\n7 = White\tF = Bright White";
	char fondo[10], fuente[10], combinacion[10]="color ";
	char opcion='s';
	 
		//fputs(lista, flujo);
		
		
	//rewind(flujo);
	while(opcion !='n' && opcion !='N'){
		memset(fondo, '\0', sizeof(fondo));
		printf("\t\t\tELEGIR FONDO\n");
		scanf("%s", fondo);
		fflush(stdin);
		memset(fuente, '\0', sizeof(fuente));
		printf("\t\t\tELEGIR FUENTE\n");
		scanf("%s", fuente);
		fflush(stdin);
		strcat(fondo, fuente);
		strcat(combinacion, fondo);
		printf("combinacion: %s\n", combinacion);
		system(combinacion);
		memset(combinacion, '\0', sizeof(combinacion));
		strcpy(combinacion, "color ");
		printf("¿Elegir otros colores?  S/N : ");
		opcion = getchar();
	}
	
	//fclose(flujo);
	return 0;
}



/*
	colores para system("color ");
	
	0 = Black       8 = Gray
	1 = Blue        9 = Light Blue
	2 = Green       A = Light Green
	3 = Aqua        B = Light Aqua
	4 = Red         C = Light Red
	5 = Purple      D = Light Purple
	6 = Yellow      E = Light Yellow
	7 = White       F = Bright White
*/
