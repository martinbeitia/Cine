#include "Pelicula.h"
#include <string>
#include "sqlite3.h"
using namespace std;

 Pelicula::Pelicula(string titulo, string director, string actor, int duracion, string genero, int anyo, string  fecha, string  hora, int precio, int asistencia)
 {
 	this->titulo=titulo;
 	this->director=director;
 	this->actor=actor;
 	this->duracion=duracion;
 	this->genero=genero;
 	this->anyo=anyo;
 	this->fecha=fecha;
 	this->hora=hora;
 	this->precio=precio;
 	this->asistencia=asistencia;
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

int Pelicula::getAsistencia() const
{
	return this->asistencia;
}

void setTitulo(string tituloset){
	this->titulo=tituloset;
}
void setDirector(string directorset){
	this->director=directorset;
}
void setActor(string actorset){
	this->actor=actorset;
}
void setDuracion(int duracionset){
	this->duracion=duracionset;
}
void setGenero(string generoset){
	this->genero=generoset;
}
void setAnyo(int anyoset){
	this->anyo=anyoset;
}
void setFecha(string fechaset){
	this->fecha=fechaset;
}	
void setHora(string horaset){
	this->hora=horaset;
}
void setPrecio(int precioset){
	this->precio=precioset;
}
void setAsistencia(int asistenciaset){
	this->asistencia=asistenciaset;
}

Pelicula::~Pelicula(){

}
