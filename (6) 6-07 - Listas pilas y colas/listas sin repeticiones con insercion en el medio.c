#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define p printf
#define s scanf


// Ingresa una lista en orden sin
//repeticiones, y extrae de la lista original los nodos con datos pares
// y los almacena en una lista par

typedef struct elemento
{
	int dato;
	int cont;
	struct elemento*sig;
} nodo;

void borranodo(nodo**,int);
void insertar(nodo**,int);
nodo*nuevonodo(int);
void nulo(void);
void unir(nodo**,nodo**,nodo**);
nodo *sacar(nodo**);
void poner(nodo**,nodo*);
void listar(nodo*);
void eliminar(nodo**);

int main(){
	int i, cant,n;
	nodo*uno,*dos,*fin;
	uno=NULL; dos=NULL;fin=NULL;
	
		system("color 9f");
		srand(time(NULL));
		p("\n Ingrese la cantidad de elementos de la primera lista:");
		s("%d",&cant);
 
			for(i=0;i<cant;i++)
				insertar(&uno,rand()%20+1);
				
			p("\n Ingrese la cantidad de elementos de la segunda lista:");
			s("%d",&cant);
			
			for(i=0;i<cant;i++)
				insertar(&dos,rand()%20+1);
 
			system("cls");
			p("\n\n Lista Uno Ingresada\n\n");
			listar(uno);
 nulo();
 p("\n\n");
 p("\n\n Lista Dos Ingresada\n\n");
 listar(dos);
 nulo();
 p("\n\n");
 unir(&uno,&dos,&fin);
 p("\n\n Lista Final\n\n");
 listar(fin);
 nulo();
 p("\n\n Elementos de la lista Uno!!!!"); getch();
 if(uno==NULL) p("\n Lista Uno ->");nulo();
 // eliminar(&uno);
 p("\n\n Elementos de la lista Dos!!!!"); getch();
 if(dos==NULL) p("\n Lista Uno ->");nulo();
 p("\n\n Presione una Tecla para borrar los nodos de la lista Resultante!!!!"); getch();
 eliminar(&fin);
 getch();
 system("cls");
 free(uno);
 free(dos);
 free(fin);
 return(0);
 }

 void nulo(void)
 {
   p(" NULL");
 }

void insertar(nodo** x,int y)
 {
	nodo *nuevo;
	if(*x==NULL)
	{
	    nuevo=nuevonodo(y);
        *x=nuevo;
	}

    else
       if((*x)->dato>y)
            {
             nuevo=nuevonodo(y);
             nuevo->sig=*x;
             *x=nuevo;
            }
        else
            if (y==(*x)->dato)
                (*x)->cont++;
            else
                insertar(&(*x)->sig,y);
 }
nodo * nuevonodo(int x)
{
 nodo *a;
 a=(nodo*)malloc(sizeof(nodo));
 a->dato=x;
 a->cont=1;
 a->sig=NULL;
 return a;
 }

void listar(nodo*x)
{
	if(x)
	{	 p("%4ld (%d) ->",x->dato,x->cont);
         listar(x->sig);
	 }
}

void eliminar(nodo**x)
 {
  nodo*aux;
  if(*x)
  {
	 aux=*x;
	 p("\nNodo a Borrar:%3d",(*x)->dato);getch();
	 *x=aux->sig;
	 free(aux);
	 eliminar(x);
  }
}

nodo* sacar(nodo**x)  // Elimina el nodo de la lista original
{
	nodo dato,*aux;
    aux=*x;
	*x=(*x)->sig; // avanza sobre la lista original
	 aux->sig=NULL;
    return aux;  //devuelve el nodo apuntando a NULL
}
void poner(nodo **x,nodo *y)
{
    if(*x==NULL) *x=y;
     else poner(&(*x)->sig,y);
}

void unir(nodo**x,nodo**y,nodo**z)
{
 nodo*a=NULL;
 nodo*b=NULL;

     if(*y&&*x)
     {
      if((*x)->dato<(*y)->dato)
          {
           a=sacar(&(*x));
           poner(&(*z),a);
           p("\nNodo a Extraer de la lista Original:%3d (%d)",a->dato,a->cont);
           p("Nodo cargado en z:%d",(*z)->dato);
           getch();

          }
            else if((*y)->dato<(*x)->dato)
              {
                 a=sacar(&(*y));
                 poner(&(*z),a);
                 p("\nNodo a Extraer de la lista Dos:%3d (%d)",a->dato,a->cont);
                 p("Nodo cargado en z:%d",(*z)->dato);
                 getch();
                }
              else {
                      b=sacar(&(*y));
                      a=sacar(&(*x));
                      a->cont=a->cont+b->cont;
                      poner(z,a);
                    }
         unir(&(*x),&(*y),&(*z)->sig); // Llamo a la recursividad
      }
      else

      {
      while(*x) //Si hay Datos en la lista Original
       {
        a=sacar(&(*x));
        poner(&(*z),a);
        p("\nNodo a Extraer de la lista Original:%3d (%d)",a->dato,a->cont);
        p("Nodo cargado en z:%d",(*z)->dato);
        }

      while(*y)   // Si hay datos en la Segunda Lista.
        {
         a=sacar(&(*y));
         poner(&(*z),a);
         p("\nNodo a Extraer de la lista Dos:%3d (%d)",a->dato,a->cont);
         p("Nodo cargado en z:%d",(*z)->dato);
        }

      }
}
