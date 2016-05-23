#include <stdio.h> //PROYECTO
#include "save.h"
#include "Pelicula.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "sqlite3.h"
#define MAX_LENGHT 20
#define MAX 2
//typedef int bool;
//#define true 1
//#define false 0
using namespace std;

void clear_if_needed(char *str)
{
    if (str[strlen(str) - 1] != '\n')
    {
        int c;    
        while ( (c = getchar()) != EOF && c != '\n');
    }
}

void insertPeli(Pelicula * a,int metidas){
	string titulo;
	string director;
	string actor;
	int duracion;
	string genero;
	int anyo;
	int fecha;
	int hora;
	int precio;



	cout<<"Escribe el nombre de la pelicula"<<endl;
	cin>>titulo;
	cout<<"Escribe el director de la pelicula"<<endl;
	cin>>director;
	cout<<"Escribe el actor de la pelicula"<<endl;
	cin>>actor;
	cout<<"Escribe la duracion de la pelicula"<<endl;
	cin>>duracion;
	cout<<"Escribe el genero de la pelicula"<<endl;
	cin>>genero;
	cout<<"Escribe el anyo de la pelicula"<<endl;
	cin>>anyo;
	cout<<"Escribe la fecha de la pelicula"<<endl;
	cin>>fecha;
	cout<<"Escribe la hora de la pelicula"<<endl;
	cin>>hora;
	cout<<"Escribe el precio de la pelicula"<<endl;
	cin>>precio;

	metidas++;

	a=new Pelicula(titulo,director,actor,duracion,genero,anyo,fecha,hora,precio);


}
void quitarPeli(Pelicula* a, int metidas)
{
	int i;
	for (i=0;i<metidas;i++)
	{
		cout<<a[i].getTitulo()<<endl;
	}
}

int main()
{
	int opcion;
	int opcionUsuario;
	int opcionAdmin;
	int opcionUsuarioMetido;
	int opcionAdminMetido;
	int otraOpcion;
	int metidas=0;
	char *nombre;
	char *contra;
	char str[MAX_LENGHT];
	char guardanombre[MAX_LENGHT];
	char guardacontra[MAX_LENGHT];
	bool exist;
	bool add;
	char num[MAX];
	Pelicula *a;
	printf("Bienvenido a A-TEAM STUDIOS.\n En la siguiente aplicacion podran realizar acciones relacionadas con nuestro cine.\n Disfrutenlo =D\n");
	do
	{
		printf("\n1.Acceder como usuario.\n");
		printf("2.Acceder como administrador.\n");
		printf("3.Salir.\n");
		printf( "\n\n   Introduzca opci%cn (1-3): ", 162 );

       fgets(num,MAX,stdin);
       clear_if_needed(num);
	   sscanf(num, "%d", &opcion);

        switch(opcion)
        {
	        case 1:
		     	printf("1.Acceder.\n");
		        printf("2.Crear cuenta.\n");
		        printf("3.Atras.\n");
		        printf( "\n\n   Introduzca opci%cn (1-3): ", 162 );
		        fgets(num,MAX,stdin);
      			clear_if_needed(num);
	  		 	sscanf(num, "%d", &opcionUsuario);
		        switch(opcionUsuario)
		        {
		        	case 2:


				        	printf("Escriba el nombre de usuario. \n");
				        	fgets(str,MAX_LENGHT,stdin);
	    					clear_if_needed(str);
	    					sscanf(str, "%s", guardanombre); 

	    					nombre = (char*)malloc ( strlen((guardanombre) +1) * sizeof(char) );
	    					strcpy(nombre, guardanombre);

	    					add=comprobar(nombre);
	    					if(add==true)
	    					{
					        	printf("Contrasena\n");
					        	fgets(str,MAX_LENGHT,stdin);
		    					clear_if_needed(str);
		    					sscanf(str, "%s",guardacontra);

		    					contra = (char*)malloc ( strlen((guardacontra) +1) * sizeof(char) );
		    					strcpy(contra, guardacontra);

					        	save(nombre, contra);
					        	free(nombre);
					        	free(contra);
					        	break;
				      		}
				      		 else printf("El usuario ya existe\n");
			       		 
			        	break;
			        case 1: 
			       
				        	printf("Escriba el nombre de usuario. \n");
				        	fgets(str,MAX_LENGHT,stdin);
	    					clear_if_needed(str);
	    					sscanf(str, "%s", guardanombre); 

	    					nombre = (char*)malloc ( strlen((guardanombre) +1) * sizeof(char) );
	    					strcpy(nombre, guardanombre);

				        	printf("Contrasena\n");
				        	fgets(str,MAX_LENGHT,stdin);
	    					clear_if_needed(str);
	    					sscanf(str, "%s",guardacontra);

	    					contra = (char*)malloc ( strlen((guardacontra) +1) * sizeof(char) );
	    					strcpy(contra, guardacontra);
	    				
			        	exist=read(nombre, contra);
			        	free(nombre);
			        	free(contra);
			        	if(exist==true)
			        	{
			        		printf("1.Cartelera.\n\n");
		       				printf("2.Puntuar pelicula.\n\n");
		        			printf("3.Salir.\n\n");
		        			printf( "\n\n   Introduzca opci%cn (1-3): ", 162 );
		        			fgets(num,MAX,stdin);
      						clear_if_needed(num);
	   						sscanf(num, "%d", &opcionUsuarioMetido);
			        		switch(opcionUsuarioMetido)
			        		{
			        			case 1: printf("Imprime la cartelera.\n\n"); break;
			        			case 2: printf("Menu para puntuar pelicula.\n\n"); break;
			        			case 3: break;
			        			default: printf("Introduzca una opcion valida. \n\n"); break;
				        	}
			       		 }else 
			       		 {
			        		printf("El nombre o contraseña del usuario no es correcto. \n");
			       		 }
			       		 break;
			        case 3:break;
			        default:
			        	printf("Introduzca una opcion valida. \n\n");
			        	break;
		}
		        break;
		   		case 2:
		   		printf("1.Acceder.\n\n");
		        printf("2.Atras.\n\n");
		        printf( "\n\n   Introduzca opci%cn (1-2): ", 162 );
		        fgets(num,MAX,stdin);
       			clear_if_needed(num);
	   			sscanf(num, "%d", &opcionAdmin);
		         switch(opcionAdmin)
		        {
		        	case 1:
		        	
		        	
			        		printf("Escriba el nombre del administrador. \n");
			        		fgets(str,MAX_LENGHT,stdin);
	    					clear_if_needed(str);
	    					sscanf(str, "%s", guardanombre); 

	    					nombre = (char*)malloc ( strlen((guardanombre) +1) * sizeof(char) );
	    					strcpy(nombre, guardanombre);

				        	printf("Contrasena\n");
				        	fgets(str,MAX_LENGHT,stdin);
	    					clear_if_needed(str);
	    					sscanf(str, "%s",guardacontra);

	    					contra = (char*)malloc ( strlen((guardacontra) +1) * sizeof(char) );
	    					strcpy(contra, guardacontra);
	    				
			        	if((strcmp(nombre, "ateamstudios") ==0)&&(strcmp(contra, "ateamcines") ==0))
			        	{
			        		free(nombre);
			        		free(contra);
			        		printf("1.Añadir/quitar pelicula.\n\n");
		        			printf("2.Busqueda.\n\n");
		        			printf("3.Records.\n\n");
		        			printf("4.Recaudacion.\n\n");
		        			printf("5.Salir.\n\n");
		        			printf( "\n\n   Introduzca opci%cn (1-5): ", 162 );
		        			fgets(num,MAX,stdin);
       						clear_if_needed(num);
	   						sscanf(num, "%d", &opcionAdminMetido);
		        			switch(opcionAdminMetido)
		        			{
		        				case 1:
		        				cout<<"1-Añadir  2-quitar"<<endl;
		        				fgets(num,MAX,stdin);
       							clear_if_needed(num);
	   							sscanf(num, "%d", &otraOpcion);
	   							if(otraOpcion==1)
		        				insertPeli(a,metidas);
		        				if(otraOpcion==2)
		        				quitarPeli(a,metidas);
		        				else cout<<"Opcion no valida"<<endl;
		        				 break;
		        				
		        				case 2: break;
		        				case 3: break;
		        				case 4: break;
		        				case 5: break;
		        				default: printf("Introduzca una opción valida. \n\n"); break;
		        			}
			        	}else{
			        		printf("El nombre o contraseña del administrador no es correcto. \n");
			        	}
			       
			        	break;
			        case 2:break;
			         default:
			        	printf("Introduzca una opción valida. \n\n");
			        	break;
			    }
			        	
		        break;
       	 }
	}while(opcion!=3);
	return 0;
}