#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
	int dato;
	int cont;
	struct elemento*sig;
}nodo;

nodo *nuevonodo(int);
nodo desapilar(nodo**);
nodo *ingresarDato(int);
void insertar(nodo**,int);
void apilar(nodo**,nodo*);


int main(){

    nodo *p1=NULL, *p2=NULL, *p3=NULL;






return 0;
}


nodo * nuevonodo(int x){
 nodo *a;
 a=(nodo*)malloc(sizeof(nodo));
 a->dato=x;
 a->cont=1;
 a->sig=NULL;
 return a;
 }

 void insertar(nodo** x,int y){
    nodo *nuevo;
    if(*x==NULL){
        nuevo=nuevonodo(y);
        *x=nuevo;
    }
       else
        if((*x)->dato>y){
             nuevo=nuevonodo(y);
             nuevo->sig=*x;
             *x=nuevo;
        }
            else
                if (y==(*x)->dato)(*x)->cont++;
                else
                    insertar(&(*x)->sig,y);
 }


void apilar(nodo**p,nodo*q){
	 q->sig=*p;
	*p=q;
}


nodo desapilar(nodo**p){
   nodo dato,*aux;
    aux=*p;
    dato=**p;
     *p=(*p)->sig;
     free(aux);
     return dato;
}

nodo *ingresarDato(int x){

	//int nro;
	nodo *q;

	 q=(nodo*)malloc(sizeof(nodo));
	 q->dato=x;
     q->sig=NULL;

return q;
}

