#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
typedef struct {
	int id;
	char *nombre;
	char *direccion;
	char *telefono;
	char *email;
}cliente;


typedef struct lista{
	cliente datos;
	struct lista *sig;
}nodo;
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
int menu(void);
void darAlta();
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
int main(){
	
	int opcion;
	
	
		while(opcion != 6){
			opcion = menu();
			switch(opcion){
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6: 
					printf("\n\n\t\t\tEl programa ha finalizado.\n\n");
					getch();
				break;
			}
			
		}

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
		void darAlta(){
			cliente enRegistro;
			
			printf("\n\t\t-INGRESAR DATOS DEL CLIENTE A REGISTRAR-\n");
			printf("Nombre: ");
			scanf("%*c%[^\n]", enRegistro.nombre);
			printf("Direccion: ");
			scanf("%*c%[^\n]", enRegistro.direccion);
			printf("Telefono: ");
			scanf("%*c%[^\n]", enRegistro.telefono);
			printf("Correo electronico: ");
			scanf("%*c%[^\n]", enRegistro.email);
		}
