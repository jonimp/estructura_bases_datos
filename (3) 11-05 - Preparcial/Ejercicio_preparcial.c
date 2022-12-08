/*
Ejercicio preparcial de archivos:
Se necesita confeccionar las estadisticas de viajes de la empresa de transporte "Lenta pero segura".

Por un error tipográfico se recibe en un archivo de texto la infomación necesaria en cadenas de
seis caracteres sin separación que corresponden a cada uno de los viajes relizados, los tres
primeros caracteres corresponden al Código del chofer y los tres últimos a la Cantidad de Kms recorridos.
Tenga en cuenta que cada chofer puede haber realizado varios viajes.

Se deberá almacenar en un archivo binario la información (sin repeticiones) con los siguientes requerimientos
sabiendo que el valor del Km recorrido es de $50.-

 | Cod. de Chofer | Kms. recorridos | Cant de viajes | Recaudación |

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SI 1
#define NO 0

typedef struct{
    int codChofer;
    int cantViajes;
    int kms;
    int rec;
} registro;

void extraer(char[], int*, int*);
void guardarEnBinario(FILE*, registro);
void mostrarBinario(FILE*);
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
int main(){
FILE *leer, *bin;
char cadena[10];
int codigo, kilometros;
registro reg;

leer = fopen("viajes.txt", "rt");
bin = fopen("tabla.dat", "wb+");

    while(fgets(cadena, sizeof(cadena), leer)){
		
		extraer(cadena, &codigo, &kilometros);
		reg.codChofer = codigo;
		reg.kms = kilometros;
		guardarEnBinario(bin, reg);
	}
	
	mostrarBinario(bin);

fclose(leer);
fclose(bin);
return 0;
}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/	
void extraer(char cad[], int *cod, int *km){
	char destino[3];
	
		memset(destino, '\0', sizeof(destino));
		strncpy(destino, cad, 3);
		*cod = atoi(destino);
		memset(destino, '\0', sizeof(destino));
		strncpy(destino, cad + 3, 3);
		*km = atoi(destino);
}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void guardarEnBinario(FILE* binario, registro reg){
	int existe = NO;
	registro regAux;

	rewind (binario);
		
		while(!feof(binario) && existe == NO){
			fread(&regAux, sizeof(registro), 1, binario);	
			
			if(regAux.codChofer == reg.codChofer){
				existe = SI;
				break;
			}
		}
		
		if(existe){ //cuando Se repite el codigo de chofer
			regAux.kms += reg.kms;
			regAux.rec += (reg.kms*50);
			regAux.cantViajes++;
			fseek (binario,sizeof(registro)*(-1L),SEEK_CUR);
			fwrite(&regAux, sizeof(registro), 1, binario);
		}
		else { //Primera vez que aparece
			reg.cantViajes = 1;
			reg.rec = (reg.kms*50);
			fseek (binario,0L,SEEK_END);
			fwrite(&reg, sizeof(registro), 1, binario);
		}

}
/*----------------------------------------------------------------------------*/
	
/*----------------------------------------------------------------------------*/
void mostrarBinario(FILE* binario){
	registro r;
	
	rewind(binario);
	printf("Contenido del archivo binario\n\n");
	printf("Codigo de chofer \t Cantidad de viajes \t Kilometros recorridos \t Recaudación \n\n");
	
	fread(&r, sizeof(registro), 1, binario);
		while(!feof(binario)){
			printf("\t%d \t\t\t %d \t\t\t %d \t\t %d\n", r.codChofer, r.cantViajes, r.kms, r.rec);
			fread(&r, sizeof(registro), 1, binario);
		}
}
