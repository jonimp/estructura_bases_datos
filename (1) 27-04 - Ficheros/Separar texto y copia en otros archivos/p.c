#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int id = 0;
	char result[16];
	FILE *fich, *fich2;
	char c[500];
	fich = fopen("fichero.txt", "rt+");
	
	if(fich == NULL)
	{
		perror("Error al abrir el fichero");
		return 1;
	}
	
	while(fgets(c,500,fich))
	{
		printf("%s", c);
		++id;
		sprintf(result, "fichero%d.txt", id+1);
		fich2 = fopen(result, "w");
		if(fich2 == NULL)
		{
			fclose(fich);
			return 1;
		}
		fputs(c, fich2);
		fclose(fich2);
	}
	fclose(fich);
	return 0;
}
