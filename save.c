#include "save.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0
void save(char nombre[],char contra[])
{
	FILE *fp;
	fp=fopen("Usuario.txt","a");
	fprintf(fp,"%s\n%s\n", nombre,contra);
	fclose(fp);

}
bool read(char nombre[],char contra[])
{

	FILE *fp;

	fp = fopen ("Usuario.txt","r");

	char c;

	int n = 0;
	bool parinpar = false; //false es que esta en la inpar
	char caracteres[30];

	while ((c = fgetc(f)) != EOF)
	{
		if (c != '\n')
		{
			if (parinpar == false)
			{
			
			}	
		}
	}


	/*FILE *fp;
	FILE * fp1;
	fp=fopen("Usuario.txt","r");
	fp1=fopen("Contra.txt","r");
	char c;
	char d;
	int cuentanom;
	int cuentacon;
	
	while ((c = fgetc(fp)) != EOF&&(d = fgetc(fp1) != EOF))	
	{
		if (c == '\n')
			cuentanom++;  
		if(d=='\n')
			cuentacon++;
		char *cChar = malloc(sizeof(char));
		*cChar=c;
		char *dChar = malloc(sizeof(char));
		*dChar=d;
		if (strcmp(cChar, nombre)==0 && strcmp(dChar, contra)==0 && cuentacon==cuentanom)
    	 return true;
    	 else return false;
	}*/
	
	/*while (fgets(c , sizeof(c) ,fp )!= NULL&& fgets(d , sizeof(d) ,fp1 )!= NULL)
    {
    	for(i=0;i<strlen(nombre);i++){
    		while(nombre[i]!="\n"){

    		}
    //	}
    	if(*c=='\n')
    		cuentanom++;
    	if(*d=='\n')
    		cuentacon++;
    	 if (strstr(c, nombre)!=NULL && strstr(d, contra)!=NULL && cuentacon==cuentanom)
    	 return true;
    	 else return false;
    	
    } */
    //fclose(fp);
    //fclose(fp1);     
}