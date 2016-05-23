#include "Pelicula.h"
#include <string>
#include "sqlite3.h"
using namespace std;

 Pelicula::Pelicula(string titulo, string director, string actor, int duracion, string genero, int anyo, std::string  fecha, std::string  hora, int precio)
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
 int Pelicula::getDuracion() const
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
 int Pelicula::getPrecio() const
{
	return this->precio;
}
 string  Pelicula::getFecha() const
{
	return this->fecha;
}
 string Pelicula::getHora() const
{
	return this->hora;
}

Pelicula::~Pelicula(){

}
