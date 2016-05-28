#include <stdio.h> //PROYECTO
#include "save.h"
#include "pelicula.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "sqlite3.h"
#ifndef _GESTOR_H_
#define _GESTOR_H_

using namespace std;

class Gestor{

	private:
	sqlite3 *db = NULL;
	int asistenciacine;
	float recaudacion;
	float mediarecaudacion;


	public:

		Gestor(string dbFile);
		~Gestor();

		int insertPeli();
		int borrarPeli(string borrar);
		int mostrarPelis();
		int buscarpordirector(string buscar);
		int buscarporgenero(string buscardos);
		int buscarporanyo(string buscartres);
		int crearTabla();
		void puntuar();
		void informacioncartelera();
		int aumentarAsistencia(string titulo);
		int devolverAsistencia();


};

#endif