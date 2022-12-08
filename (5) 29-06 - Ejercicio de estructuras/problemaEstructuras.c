#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int nfac;
    int nchof;
    int km;
    int cv;
    int tot;
}registro;

typedef struct nodo{
	registro datos;
	struct nodo *sig;
}nodo;

/****************************/

int main(){
    char c;
    struct nodo *aux;
    registro reg;
    FILE* archivo = fopen("lista.dat", "a+");

    fwrite(&aux->datos, sizeof(registro), 1, archivo);

    fprintf(archivo, "%d\n", aux->datos.nfac);
    fprintf(archivo, "%d\n", aux->datos.nchof);
    fprintf(archivo, "%d\n", aux->datos.km);
    fprintf(archivo, "%d\n", aux->datos.cv);
    fprintf(archivo, "%d\n", aux->datos.tot);

fclose(archivo);
return 0;
}

/*
int main(){
procesar(&cabeza,archivo);
return 0;
}

void procesar(nodo **x, FILE*y){
registro r;
rewind(y);
fread(&r, sizeof(r), 1, y);
while(!feof(y)){
    insertar(x,r);
    fread(&r,sizeof(r), 1, y);
    }
}

void insertar(nodo **x, registro r){

    nodo *nuevo;
    if(*x == NULL){
        nuevo = nuevoNodo(r.chof,r.km, r.tot);
        *x = nuevo;
    }
    else if (r.chof<(*x)->dato.chof){
        nuevo = nuevoNodo(r.chof,r.km, r.tot);
        nuevo->sig=*x;
        *x = nuevo;
    }
    else if(r.chof == (*x)->dato.chof){
        (*x)->dato.km += r.km;
        (*x)->dato.cv += 1;
        (*x)->dato.tot += r.tot;
    }
    else
        insertar(&(*x)->sig, r);
}
*/
