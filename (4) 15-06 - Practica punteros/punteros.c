#include<stdio.h>
#include<stdlib.h>

int main(){

    int *pun, A=25;
    system("color 9f");

    pun = &A;
	*pun = 82;
    printf("\nContenido de A: %d", A);//contenido de la direccion de memoria
    printf("\nContenido del puntero pun: %d", *pun);
    printf("\nDireccion de A: %X", &A);
    printf("\nDireccion de pun %x", pun);
    
    return 0;
}
