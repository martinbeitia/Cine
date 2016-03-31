#include "save.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0
void save(char nombre[],char contra[])
{
	FILE * fp;
	FILE * fp1;
	fp=fopen("Usuario.txt","a");
	fp1=fopen("Contra.txt","a");
	fprintf(fp,"%s", nombre);
	fprintf(fp1,"%s", contra);
	fclose(fp);
	fclose(fp1);

}
bool read(char nombre[],char contra[])
{
	FILE * fp;
	FILE * fp1;
	char line[256];
	char line1[256];
	fp=fopen("Usuario.txt","r");
	fp1=fopen("Contra.txt","r");
	while ( fgets ( line, sizeof line, fp ) != NULL && fgets ( line1, sizeof line1, fp1 ) )
    {
    	 if (strstr(line, nombre)&& strstr(line1, contra))
    	 	return true;
    	 else return false;
    } 
    fclose(fp);
    fclose(fp1);     
}