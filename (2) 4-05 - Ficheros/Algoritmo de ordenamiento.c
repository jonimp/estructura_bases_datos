#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct{
    int cod_chof;
    char nom_chof[30];
    int kms;
    int rec;
}registro;

void ordenar (registro x[], int y);

int main(){




return 0;
}

void ordenar (registro x[], int y){

    int i, cota=y-1, k=1;
    registro aux;

    while(k){
        k=0;

        for(i=0; i<cota; i++){

            if(x[i].rec > x[i+1].rec){
                aux = x[i];
                x[i] = x[i+1];
                x[x+1] = aux;
                k=1;
            }
        }
    cota = k;
    }

}
