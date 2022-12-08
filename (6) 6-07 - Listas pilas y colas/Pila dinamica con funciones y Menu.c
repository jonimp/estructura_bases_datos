#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct r nodo;

struct r
{
	int nro;
   nodo* ptr;
};

nodo* ingresarDato(void);
int pilaVacia(nodo*);

void apilar(nodo**,nodo*);
nodo desapilar(nodo**);

void mostrarDato(nodo);
void listarPila(nodo*);
void eliminarPila(nodo*);

int menu(void);

main()
{
	nodo *p,*q,dato;
   int op;

   p=NULL;

   do
   {
   	op=menu();
      switch(op)
      {
      	case 1:
         	q=ingresarDato();
            apilar(&p,q);
            break;
         case 2:
         	if(pilaVacia(p))
            {
            	dato=desapilar(&p);
               mostrarDato(dato);
            }
            break;
         case 3:
         	if(pilaVacia(p))
            	listarPila(p);
      }
   }while(op<4);

   if(p!=NULL)
     	eliminarPila(p);

   return 0;
}


nodo* ingresarDato(void)
{
	int nro;
   nodo *q;
   q=(nodo*)malloc(sizeof(nodo));
   system("cls");
   printf("\n\nIngrese un n�mero:  ");
   scanf("%d",&nro);
   q->nro=nro;
   q->ptr=NULL;
   return q;
}


int pilaVacia(nodo*p)
{
    if(p==NULL)
    {
        system("cls");
        printf("PILA VACIA");
        system("pause");
        return 0;
    }
    else
        return 1;
}

void apilar(nodo**p,nodo*q)
{
   q->ptr=*p;
	*p=q;
}

nodo desapilar(nodo**p)
{
    nodo dato,*aux;
    aux=*p; // aux queda mirando a p
    dato=**p;
    *p=(*p)->ptr;
    free(aux);
    return dato;
}


void mostrarDato(nodo dato)
{
    system("cls");
    printf("\n\n\nDato desapilado: %ld",dato.nro);
    printf("\n\n");
    system("pause");
}

void listarPila(nodo*p)
{
    system("cls");
    printf("CONTENIDO DE LA PILA\n\n");
    while(p)
    {
        printf("direccion:%x dato:%d ptr:%x \n",p,p->nro,p->ptr);
        p=p->ptr;
    }
    printf("\n\n");
    system("pause");
}

void eliminarPila(nodo*p)
{
    nodo *aux;
    while(p)
    {
        aux=p;
        p=p->ptr;
        free(aux);
    }
}

int menu(void)
{
    int op;
    do
    {
        system("cls");
        printf("MENU DE OPCIONES\n\n");
        printf("1- Apilar\n");
        printf("2- Desapilar\n");
        printf("3- Listar\n");
        printf("4- Salir\n");
        printf("Ingrese Opcion:  ");
        scanf("%d",&op);
    }while(op<1||op>4);
    return op;
}

