#include <iostream>
#include <string>


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

	Pelicula(std::string titulo, std::string director, std::string actor, float duracion, std::string genero, int anyo, float precio, int fecha, int hora);

	~Pelicula();

	std::string getTitulo() const;
	std::string getDirector() const;
	std::string getActor() const;
	float getDuracion() const;
	std::string getGenero() const;
	int getAnyo() const;
	float getPrecio() const;
	int getFecha() const;
	int getHora() const;



};
