#include <stdio.h> //PROYECTO
#include "save.h"
#include "Pelicula.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

class Gestor{

private:
		sqlite3 *db = NULL;
public:
int metidas =0;

int insertPeli(string basededatos){

	sqlite3_stmt *stmt;
	string titulo;
	string director;
	string actor;
	float duracion;
	string genero;
	int anyo;
	int fecha;
	int hora;
	float precio;

	cout<<"Escribe el nombre de la pelicula"<<endl;
	cin>>titulo;
	cout<<"Escribe el director de la pelicula"<<endl;
	cin>>director;
	cout<<"Escribe el actor de la pelicula"<<endl;
	cin>>actor;
	cout<<"Escribe la duracion de la pelicula"<<endl;
	cin>>duracion;
	cout<<"Escribe el genero de la pelicula"<<endl;
	cin>>genero;
	cout<<"Escribe el anyo de la pelicula"<<endl;
	cin>>anyo;
	cout<<"Escribe la fecha de la pelicula"<<endl;
	cin>>fecha;
	cout<<"Escribe la hora de la pelicula"<<endl;
	cin>>hora;
	cout<<"Escribe el precio de la pelicula"<<endl;
	cin>>precio;

	metidas++;

	string sentencia = "insert into basededatos (titulo, director, actor, duracion, genero, anyo, fecha, hora, precio) values (NULL,?)";

	int result = sqlite3_prepare_v2(db, sentencia, sentencia.length(), &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");

		result = sqlite3_bind_text(stmt, 1, basededatos.c_str(), basededatos.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into country table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (INSERT)\n");

		return SQLITE_OK;

}

int borrarPeli(string borrar){
	sqlite3_stmt *stmt;

		string sentencia = "delete from basededatos where titulo=borrar";

		int result = sqlite3_prepare_v2(db, sentencia, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (DELETE)\n");

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error deleting data\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (DELETE)\n");

		return SQLITE_OK;
}

int mostrarPelis() {
		sqlite3_stmt *stmt;

		char sql[] = "select titulo, director, actor, duracion, genero, anyo, fecha, hora, precio from basededatos";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (SELECT)\n");

		int id;
		char name[100];

		printf("\n");
		printf("\n");
		printf("Cartelera:\n");
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				id = sqlite3_column_int(stmt, 0);
				strcpy(name, (char *) sqlite3_column_text(stmt, 1));
				printf("ID: %d Name: %s\n", id, name);
			}
		} while (result == SQLITE_ROW);

		printf("\n");
		printf("\n");

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (SELECT)\n");

		return SQLITE_OK;
	}

}