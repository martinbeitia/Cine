#ifndef _PELICULA_H_
#define _PELICULA_H_
#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;
class Pelicula{
private:
	std::string titulo;
	std::string director;
	std::string actor;
	int duracion;
	std::string genero;
	int anyo;
	int precio;
	string fecha;
	string hora;
	int asistencia;

public:

	Pelicula(std::string titulo, std::string director, std::string actor, int duracion, std::string genero, int anyo,  std::string  fecha, std::string  hora, int precio, int asistencia);

	~Pelicula();

	std::string getTitulo() const;
	std::string getDirector() const;
	std::string getActor() const;
	int getDuracion() const;
	std::string getGenero() const;
	int getAnyo() const;
	int getPrecio() const;
	std::string  getFecha() const;
	std::string  getHora() const;
	int getAsistencia() const;
	/*void setTitulo(string tituloset);
	void setDirector(string directorset);
	void setActor(string actorset);
	void setDuracion(int duracionset);
	void setGenero(string generoset);
	void setAnyo(string anyoset);
	void setFecha(string fechaset);
	void setHora(string horaset);
	void setPrecio(int precioset);
	void setAsistencia(int asistenciaset);*/


};
#endif