#include "Pelicula.h"
#include <string>
using namespace std;

 Pelicula::Pelicula(string titulo, string director, string actor, float duracion, string genero, int anyo, float precio, int fecha, int hora)
 {
 	this->titulo=titulo;
 	this->director=director;
 	this->actor=actor;
 	this->duracion=duracion;
 	this->genero=genero;
 	this->anyo=anyo;
 	this->precio=precio;
 	this->fecha=fecha;
 	this->hora=hora;
 }
 string Pelicula::getTitulo()
{
	return this->titulo;
}
string Pelicula::getDirector()
{
	return this->director;
}
string Pelicula::getActor()
{
	return this->actor;
}
float Pelicula::getDuracion()
{
	return this->duracion;
}
string Pelicula::getGenero()
{
	return this->genero;
}
int Pelicula::getAnyo()
{
	return this->anyo;
}
float Pelicula::getPrecio()
{
	return this->precio;
}
int Pelicula::getFecha()
{
	return this->fecha;
}
int Pelicula::getHora()
{
	return this->hora;
}
