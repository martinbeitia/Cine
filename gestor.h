#include <stdio.h> //PROYECTO
#include "save.h"
#include "Pelicula.h"
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

	public:

		Gestor(string dbFile);
		~Gestor();

		int insertPeli();
		int borrarPeli(string borrar);
		int mostrarPelis();
		int buscarpordirector(char buscar[]);
		int buscarporgenero(char buscardos[]);
		int buscarporanyo(char buscartres[]);
		int crearTabla();


};

#endif