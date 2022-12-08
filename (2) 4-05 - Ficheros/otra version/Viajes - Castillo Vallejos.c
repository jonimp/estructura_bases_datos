#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int cod_chof;
    char nom_chof[30];
    int kms;
    int cantv;
    int sueldo;
} registro;

void ordenar (registro[], int);
void sacar (char[], registro*, FILE*);
void mostrarBinario(FILE*);
void mostrarTexto(FILE*);
void ordenarBinario (FILE*, FILE*);

int main () {
    system("color 1f");
    FILE *texto, *bin1, *bin2;
    char cad[80];
    registro r;
    texto = fopen("viajes.txt","rt+");
    bin1 = fopen("resumen.dat","wb+");
    bin2 = fopen("resumenOrd.dat","wb+");
    if (texto != NULL && bin1 != NULL && bin2 != NULL) {
        printf("\nPresione una tecla para leer el archivo original\n\n");
        getchar();
        mostrarTexto(texto);
        rewind(texto);
        while (fgets(cad,81,texto)) {
            sacar(cad,&r,bin1);
        }
        printf("\nPresione una tecla para leer el archivo binario\n\n");
        getchar();
        mostrarBinario(bin1);
        ordenarBinario(bin1,bin2);
        printf("\nPresione una tecla para leer el archivo ordenado\n\n");
        getchar();
        mostrarBinario(bin2);
        fclose(texto);
        fclose(bin1);
        fclose(bin2);
    }
    else {
        printf("No se pudieron abrir o crear los archivos\n");
    }
    getchar();
    return 0;
}

void ordenar (registro x[], int y) {
    int i, cota = y-1, k = 1;
    registro aux;
    while (k) {
        k = 0;
        for (i = 0; i < cota; i++) {
            if (x[i].kms > x[i+1].kms) {
                aux = x[i];
                x[i] = x[i+1];
                x[i+1] = aux;
                k = i;
            }
        }
        cota = k;
    }
}
/*----------------------------------------------------------------------------*/
void sacar (char cad[], registro *r, FILE *destino) {
    char *pri, *seg, *ter, nombre[30];
    int flag = 0;
    registro aux;
    rewind(destino);
    pri = strtok(cad,",");
    seg = strtok(NULL,",");
    ter = strtok(NULL,",");
    while (!feof(destino)) {
        fread(&aux,sizeof(registro),1,destino);
        if (aux.cod_chof == atoi(pri)) { //si existe
            flag = 1;
            break;
        }
    }
    if (flag) { // MODIFICACION
        aux.cantv++;
        aux.kms += atoi(ter);
        aux.sueldo = aux.sueldo + (100 * atoi(ter));
        fseek(destino,-1L * sizeof(registro),SEEK_CUR);
        fwrite(&aux,sizeof(registro),1,destino);
    }
    else { // ALTA
        r -> cod_chof = atoi(pri);
        strcpy(r -> nom_chof,seg);
        r -> kms = atoi(ter);
        r -> cantv = 1;
        r -> sueldo = 35000 + (100 * r -> kms);
        fwrite(r,sizeof(registro),1,destino);
    }
}
/*----------------------------------------------------------------------------*/
void mostrarBinario(FILE *f) {
    registro r;
    rewind(f);
    fread(&r,sizeof(registro),1,f);
    while (!feof(f)) {
        if (r.cantv > 2)
            printf("%d\t%-20s\t%d\t%d\t%d\tPREMIO DE 5000 PESOS\n",r.cod_chof,r.nom_chof,r.kms,r.cantv,r.sueldo);
        else
            printf("%d\t%-20s\t%d\t%d\t%d\n",r.cod_chof,r.nom_chof,r.kms,r.cantv,r.sueldo);
        fread(&r,sizeof(registro),1,f);
    }
}

void mostrarTexto(FILE *x) {
    char cad[81];
    rewind(x);
    while (fgets(cad,81,x) != NULL) {
        printf("%s",cad);
    }
}

void ordenarBinario (FILE* binario, FILE* ordenado) {
    int i = 0, cantReg = ftell(binario) / sizeof(registro);
    registro aux, v[cantReg-1];
    rewind(binario);
    rewind(ordenado);
    fread(&aux,sizeof(registro),1,binario);
    while (!feof(binario)) {
        v[i].cod_chof = aux.cod_chof;
        strcpy(v[i].nom_chof, aux.nom_chof);
        v[i].kms = aux.kms;
        v[i].cantv = aux.cantv;
        v[i].sueldo = aux.sueldo;
        i++;
        fread(&aux,sizeof(registro),1,binario);
    }
    ordenar(v,cantReg);
    for (i= 0; i < cantReg; i++) {
        fwrite(&v[i],sizeof(registro),1,ordenado);
    }
}
