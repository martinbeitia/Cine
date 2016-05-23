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

	std::string getTitulo();
	std::string getDirector();
	std::string getActor();
	float getDuracion();
	std::string getGenero();
	int getAnyo();
	float getPrecio();
	int getFecha();
	int getHora();



};
