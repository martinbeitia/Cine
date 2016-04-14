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
	fp1=fopen("Usuario.txt","a");
	fprintf(fp,"%s\n", nombre);
	fprintf(fp1,"%s\n", contra);
	fclose(fp);
	fclose(fp1);

}
bool read(char nombre[],char contra[])
{
	FILE * fp;
	FILE * fp1;
	fp=fopen("Usuario.txt","r");
	fp1=fopen("Usuario.txt","r");
	char *c;
	char *d;
	int i;
	
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
    fclose(fp);
    fclose(fp1);     
}