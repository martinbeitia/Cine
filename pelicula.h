#include <iostream>
#include <string>
#include "sqlite3.h"

class Pelicula{
private:
	std::string titulo;
	std::string director;
	std::string actor;
	float duracion;
	std::string genero;
	int anyo;
	float precio;
	int fecha;
	int hora;

public:

	Pelicula(std::string titulo, std::string director, std::string actor, int duracion, std::string genero, int anyo,  std::string  fecha, std::string  hora, int precio,);

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



};
