#include <stdio.h>
#include <stdlib.h>

int main(){

int vec[] = {10,20,30,40,50,60,70,80,90};
int *pLista = vec,i; //apunta al comienzo del vector
printf("\nContenido del puntero !!!\n\n");

    for(i=0; i<9; i++){
        printf("%3d", *pLista++);
    }
printf("\nContenido del vector !!!\n\n");
    for(i=0; i<9; i++){
        printf("%3d", vec[i]);
    }

   // pLista = printf("\nContenido del puntero !!!\n\n");vec;

    printf("\nCuadro comparativos entre vectores y punteros\n\n");
    printf("\n Posicion     Vector    &vector   &Plista \tPlista");

    for(i=0; i<9; i++)
        printf("\n%5d\t\t%d\t%p  %d\t%3p", i+1, vec[i], &vec[i], pLista++, *pLista);
    printf("\nPresione una tecla para salir.");
    

return 0;
}
