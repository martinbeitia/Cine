#include <stdio.h> //PROYECTO
#include "save.h"
#include "pelicula.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "sqlite3.h"
#include "gestor.h"
#define MAX_LENGHT 20
#define MAX 2
#define MAX_FILM 10
//typedef int bool;
//#define true 1
//#define false 0
using namespace std;

Gestor *gestor = new Gestor("basededatos.sqlite");


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

int menuUsuarioDentro()
{
	int optionUsuarioMetido;
	char num[MAX];

	printf("1.Cartelera.\n\n");
	printf("2.Puntuar cine.\n\n");
	printf("3.Salir.\n\n");
	printf( "\n\n   Introduzca opcion (1-3): ", 162 );

	fgets(num,MAX,stdin);
	clear_if_needed(num);
	sscanf(num, "%d", &optionUsuarioMetido);

	return optionUsuarioMetido;
}

void accederUsuario(Gestor *gestor)
{
	char *nombre;
	char *contra;
	char str[MAX_LENGHT];
	int exist;
	int opcionUsuarioMetido;
	float num;
	int probar;

	
	printf("Username \n");
	fgets(str,MAX_LENGHT,stdin);
	clear_if_needed(str);
	nombre = (char*)malloc ( (strlen(str) +1) * sizeof(char) );
	sscanf(str, "%s",nombre); 

	printf("Password\n");
	fgets(str,MAX_LENGHT,stdin);
	clear_if_needed(str);
	contra = (char*)malloc ( (strlen(str) +1) * sizeof(char) );
	sscanf(str, "%s",contra);

	Usuario u={nombre,contra};


	exist=read(u);
	free(nombre);
	free(contra);
	if(exist==1)
	{
		do{
		opcionUsuarioMetido = menuUsuarioDentro();

    	switch(opcionUsuarioMetido)
    	{
			case 1: {probar=gestor->mostrarPelis();
					if(probar==1){
					string eleccion;
					cout<<"Elija que pelicula quiere ver: ";
					getline(cin,eleccion);
					cout << "Pulse intro" << endl;
					gestor->actualizarAsistencia(eleccion);
					gestor->aumentarAsistencia(eleccion);
					gestor->guardarAsistencia();
					gestor->guardarRecaudacion(eleccion);
					}else{
						cout << "Vacia" <<endl;
					}
					
					break;
					}
			case 2:	{gestor->puntuar();
					break;}
			case 3: {menuUsuario();break;}
					
			default: {printf("Introduzca una opcion valida. \n\n"); break;}
    	}
    	}while(opcionUsuarioMetido !=3);
	}
	 else 
	{
		printf("El nombre o contrasenya del usuario no es correcto. \n");
	}
    	
}



int crearCuenta()
{
	char *nombre;
	char *contra;
	char str[MAX_LENGHT];
	int add;

	printf("Username: \n");
	fgets(str,MAX_LENGHT,stdin);
	clear_if_needed(str);
	nombre = (char*)malloc ( (strlen(str) +1) * sizeof(char) );
	sscanf(str, "%s", nombre); 

	printf("Password: \n");
	fgets(str,MAX_LENGHT,stdin);
	clear_if_needed(str);
	contra = (char*)malloc ( (strlen(str) +1) * sizeof(char) );
	sscanf(str, "%s",contra);

	Usuario u={nombre,contra};
	add=comprobar(u);
	if(add==1)
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

	return optionAdmin;
}

int menuAdminDentro()
{
	char num[MAX];
	int optionAdminMetido;

	printf("1.Anyadir/Quitar pelicula.\n\n");
	printf("2.Busqueda.\n\n");
	printf("3.Consultar asistencias.\n\n");
	printf("4.Recaudacion.\n\n");
	printf("5.Puntuacion de cine.\n\n");
	printf("6.Salir.\n\n");
	printf( "\n\n   Introduzca opcion (1-6): ", 162 );

	fgets(num,MAX,stdin);
	clear_if_needed(num);
	sscanf(num, "%d", &optionAdminMetido);

	return optionAdminMetido;

}

int menuBuscar()
{
	char num[MAX];
	int optionAdminBusqueda;

	printf("1.Buscar por anyo.\n\n");
	printf("2.Buscar por director.\n\n");
	printf("3.Buscar por genero.\n\n");
	printf("4.Atras\n\n");

	fgets(num,MAX,stdin);
	clear_if_needed(num);
	sscanf(num, "%d", &optionAdminBusqueda);

	return optionAdminBusqueda;

}

void accederAdmin(Gestor *gestor)
{
	char *nombre;
	char *contra;
	char str[MAX_LENGHT];
	char num[MAX];
	int opcionAdminMetido;
	int otraOpcion;
	string anyo;
	string director;
	string genero;
	int opcionBuscar;
	int asistencia;
	int recaudacion;
	int asistenciados;
	int puntuaciondos;
	int mediapuntuacion;
	int probar;

	
	printf("Administrador username: \n");
	fgets(str,MAX_LENGHT,stdin);
	clear_if_needed(str);
	nombre = (char*)malloc ( (strlen(str) +1) * sizeof(char) );
	sscanf(str, "%s", nombre); 

	printf("Administrador password:\n");
	fgets(str,MAX_LENGHT,stdin);
	contra = (char*)malloc ( (strlen(str) +1) * sizeof(char) );
	clear_if_needed(str);
	sscanf(str, "%s",contra);
		

	if((strcmp(nombre, "ateamstudios") ==0)&&(strcmp(contra, "ateamcines") ==0))
	{
		

		do{
		 opcionAdminMetido = menuAdminDentro();

			switch(opcionAdminMetido){
				case 1:
					cout<<"1-Anyadir / 2-Quitar"<<endl;
			        fgets(num,MAX,stdin);
					clear_if_needed(num);
					sscanf(num, "%d", &otraOpcion);
					if(otraOpcion==1){
					gestor->insertPeli();
					}
					if(otraOpcion==2){
						probar = gestor->mostrarPelis();
						if(probar==1){
						string titulo;						
						cout<<"Inserta el nombre de la pelicula a borrar: ";
						getline(cin,titulo);
						gestor->borrarPeli(titulo);
						}else{
						cout << "No hay peliculas registradas" << endl;
						}	
					}
					if(otraOpcion!=1 && otraOpcion!=2) cout<<"Opcion no valida"<<endl;
					break;
				case 2: opcionBuscar = menuBuscar();
						switch(opcionBuscar)
						{
							case 1: 
									cout<<"Introduce un anyo: "<<endl;
									cin>>anyo;					
									gestor->buscarporanyo(anyo);
									break;
							case 2: 
									cout<<"Introduce un director: "<<endl;
									getline(cin,director);					
									gestor->buscarpordirector(director);
									break;
							case 3: 
									cout<<"Introduce un genero: "<<endl;
									getline(cin,genero);					
									gestor->buscarporgenero(genero);
									break;
							
							default: cout << "Esa opcion no es valida"; break;
						}
				break;
				case 3: asistencia = gestor->consultarAsistencia();
						cout<<"El cine ha recibido un total de "<<asistencia<<" visitas"<<endl;
						cout << endl;
						break;
				case 4: recaudacion = gestor->consultarRecaudacion();
						cout<<"El cine ha recaudado un total de "<<recaudacion<<" euros"<<endl;
						cout << endl;break;
				case 5: asistenciados = gestor->consultarAsistencia();
						puntuaciondos = gestor->consultarPuntuacion();
						mediapuntuacion = puntuaciondos/asistenciados;
						cout << "El cine tiene una nota media de " << mediapuntuacion << endl;
						cout << endl;
						break;
				case 6: break;
				default: printf("Introduzca una opcion valida. \n\n"); break;

			}
			
		}while(opcionAdminMetido !=6);
	}
	else 
	{
    	printf("El nombre o contrasenya del administrador no es correcto. \n");
    }
    
	free(nombre);
	free(contra);

}

int main(void)
{


	int opcion;
	int opcionUsuario;
	int opcionAdmin;
	int metidas=0;
	
	char str[MAX_LENGHT];

	gestor->crearTabla();
	
	
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
		        	accederUsuario(gestor);
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
		        	accederAdmin(gestor);
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

		
		        				