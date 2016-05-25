#include "save.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"
typedef int bool;
//#define true 1
//#define false 0
void save(Usuario u)
{
	FILE * fp;
	fp=fopen("Usuario.txt","a");
	fprintf(fp,"%s\n%s\n", u.nombre,u.contra);
	fclose(fp);

}
bool comprobar(Usuario u)
{
	FILE * fp;
	fp=fopen("Usuario.txt","r");
	char c[100];
	int i=1;
	int a;
	char name [100];
	if(fp==NULL)
		return true;
	else
	{
		while (fgets(c,100,fp)!=NULL)	
		{
			if((i%2)!=0)
			{
				sscanf(c,"%s",name);
				if(strcmp(name,u.nombre)==0)
				{
					a=1;
				}			
			}
			i++;
		}
		if(a==1)
			return false;
		else return true;
	}
	fclose(fp);	
}

bool read(Usuario u)
{
	FILE * fp;
	fp=fopen("Usuario.txt","r");
	char c[100];
	int i=1;
	int a;
	int b;
	int d;
	int e;
	char name [100];
	char password[100];

	while (fgets(c,100,fp)!=NULL)	
	{		
		if((i%2)!=0)
		{
			sscanf(c,"%s",name);
			if(strcmp(name,u.nombre)==0)
			{
				a=1;
				d=i;	
			}
		}	
		if((i%2)==0)
		{
			sscanf(c,"%s",password);
			if(strcmp(password,u.contra)==0)
			{
				b=1;
				e=i;
			}
		}
		i++;		
	}
	if(a==1 && b==1 && e-d==1)
	return true;
			
	else return false;
		
    fclose(fp);
}