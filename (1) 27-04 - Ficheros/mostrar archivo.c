#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define p printf
#define s scanf

void mostrar(FILE*);
void cargar(FILE*);
void grabar(FILE*, FILE*);

int main(){
    FILE *origen, *destino;
    char archivo[81], dest[81];
	system("color 9f");
	
    p("\nIngrese el nombre del archivo a crear\n");
    s("%[^\n]", archivo);

    if((origen = fopen(archivo, "w+")) == NULL)
        p("\n El archivo %s no pudo abrirse", archivo);
    else
    {
        p("\nEl archivo %s se abrio satisfactoriamente", archivo);
        cargar(origen);
        p("\n Presione una tecla para ver el contenido del archivo %s ", archivo);
		getchar();
        rewind(origen);
        mostrar(origen);
        fflush(stdin);
        
    }



    p("\nIngrese el nombre del archivo a grabar\n");
    s("%[^\n]", dest);

    if((destino = fopen(dest, "w+")) == NULL){
        p("\n El archivo %s no pudo abrirse", archivo);
    }
	
		grabar(origen, destino);
	
	
    p("\nPresione una tecla para salir del programa!!!");
        getchar();
        system("cls");

		fclose(origen);
		fclose(destino);

    return 0;

}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void mostrar (FILE *x){
char cad [81];
    while(fgets(cad,81,x)){
        p("%s", cad);
    }
}

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

void cargar(FILE* x){

    char cad[80];
	
    p("\nPara Ingresar datos finalize cada renglon con [ENTER]\n");
    p("\nPara finalizar el ingreso de datos ingrese fin de archivo EOF[^z]\n");
	
	rewind(x);
	getchar();
	
   while(gets(cad)){
	   
        fputs(cad,x);
		fputc('\n', x);
    }
}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void grabar(FILE *x, FILE *y){
	char cadena[81];
	
	rewind(x);
	
		while(fgets(cadena, 81, x)){
			
			fputs(cadena, y);	
		}
	 
}
/*----------------------------------------------------------------------------*/
	
/*----------------------------------------------------------------------------*/
