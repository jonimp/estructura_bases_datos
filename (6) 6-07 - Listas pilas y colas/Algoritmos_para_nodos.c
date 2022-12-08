typedef struct elemento{
	int dato;
	int cont;
	struct elemento*sig;
} nodo;

/*----------------------------------------------------------------*/

nodo * nuevonodo(int x){
	nodo *a;
	a=(nodo*)malloc(sizeof(nodo));
	a->dato=x;
	a->cont=1;
	a->sig=NULL;
	return a;
}

/*----------------------------------------------------------------*/
	insertar(&uno,rand()%20+1);
	
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
		
/*----------------------------------------------------------------*/
	void insadel(nodo **x, int y){
		nodo *nuevo;
		nuevo = nuevonodo(y);
		if(*x==NULL){
			*x = nuevo;
		} 
		else {
				nuevo->sig = *x;
				*x = nuevo;
		}
	}
		
/*----------------------------------------------------------------*/
	void insatras(nodo** x, int y){
		
		nodo *nuevo;
		if(*x==NULL){
			nuevo=nuevonodo(y);
			(*x)=nuevo;
		}
		else {
			insatras(&(*x)->sig, y);
		}
	}
/*----------------------------------------------------------------*/
		void insertar(nodo**x, int y){
			nodo *nuevo;
			if(*x==NULL){
				nuevo = nuevonodo(y);
				*x=nuevo;
			}
			else {
				if((*x)->dato > y){
					nuevo = nuevonodo(y);
					nuevo->sig =*x;
					*x=nuevo;
				} else {
					if(y == (*x)->dato)
						(*x) -> cont++;
					else
						insertar(&(*x)->sig, y);
				}
			}
		}
/*----------------------------------------------------------------*/
		void listar(nodo *x){
			if(x){
				printf("%2d(%d) -> ", x->dato, x->cont);
				//printf("%p, dat:%d -- x-sig:%p\n", x,x->dato, x->sig);
				listar(x -> sig);
			}
		}
/*----------------------------------------------------------------*/
		void eliminar(nodo **x){
			nodo *aux;
			if(*x){
				aux = *x;
				printf("\nNodo a borrar: %3d", (*x)->dato);
				getch();
				*x=aux->sig;
				free(aux);
				aliminar(x);
			}
		}
/*----------------------------------------------------------------*/
		void borranodo(nodo **x, int y){
			nodo *aux;
			if(*x){
				aux = *x;
				if((*x)->dato == y){
					printf("Nodo a eliminar: %3d", (*x)->dato);
					getch();
					*x=aux->sig;
					free(aux);
				}
				else{
					borranodo(&(*x)->sig, y);
				}
			}
		}
/*----------------------------------------------------------------*/
		case 1:
				printf("\nIngresa elemento por delante");
				scanf("%d", &num);
				insadel(&cabeza, num);
				break;
		case 2:
				printf("\nIngresa elemento por el final");
				scanf("%d", &num);
				insatras(&cabeza, num);
				break;
		case 3:
				if(cabeza){
					printf("\n\n Lista ordenada\n\n");
					listar(cabeza);
					printf("NULL");
					getch();
				}
				else {
					vacia();
				}
				break;
/*----------------------------------------------------------------*/	
/*
	PILAS: se agrega un nodo al final y cuando se saca un nodo, se saca el primero
	O lo que es lo mismo, se agrega un nodo al principio y siempre se saca el primero
				
	COLAS: De esta forma al agregar nodos siempre al final,
			cuando se saquen será desde el principio de la cola.			
				*/
