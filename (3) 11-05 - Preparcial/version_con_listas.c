#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(void);
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
int main(){
	
	int opcion;
	
	opcion = menu();

return 0;
}


/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
	int menu (void){
		int opcion;
		 
		do{
			system("cls");
			printf("\n\t\t-ALTA / BAJA / MODIFICACIONES-\n");
			printf("\n\t\t\t1- ALTA\n");
			printf("\n\t\t\t2- BAJA\n");
			printf("\n\t\t\t3- MODIFICIACION\n");
			printf("\n\t\t\t4- LISTAR\n");
			printf("\n\t\t\t5- CARGAR ARCHIVO .CSV/.TXT\n");
			printf("\n\t\t\t6- SALIR\n");
			printf("\n\n\t\t ELECCION:  ");
			scanf("%d", &opcion);
		}while(opcion<1 || opcion>6);
		
	return opcion;
	}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
