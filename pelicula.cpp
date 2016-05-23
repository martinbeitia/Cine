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
  string Pelicula::getTitulo() const
{
	return this->titulo;
}
 string Pelicula::getDirector() const
{
	return this->director;
}
 string Pelicula::getActor() const
{
	return this->actor;
}
 float Pelicula::getDuracion() const
{
	return this->duracion;
}
 string Pelicula::getGenero() const
{
	return this->genero;
}
 int Pelicula::getAnyo() const
{
	return this->anyo;
}
 float Pelicula::getPrecio() const
{
	return this->precio;
}
 int Pelicula::getFecha() const
{
	return this->fecha;
}
 int Pelicula::getHora() const
{
	return this->hora;
}

Pelicula::~Pelicula(){

}
