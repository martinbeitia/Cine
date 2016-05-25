#include <stdio.h> //PROYECTO
#include "save.h"
#include "Pelicula.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "sqlite3.h"
#include "gestor.h"

using namespace std;

class Gestor{

//private:
		
public:

sqlite3 *db = NULL;
int insertPeli(string basededatos){

	sqlite3_stmt *stmt;
	string titulo ;
		string director ;   
		string actor ;
		int duracion;
		string genero ;
		int anyo;
		string fecha ;
		string hora ;
		int precio;

	cout<<"Escribe el titulo de la pelicula"<<endl;
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


	char sentencia[]  = "insert into basededatos (titulo, director, actor, duracion, genero, anyo, fecha, hora, precio) values (?, ?, ?, ?, ?, ?, ?, ?, ?)";

	int result = sqlite3_prepare_v2(db, sentencia, strlen(sentencia)+1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");

		result = sqlite3_bind_text(stmt, 1, titulo.c_str(), titulo.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 2, director.c_str(), director.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 3, actor.c_str(), actor.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_int(stmt, 4, duracion);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 5, genero.c_str(), genero.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_int(stmt, 6, anyo);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 7, fecha.c_str(), fecha.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 8, hora.c_str(), hora.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_int(stmt, 9, precio);
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

		char sentencia[] = "delete from basededatos where titulo=borrar";

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

		char sql[] = "select * from basededatos";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (SELECT)\n");

		char titulo[100] ;
		char director[100] ;   
		char actor[100] ;
		int duracion;
		char genero[100] ;
		int anyo;
		char fecha[100] ;
		char hora[100] ;
		int precio;

		printf("\n");
		printf("\n");
		printf("Cartelera:\n");
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				strcpy(titulo, (char *) sqlite3_column_text(stmt, 0));
				strcpy(director, (char *) sqlite3_column_text(stmt, 1));
				strcpy(actor, (char *) sqlite3_column_text(stmt, 2));
				duracion = sqlite3_column_int(stmt, 3);
				strcpy(genero, (char *) sqlite3_column_text(stmt, 4));
				anyo  = sqlite3_column_int(stmt, 5);
				strcpy(fecha, (char *) sqlite3_column_text(stmt, 6));
				strcpy(hora, (char *) sqlite3_column_text(stmt, 7));
				precio = sqlite3_column_int(stmt, 8);

				cout << "Titulo: " << titulo << endl;
				cout << "Director: " << director << endl;
				cout << "Actor: " << actor << endl;
				cout << "Duracion (min.): " << duracion << endl;
				cout << "Genero: " << genero << endl;
				cout << "Año: " << anyo << endl;
				cout << "Fecha: " << fecha << endl;
				cout << "Hora: " << hora << endl;
				cout << "Precio (euros): " << precio << endl;
				cout << "----------------------------" << endl;
				
				
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

	int buscarpordirector(char buscar[] ){

		sqlite3_stmt *stmt;

		char sql[] = "select * from basededatos where director=buscar";
		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (SELECT)\n");

		char titulo[100] ;
		char director[100] ;   
		char actor[100] ;
		int duracion;
		char genero[100] ;
		int anyo;
		char fecha[100] ;
		char hora[100] ;
		int precio;

		printf("\n");
		printf("\n");
		cout << "Peliculas del director/a: " << buscar << endl;
		printf("\n");
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				strcpy(titulo, (char *) sqlite3_column_text(stmt, 0));
				strcpy(director, (char *) sqlite3_column_text(stmt, 1));
				strcpy(actor, (char *) sqlite3_column_text(stmt, 2));
				duracion = sqlite3_column_int(stmt, 3);
				strcpy(genero, (char *) sqlite3_column_text(stmt, 4));
				anyo  = sqlite3_column_int(stmt, 5);
				strcpy(fecha, (char *) sqlite3_column_text(stmt, 6));
				strcpy(hora, (char *) sqlite3_column_text(stmt, 7));
				precio = sqlite3_column_int(stmt, 8);

				cout << "Titulo: " << titulo << endl;
				cout << "Director: " << director << endl;
				cout << "Actor: " << actor << endl;
				cout << "Duracion (min.): " << duracion << endl;
				cout << "Genero: " << genero << endl;
				cout << "Año: " << anyo << endl;
				cout << "Fecha: " << fecha << endl;
				cout << "Hora: " << hora << endl;
				cout << "Precio (euros): " << precio << endl;
				cout << "----------------------------" << endl;
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

	int buscarporgenero(char buscardos[] ){

		sqlite3_stmt *stmt;

		char sql[] = "select * from basededatos where genero=buscardos";
		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (SELECT)\n");

		char titulo[100] ;
		char director[100] ;   
		char actor[100] ;
		int duracion;
		char genero[100] ;
		int anyo;
		char fecha[100] ;
		char hora[100] ;
		int precio;

		printf("\n");
		printf("\n");
		printf("Peliculas del genero %s: ",buscardos);
		printf("\n");
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				strcpy(titulo, (char *) sqlite3_column_text(stmt, 0));
				strcpy(director, (char *) sqlite3_column_text(stmt, 1));
				strcpy(actor, (char *) sqlite3_column_text(stmt, 2));
				duracion = sqlite3_column_int(stmt, 3);
				strcpy(genero, (char *) sqlite3_column_text(stmt, 4));
				anyo  = sqlite3_column_int(stmt, 5);
				strcpy(fecha, (char *) sqlite3_column_text(stmt, 6));
				strcpy(hora, (char *) sqlite3_column_text(stmt, 7));
				precio = sqlite3_column_int(stmt, 8);

				cout << "Titulo: " << titulo << endl;
				cout << "Director: " << director << endl;
				cout << "Actor: " << actor << endl;
				cout << "Duracion (min.): " << duracion << endl;
				cout << "Genero: " << genero << endl;
				cout << "Año: " << anyo << endl;
				cout << "Fecha: " << fecha << endl;
				cout << "Hora: " << hora << endl;
				cout << "Precio (euros): " << precio << endl;
				cout << "----------------------------" << endl;
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

	int buscarporanyo(char buscartres[] ){

		sqlite3_stmt *stmt;

		char sql[] = "select * from basededatos where anyo=buscartres";
		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (SELECT)\n");

		char titulo[100] ;
		char director[100] ;   
		char actor[100] ;
		int duracion;
		char genero[100] ;
		int anyo;
		char fecha[100] ;
		char hora[100] ;
		int precio;

		printf("\n");
		printf("\n");
		printf("Peliculas del año %s: ", buscartres);
		printf("\n");
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				strcpy(titulo, (char *) sqlite3_column_text(stmt, 0));
				strcpy(director, (char *) sqlite3_column_text(stmt, 1));
				strcpy(actor, (char *) sqlite3_column_text(stmt, 2));
				duracion = sqlite3_column_int(stmt, 3);
				strcpy(genero, (char *) sqlite3_column_text(stmt, 4));
				anyo  = sqlite3_column_int(stmt, 5);
				strcpy(fecha, (char *) sqlite3_column_text(stmt, 6));
				strcpy(hora, (char *) sqlite3_column_text(stmt, 7));
				precio = sqlite3_column_int(stmt, 8);

				cout << "Titulo: " << titulo << endl;
				cout << "Director: " << director << endl;
				cout << "Actor: " << actor << endl;
				cout << "Duracion (min.): " << duracion << endl;
				cout << "Genero: " << genero << endl;
				cout << "Año: " << anyo << endl;
				cout << "Fecha: " << fecha << endl;
				cout << "Hora: " << hora << endl;
				cout << "Precio (euros): " << precio << endl;
				cout << "----------------------------" << endl;
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

	int crearTabla(){

		Gestor *gestor= new Gestor("basededatos.sqlite");

		char commandline[]  = "CREATE TABLE IF NOT EXISTS basededatos(titulo VARCHAR(30), director VARCHAR(30), actor VARCHAR(30), duracion INT, genero VARCHAR(15), anyo INT, fecha VARCHAR(10), hora VARCHAR(10), precio INT)";
		sqlite3_stmt *stmt;

		

		int result = sqlite3_prepare_v2(gestor->db, commandline, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (CREATE)\n");
			printf("%s\n", sqlite3_errmsg(gestor->db));
			return result;
		}

		printf("SQL query prepared (CREATE)\n");

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error deleting data\n");
			printf("%s\n", sqlite3_errmsg(gestor->db));
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (CREATE)\n");
			printf("%s\n", sqlite3_errmsg(gestor->db));
			return result;
		}

		printf("Prepared statement finalized (CREATE)\n");
		return SQLITE_OK;

	}

	Gestor(string dbFile) {
		int result = sqlite3_open("basededatos.sqlite", &db);
		if (result != SQLITE_OK) {
			printf("Error opening database\n");

		}
	}

	~Gestor() {
		int result = sqlite3_close(db);
		if (result != SQLITE_OK) {
			printf("Error opening database\n");
			printf("%s\n", sqlite3_errmsg(db));
		}	
	}

};

/*int main(void){

	cout<< "probando" << endl;

	Gestor *gestor= new Gestor("basededatos.sqlite");
	char titulo[100] ;
		char director[100] ;   
		char actor[100] ;
		int duracion;
		char genero[100] ;
		int anyo;
		char fecha[100] ;
		char hora[100] ;
		int precio;

	char commandline[]  = "CREATE TABLE IF NOT EXISTS basededatos(titulo VARCHAR(10), director VARCHAR(10), actor VARCHAR(10), duracion INT, genero VARCHAR(10), anyo INT, fecha VARCHAR(10), hora VARCHAR(10), precio INT)";
	sqlite3_stmt *stmt;

		

		int result = sqlite3_prepare_v2(gestor->db, commandline, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (CREATE)\n");
			printf("%s\n", sqlite3_errmsg(gestor->db));
			return result;
		}

		printf("SQL query prepared (CREATE)\n");

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error deleting data\n");
			printf("%s\n", sqlite3_errmsg(gestor->db));
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (CREATE)\n");
			printf("%s\n", sqlite3_errmsg(gestor->db));
			return result;
		}

		printf("Prepared statement finalized (CREATE)\n");
	gestor->insertPeli("basededatos");
	gestor->mostrarPelis();
	return SQLITE_OK;
}*/
