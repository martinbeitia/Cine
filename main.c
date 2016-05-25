#include <stdio.h> //PROYECTO
#include "save.h"
#include <stdlib.h>
#include <string.h>
//#include "sqlit3.h"

#define MAX_LENGHT 20
#define MAX 2

void clear_if_needed(char *str)
{
    if (str[strlen(str) - 1] != '\n')
    {
        int c;    
        while ( (c = getchar()) != EOF && c != '\n');
    }
}

int menuPrincipal(void)
{
	int option;
	char num[MAX];

	printf("\n1.Acceder como usuario.\n");
	printf("2.Acceder como administrador.\n");
	printf("3.Salir.\n");
	printf( "\n\n   Introduzca opcion (1-3): ", 162 );

	fgets(num,MAX,stdin);
   	clear_if_needed(num);
   	sscanf(num, "%d", &option);

   	return option;
}

int menuUsuario(void)
{
	int optionUsuario;
	char num[MAX];

	printf("1.Acceder.\n");
    printf("2.Crear cuenta.\n");
    printf("3.Atras.\n");
    printf( "\n\n   Introduzca opcion (1-3): ", 162 );

    fgets(num,MAX,stdin);
	clear_if_needed(num);
 	sscanf(num, "%d", &optionUsuario);

 	return optionUsuario;

}

void accederUsuario(void)
{
	char *nombre;
	char *contra;
	char str[MAX_LENGHT];
	bool exist;
	int opcionUsuarioMetido;

	
	printf("Escriba el nombre de usuario. \n");
	fgets(str,MAX_LENGHT,stdin);
	clear_if_needed(str);
	nombre = (char*)malloc ( strlen((str) +1) * sizeof(char) );
	sscanf(str, "%s",nombre); 

	printf("Contrasena\n");
	fgets(str,MAX_LENGHT,stdin);
	clear_if_needed(str);
	contra = (char*)malloc ( strlen((str) +1) * sizeof(char) );
	sscanf(str, "%s",contra);

	Usuario u={nombre,contra};


	exist=read(u);
	free(nombre);
	free(contra);
	if(exist==true)
	{
		opcionUsuarioMetido = menuUsuarioDentro();

    	switch(opcionUsuarioMetido)
    	{
			case 1: printf("Imprime la cartelera.\n\n"); break;
			case 2: printf("Menu para puntuar pelicula.\n\n"); break;
			case 3: break;
			default: printf("Introduzca una opcion valida. \n\n"); break;
    	}
	}
	 else 
	{
		printf("El nombre o contrasena del usuario no es correcto. \n");
	}
    	
}

int menuUsuarioDentro()
{
	int optionUsuarioMetido;
	char num[MAX];

	printf("1.Cartelera.\n\n");
	printf("2.Puntuar pelicula.\n\n");
	printf("3.Salir.\n\n");
	printf( "\n\n   Introduzca opcion (1-3): ", 162 );

	fgets(num,MAX,stdin);
	clear_if_needed(num);
	sscanf(num, "%d", &optionUsuarioMetido);

	return optionUsuarioMetido;
}

int crearCuenta()
{
	char *nombre;
	char *contra;
	char str[MAX_LENGHT];
	bool add;

	printf("Escriba el nombre de usuario. \n");
	fgets(str,MAX_LENGHT,stdin);
	clear_if_needed(str);
	nombre = (char*)malloc ( strlen((str) +1) * sizeof(char) );
	sscanf(str, "%s", nombre); 

	printf("Contrasena\n");
	fgets(str,MAX_LENGHT,stdin);
	clear_if_needed(str);
	contra = (char*)malloc ( strlen((str) +1) * sizeof(char) );
	sscanf(str, "%s",contra);

	Usuario u={nombre,contra};
	add=comprobar(u);
	if(add==true)
	{
    	save(u);
    	free(nombre);
    	free(contra);
	}		
	else 
	{
		printf("El usuario ya existe\n");
    }
}

int menuAdmin()
{
	char num[MAX];
	int optionAdmin;

	printf("1.Acceder.\n\n");
    printf("2.Atras.\n\n");
    printf( "\n\n   Introduzca opcion (1-2): ", 162 );

    fgets(num,MAX,stdin);
	clear_if_needed(num);
	sscanf(num, "%d", &optionAdmin);
}

void accederAdmin()
{
	char *nombre;
	char *contra;
	char str[MAX_LENGHT];
	char num[MAX];
	int opcionAdminMetido;

	
	printf("Escriba el nombre del administrador. \n");
	fgets(str,MAX_LENGHT,stdin);
	clear_if_needed(str);
	nombre = (char*)malloc ( strlen((str) +1) * sizeof(char) );
	sscanf(str, "%s", nombre); 

	printf("Contrasena\n");
	fgets(str,MAX_LENGHT,stdin);
	contra = (char*)malloc ( strlen((str) +1) * sizeof(char) );
	clear_if_needed(str);
	sscanf(str, "%s",contra);
		

	if((strcmp(nombre, "ateamstudios") ==0)&&(strcmp(contra, "ateamcines") ==0))
	{


		int opcionAdminMetido = menuAdminDentro();

			switch(opcionAdminMetido){
				case 1: break;
				case 2: break;
				case 3: break;
				case 4: break;
				case 5: break;
				default: printf("Introduzca una opcion valida. \n\n"); break;
			}
	}
	else 
	{
    	printf("El nombre o contrasena del administrador no es correcto. \n");
    }
    
	free(nombre);
	free(contra);
}

int menuAdminDentro()
{
	char num[MAX];
	int optionAdminMetido;

	printf("1.Añadir/quitar pelicula.\n\n");
	printf("2.Busqueda.\n\n");
	printf("3.Records.\n\n");
	printf("4.Recaudacion.\n\n");
	printf("5.Salir.\n\n");
	printf( "\n\n   Introduzca opcion (1-5): ", 162 );

	fgets(num,MAX,stdin);
	clear_if_needed(num);
	sscanf(num, "%d", &optionAdminMetido);

	return optionAdminMetido;


}

int main(void)
{
	int opcion;
	int opcionUsuario;
	int opcionAdmin;
	
	char str[MAX_LENGHT];
	
	
	printf("Bienvenido a A-TEAM STUDIOS.\n En la siguiente aplicacion podran realizar acciones relacionadas con nuestro cine.\n Disfrutenlo =D\n");
	do
	{
		opcion = menuPrincipal();

        switch(opcion)
        {
	        case 1:
		     	opcionUsuario = menuUsuario();
		        switch(opcionUsuario)
		        {
		        	case 1:
		        	accederUsuario();
		        	break;

		        	case 2:
		        	crearCuenta();
		        	break;

		        	case 3:
		        	menuPrincipal();
		        	break;

			        default:
		        	printf("Introduzca una opcion valida. \n\n");
		        	break;
			    }
		        break;

		    case 2:
		    	opcionAdmin = menuAdmin();
		        switch(opcionAdmin)
		        {
		        	case 1:
		        	accederAdmin();
		        	break;
		        		
			        case 2:break;
			        menuPrincipal();
			        break;

			        default:
		        	printf("Introduzca una opción valida. \n\n");
		        	break;
			    }
			        	
		    break;
       	}
	}
	while(opcion!=3);
	return 0;
}