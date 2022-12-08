#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FIJO 35000;
typedef struct{
	int cod_chof;
	char nom_chof[30];
	int kms;
	int cantv;
	int sueldo;
} registro;

void extraer(char[] , registro *);
void volcarInfo(FILE *, registro);
void leerBinario(FILE *);
void ordenarBin(FILE *);
int main(){
	FILE *lectura = fopen("viajes.txt", "rt");
	FILE *binario = fopen("resumen.dat", "wb+");
	registro viaje;
	char cadena[30];
	
		if(lectura == NULL){
			printf("El archivo no pudo abrirse.\n");
			return 1;
		}
		
			while(fgets(cadena, sizeof(cadena), lectura)){
				extraer(cadena, &viaje);
				volcarInfo(binario, viaje);	
			}
			leerBinario(binario);
			
	fclose(lectura);
	fclose(binario);
	return 0;
}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void extraer(char cadena[], registro *viaje){
	char *token;
	
		token = strtok(cadena ,",");
		viaje->cod_chof = atoi(token);
		token = strtok(NULL, ",");
		strcpy(viaje->nom_chof, token);
		token = strtok(NULL, ",");
		viaje->kms = atoi(token);
		
}
/*----------------------------------------------------------------------------*/
	
/*----------------------------------------------------------------------------*/
void volcarInfo(FILE *binario, registro viaje){
	int existe=0;
	registro regAux;
	
	rewind(binario);
	
	while(!feof(binario) && existe==0){
		fread(&regAux, sizeof(registro), 1, binario);
		
			if(viaje.cod_chof == regAux.cod_chof){
				existe = 1;
				break;
			}
	}	
	
	if(existe){ //codigo de chofer repetido
		regAux.cantv++;
		regAux.kms += viaje.kms;
		regAux.sueldo += (viaje.kms*100);
		fseek(binario,sizeof(registro)*(-1L),SEEK_CUR);
		fwrite(&regAux, sizeof(registro) ,1,binario);
	}
	else{ //primera vez que aparece
		viaje.cantv = 1;
		viaje.sueldo = (viaje.kms*100) + FIJO;
		fseek(binario, 0L, SEEK_END);
		fwrite(&viaje,  sizeof(registro), 1, binario);
	}
		
	
}
/*----------------------------------------------------------------------------*/
	
/*----------------------------------------------------------------------------*/
void leerBinario(FILE *binario){
	registro lista;
	
	rewind(binario);
	printf("CODIGO DE CHOFER | NOMBRE \t    | KILOMETROS | VIAJES | SUELDO\n");
	
	fread(&lista, sizeof(registro), 1, binario);
		while(!feof(binario)){
			
			printf("\t%d\t  %-20s\t%d\t      %d\t     %d", lista.cod_chof, lista.nom_chof, lista.kms, lista.cantv, lista.sueldo);
			if(lista.cantv>2){
				printf("\tPremio de $5000.- ");
			}
			printf("\n");
			fread(&lista, sizeof(registro), 1, binario);
		}
}
/*----------------------------------------------------------------------------*/
	
/*----------------------------------------------------------------------------*/
/*void ordenarBin(FILE *bin){
	registro lis, mayor=0;
	
	rewind(bin);
	printf("LISTA ORDENADA POR KILOMETROS\n");
	
	
	fread(&lis, sizeof(registro), 1, bin);
		while(!feof(bin)){
			fseek(f,0,SEEK_END);
			nReg=ftell(f)/sizeof(Movimiento);
		}
}
*/
