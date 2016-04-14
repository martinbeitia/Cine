#include <stdio.h> //PROYECTO
#include "save.h"
#include <stdlib.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0
#define maximo 20

void clear_if_needed(char *str)
{
    if (str[strlen(str) - 1] != '\n')
    {
        int c;    
        while ( (c = getchar()) != EOF && c != '\n');
    }
}

int main()
{
	int opcion;
	int opcionUsuario;
	int opcionAdmin;
	int opcionUsuarioMetido;
	int opcionAdminMetido;
	char *nombre;
	char *contra;
	char guardanombre[maximo];
	char guardacontra[maximo];
	bool exist;
	printf("Bienvenido a A-TEAM STUDIOS.\n En la siguiente aplicacion podran realizar acciones relacionadas con nuestro cine.\n Disfrutenlo =D\n");
	do
	{
		printf("1.Acceder como usuario.\n");
		printf("2.Acceder como administrador.\n");
		printf("3.Salir.\n");
		printf( "\n\n   Introduzca opci%cn (1-3): ", 162 );

        scanf( "%d", &opcion );

        switch(opcion)
        {
	        case 1:
		     	printf("1.Acceder.\n");
		        printf("2.Crear cuenta.\n");
		        printf("3.Atras.\n");
		        printf( "\n\n   Introduzca opci%cn (1-3): ", 162 );
		        scanf("%d", &opcionUsuario);
		        switch(opcionUsuario)
		        {
		        	case 2:
		        		nombre = (char*)malloc ( maximo*sizeof(char) );
		        		contra = (char*)malloc ( maximo *sizeof(char) );
			        	printf("Escriba el nombre de usuario. \n");
			        	fgets(nombre, maximo, stdin);
    					clear_if_needed(nombre);
    					sscanf(nombre, "%s", guardanombre); 
			        	printf("Contrasena\n");
			        	fgets(contra, maximo, stdin);
    					clear_if_needed(contra);
    					sscanf(nombre, "%s", guardacontra);
			        	save(guardanombre, guardacontra);
			        	free(nombre);
			        	free(contra);
			        	break;
			        case 1:
			        	nombre = (char*)malloc ( sizeof(char) );
		        		contra = (char*)malloc ( sizeof(char) );
			        	printf("Escriba el nombre de usuario. \n");
			        	fgets(nombre, maximo, stdin);
    					clear_if_needed(nombre);
			        	fgets(contra, maximo, stdin);
    					clear_if_needed(contra);
    					sscanf(contra, "%s", guardacontra);
			        	exist=read(guardanombre, guardacontra);
			        	free(nombre);
			        	free(contra);
			        	if(exist==true){
			        	printf("1.Cartelera.\n\n");
		       				printf("2.Puntuar pelicula.\n\n");
		        			printf("3.Salir.\n\n");
		        			printf( "\n\n   Introduzca opci%cn (1-3): ", 162 );
		        			scanf("%d", &opcionUsuarioMetido);
			        	switch(opcionUsuarioMetido){
			        		
		        			case 1: printf("Imprime la cartelera.\n\n"); break;
		        			case 2: printf("Menu para puntuar pelicula.\n\n"); break;
		        			case 3: break;
		        			default: printf("Introduzca una opcion valida. \n\n"); break;
			        	}
			        }else break;
			        case 3:break;
			        default:
			        	printf("Introduzca una opcion valida. \n\n");
			        	break;
			    }
		        break;
		    case 2:printf("1.Acceder.\n\n");
		        printf("2.Atras.\n\n");
		        printf( "\n\n   Introduzca opci%cn (1-2): ", 162 );
		        scanf("%d", &opcionAdmin);
		         switch(opcionAdmin)
		        {
		        	case 1:
		        	do{
			        	printf("Escriba el nombre del administrador. \n");
			        	scanf("%s", &nombre);
			        	printf("Contrasena\n");
			        	scanf("%s", &contra);
			        	if((strcmp(nombre, "ateamstudios") ==0)&&(strcmp(contra, "ateamcines") ==0)){
			        		printf("1.Añadir/quitar pelicula.\n\n");
		        			printf("2.Busqueda.\n\n");
		        			printf("3.Récords.\n\n");
		        			printf("4.Recaudacion.\n\n");
		        			printf("5.Salir.\n\n");
		        			printf( "\n\n   Introduzca opci%cn (1-5): ", 162 );
		        			scanf("%d", &opcionAdminMetido);
		        			switch(opcionAdminMetido){
		        				case 1: break;
		        				case 2: break;
		        				case 3: break;
		        				case 4: break;
		        				case 5: break;
		        				default: printf("Introduzca una opción valida. \n\n"); break;
		        			}
			        	}else{
			        		printf("El nombre o contraseña del administrador no es correcto. \n");
			        	}
			        }while((strcmp(nombre, "ateamstudios") !=0)&&(strcmp(contra, "ateamcines") !=0));
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