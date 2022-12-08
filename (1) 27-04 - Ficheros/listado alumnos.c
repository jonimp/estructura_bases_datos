/*A)Cantidad de alumnos
  B)Promedio curso
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char legajo[30];
    char nombre[50];
    int nota;
} registro;

int sacar(char[], registro*);
void mostrar(FILE*);

int main(){
    FILE* binario;
    registro r;
    char *nombre = "notas.txt";
    char *nombre2 = "notasArchivo.dat";
    char cadena[81];
    int n;

    binario = fopen("notas.dat", "wb+");
    n = sacar(cadena, r);
    mostrar(binario);

return 0;
}


void mostrar(FILE* x){
    registro r;
    rewind(x);
    fread(&r, sizeof(r), 1, x);

    while(!feof(x)) {
        printf("\n %-8s\t %-30s\t %3d", r.legajo, r.nombre, r.nota);
        fread(&r, sizeof(r), 1, x);
    }
}

int sacar(char x[], registro *y){
    char *pri, *seg, *ter;
    pri= strtok(x, ",");
    strcpy(y->legajo, pri);
    seg = strtok(NULL, ",");
    strcpy(y->nombre, seg);
    ter = strtok(NULL, ",");
    y-> nota =  atoi(ter);

    return atoi(ter);
}
