#include <stdio.h> //PROYECTO
#include "save.h"
#include "Pelicula.h"
#include "gestorcliente.h"
#include "g"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;


void InformacionCartelera(elige)
{

	string elige;
	//elige = ImprimirCartelera() //Se llama a la funcion imprimircartelera del gestor y este nos devuelve la eleccion del usuario.

	asistencia++; //en el momento guardariamos en la base de datos la nueva asistencia.
	//Acceder a la base de datos y coger el precio de la película.
	recaudacion+=

}

void Puntuar()
{
	float puntuaciones;//sacar este dato de la base de datos.
	float puntuacion;

	cout<<"Puntua el cine"<<endl;
	cin>>puntuacion;

	puntuaciones+=puntuacion;
	//guardar en la base de datos puntuaciones;

	//acceder a la base de datos y sacar las asistencias.

	mediapuntuacion = puntuaciones/asistencias;



}

