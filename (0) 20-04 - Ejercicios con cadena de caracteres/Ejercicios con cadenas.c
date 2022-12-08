/*
1)Dimension cadena
2)Cantidad palabras de cadena
3)copiar la cadena en otra auxiliar
4)Mayusculas
5)Invetir (en forma ) la cadena original
6)Cantidad de vocales
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define p printf
#define s scanf

int dimensionCadena(char []);
int cantidadPalabras(char []);
void copiarCadena(char [], char []);
void pasarAmayusculas(char []);
void invertirCadena(char[]);
int contarVocales(char []);

int main(){

	int cantCar = 0, palabras=0, vocales;
	char cad[80], otraCad[80];

	
	
	system("cls");
	system("color 0a");
		p("\nIngrese cadena: ");
		s("%[^\n]", cad);
		p("\nCadena ingresada : %s", cad);
	//getch();

		
		
	p("\nCantidad de caracteres: %d", cantCar = dimensionCadena(cad));
	p("\nCantidad de palabras: %d", palabras = cantidadPalabras(cad));

	copiarCadena(cad, otraCad);
	p("\nCadena copiada: %s", otraCad);
	p("\nEn mayusculas: ");
	pasarAmayusculas(cad);
	invertirCadena(cad);
	p("\nCantidad de vocales: %d", vocales = contarVocales(cad));

return 0;
}
/*----------------------------------------------------------------------------*/
	
/*----------------------------------------------------------------------------*/
int dimensionCadena(char cadena[]){
    int i=0;
       while(cadena[++i]){
	   };   
	   
	return i;
}
/*----------------------------------------------------------------------------*/
	
/*----------------------------------------------------------------------------*/
int cantidadPalabras(char cadena[]){
    int i=0, contador=1, dim = dimensionCadena(cadena);

            while(cadena[++i]){
               
				if(cadena[i] != ' ' && cadena[i+1] == ' '){
					contador++;
				}
			}	
			
			if(cadena[dim-1] == ' ')
				contador--;
			
        
 return contador;
}
/*----------------------------------------------------------------------------*/
	
/*----------------------------------------------------------------------------*/
void copiarCadena(char original[], char copia[]){
    int i, t;
	t = dimensionCadena(original);
	
		for(i=0; i<t; i++){
			copia[i] = original[i];
		}
		copia[t] = '\0';
		
}
/*----------------------------------------------------------------------------*/
	
/*----------------------------------------------------------------------------*/
void pasarAmayusculas(char minusculas[]){
		int i, num;
		int t = dimensionCadena(minusculas);
		
			for(i=0; i<t; i++){
				
				num = minusculas[i];
				
					if(num >=97 && num <= 122){
						num = num-32;
					}
				
						p("%c", num);
			}
	
}
/*----------------------------------------------------------------------------*/
		
/*----------------------------------------------------------------------------*/
void invertirCadena(char cadena[]){
	
	int l = dimensionCadena(cadena);
	int i, j;
	char cadInvertida[l];
	
	j= l-1;
	for(i=0; i<l; i++){
		cadInvertida[i] = cadena[j];
		j--;
	}
	cadInvertida[l] = '\0';
	
	p("\nCadena invertida: %s", cadInvertida);
}
/*----------------------------------------------------------------------------*/
	
/*----------------------------------------------------------------------------*/
int contarVocales(char cadena[]){
	
	int i, contador=0, num;
	for(i=0; i<dimensionCadena(cadena); i++){
		
		num = cadena[i];
		
		if (num == 85 || num == 79 || num == 73 || num == 69 || num == 65 || 
			num == 97 || num == 101 || num == 105 || num == 111 || num == 117)
			contador++;
	}
	
	return contador;
}
