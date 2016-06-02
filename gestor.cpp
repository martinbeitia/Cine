#include <stdio.h> //PROYECTO
#include "save.h"
#include "pelicula.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "sqlite3.h"
#include "gestor.h"
using namespace std;

//sqlite3 *db = NULL;
void clear_if_neededotro(char *str)
{
    if (str[strlen(str) - 1] != '\n')
    {
        int c;    
        while ( (c = getchar()) != EOF && c != '\n');
    }
}


int Gestor::insertPeli(){

	sqlite3_stmt *stmt;
	
	string titulo;
	string director;   
	string actor;
	int duracion;
	string genero;
	int anyo;
	string fecha;
	string hora;
	int precio;
	int asistencia;

	cout<<"Escribe el titulo de la pelicula:"<<endl;
	getline(cin, titulo);
	cout<<"Escribe el director de la pelicula:"<<endl;
	getline(cin, director);
	cout<<"Escribe el actor de la pelicula:"<<endl;
	getline(cin, actor);
	cout<<"Escribe el genero de la pelicula:"<<endl;
	getline(cin, genero);
	cout<<"Escribe la fecha de la pelicula:"<<endl;
	getline(cin, fecha);
	cout<<"Escribe la hora de la pelicula:"<<endl;
	getline(cin, hora);
	cout<<"Escribe la duracion de la pelicula:"<<endl;
	cin>>duracion;
	cout<<"Escribe el anyo de la pelicula:"<<endl;
	cin>>anyo;
	cout<<"Escribe el precio de la pelicula:"<<endl;
	cin>>precio;
	//cout<<"Escribe la asistencia esperada de la pelicula:"<<endl;
	//cin>>asistencia;
	char sentencia[]  = "insert into basededatos (titulo, director, actor, duracion, genero, anyo, fecha, hora, precio, asistencia) values (?, ?, ?, ?, ?, ?, ?, ?, ?, 0)";

	int result = sqlite3_prepare_v2(db, sentencia, strlen(sentencia)+1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		//printf("SQL query prepared (INSERT)\n");

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
		//result = sqlite3_bind_int(stmt, 10, asistencia);
		//if (result != SQLITE_OK) {
			//printf("Error binding parameters\n");
			//printf("%s\n", sqlite3_errmsg(db));
			//return result;
		//}

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

		//printf("Prepared statement finalized (INSERT)\n");

		return SQLITE_OK;

}

int Gestor::borrarPeli(string borrar){
	sqlite3_stmt *stmt;

		char sentencia[] = "delete from basededatos where titulo=?";

		

		 int result = sqlite3_prepare_v2(db, sentencia, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		//printf("SQL query prepared (DELETE)\n");

		 result = sqlite3_bind_text(stmt, 1, borrar.c_str(), borrar.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

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

		//printf("Prepared statement finalized (DELETE)\n");

		return SQLITE_OK;
}

int Gestor::mostrarPelis() {
		sqlite3_stmt *stmt;

		char sql[] = "select * from basededatos";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			//return result;
		}

		//printf("SQL query prepared (SELECT)\n");

		char titulo[100] ;
		char director[100] ;   
		char actor[100] ;
		int duracion;
		char genero[100] ;
		int anyo;
		char fecha[100] ;
		char hora[100] ;
		int precio;
		int asistencia;
		int probar=0;

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
				asistencia = sqlite3_column_int(stmt, 9);

				cout << "Titulo: " << titulo << endl;
				cout << "Director: " << director << endl;
				cout << "Actor: " << actor << endl;
				cout << "Duracion (min.): " << duracion << endl;
				cout << "Genero: " << genero << endl;
				cout << "Anyo: " << anyo << endl;
				cout << "Fecha: " << fecha << endl;
				cout << "Hora: " << hora << endl;
				cout << "Precio (euros): " << precio << endl;
				cout << "Asistencia: " << asistencia << endl;
				cout << "----------------------------" << endl;
				probar =1;
				
				
			}
		} while (result == SQLITE_ROW);

		printf("\n");
		printf("\n");

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			//return result;
		}

		//printf("Prepared statement finalized (SELECT)\n");

		return probar;
	}

	int Gestor::buscarpordirector(string buscar){

		sqlite3_stmt *stmt;

		char sql[] = "select * from basededatos where director=?";
		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		//printf("SQL query prepared (SELECT)\n");

		 result = sqlite3_bind_text(stmt, 1, buscar.c_str(), buscar.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		char titulo[100] ;
		char director[100] ;   
		char actor[100] ;
		int duracion;
		char genero[100] ;
		int anyo;
		char fecha[100] ;
		char hora[100] ;
		int precio;
		int asistencia;

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
				asistencia = sqlite3_column_int(stmt, 9);

				cout << "Titulo: " << titulo << endl;
				cout << "Director: " << director << endl;
				cout << "Actor: " << actor << endl;
				cout << "Duracion (min.): " << duracion << endl;
				cout << "Genero: " << genero << endl;
				cout << "Año: " << anyo << endl;
				cout << "Fecha: " << fecha << endl;
				cout << "Hora: " << hora << endl;
				cout << "Precio (euros): " << precio << endl;
				cout << "Asistencia: " << asistencia << endl;
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

		//printf("Prepared statement finalized (SELECT)\n");
		return SQLITE_OK;
	}

	int Gestor::buscarporgenero(string buscardos){

		sqlite3_stmt *stmt;

		char sql[] = "select * from basededatos where genero=?";
		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		//printf("SQL query prepared (SELECT)\n");

		 result = sqlite3_bind_text(stmt, 1, buscardos.c_str(), buscardos.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		char titulo[100] ;
		char director[100] ;   
		char actor[100] ;
		int duracion;
		char genero[100] ;
		int anyo;
		char fecha[100] ;
		char hora[100] ;
		int precio;
		int asistencia;

		printf("\n");
		printf("\n");
		cout << "Peliculas del genero: " << buscardos << endl;
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
				asistencia = sqlite3_column_int(stmt, 9);

				cout << "Titulo: " << titulo << endl;
				cout << "Director: " << director << endl;
				cout << "Actor: " << actor << endl;
				cout << "Duracion (min.): " << duracion << endl;
				cout << "Genero: " << genero << endl;
				cout << "Año: " << anyo << endl;
				cout << "Fecha: " << fecha << endl;
				cout << "Hora: " << hora << endl;
				cout << "Precio (euros): " << precio << endl;
				cout << "Asistencia: " << asistencia << endl;
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

		//printf("Prepared statement finalized (SELECT)\n");
		return SQLITE_OK;
	}

	int Gestor::buscarporanyo(string buscartres){

		sqlite3_stmt *stmt;

		char sql[] = "select * from basededatos where anyo=?";
		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		//printf("SQL query prepared (SELECT)\n");

		 result = sqlite3_bind_text(stmt, 1, buscartres.c_str(), buscartres.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		char titulo[100] ;
		char director[100] ;   
		char actor[100] ;
		int duracion;
		char genero[100] ;
		int anyo;
		char fecha[100] ;
		char hora[100] ;
		int precio;
		int asistencia;

		printf("\n");
		printf("\n");
		cout << "Peliculas del anyo: " << buscartres << endl;
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
				asistencia = sqlite3_column_int(stmt, 9);

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

		//printf("Prepared statement finalized (SELECT)\n");
		return SQLITE_OK;
	}

	int Gestor::crearTabla(){

		//Gestor *gestor= new Gestor("basededatos.sqlite");

		char commandline[]  = "CREATE TABLE IF NOT EXISTS basededatos(titulo VARCHAR(30), director VARCHAR(30), actor VARCHAR(30), duracion INT, genero VARCHAR(15), anyo INT, fecha VARCHAR(10), hora VARCHAR(10), precio INT, asistencia INT)";
		sqlite3_stmt *stmt;

		

		int result = sqlite3_prepare_v2(db, commandline, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (CREATE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		//printf("SQL query prepared (CREATE)\n");

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error deleting data\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (CREATE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		//printf("Prepared statement finalized (CREATE)\n");
		return SQLITE_OK;

	}

	Gestor::Gestor(string dbFile) {
		int result = sqlite3_open(dbFile.c_str(), &db);
		if (result != SQLITE_OK) {
			printf("Error opening database\n");

		}
	}

	Gestor::~Gestor() {
		int result = sqlite3_close(db);
		if (result != SQLITE_OK) {
			printf("Error opening database\n");
			printf("%s\n", sqlite3_errmsg(db));
		}	
	}



void Gestor::puntuar()
{

	int puntuacion;
	int puntuacionf;

	FILE* file;
		
	file=fopen("Puntuaciones.txt","r");
	if(file==NULL)
		{
			file=fopen("Puntuaciones.txt","w");
			do{
			cout<<"Como valoraria A team studios? Dejenos su valoracion global de la aplicacion: ";
			cin>>puntuacion;
			
			if(puntuacion >=0 && puntuacion <=10){
			fprintf(file,"%i",puntuacion);
			}else{
				cout << "La puntuacion ha de ser mayor que 0 y menor que 10" << endl;
			}
			}while(puntuacion <0 || puntuacion >10);
		}
	else
		{

			cout << "Pulse intro"<<endl;
			char str[10];
			file=fopen("Puntuaciones.txt","r");

			while(fgets(str,10,file)!=NULL)
			{
				clear_if_neededotro(str);

				sscanf(str,"%i",&puntuacionf);
			}
			fclose(file);
			
			file=fopen("Puntuaciones.txt","w");
			do{
			cout<<"Como valoraria A team studios? Dejenos su valoracion global de la aplicacion: ";
			cin>>puntuacion;
			if(puntuacion >=0 && puntuacion <=10){
			puntuacionf += puntuacion;	
			fprintf(file,"%i",puntuacionf);
			}else{
				cout << "La puntuacion ha de ser mayor que 0 y menor que 10" << endl;
			}
			}while(puntuacion <0 || puntuacion >10);
		}
		fclose(file);
}
int Gestor::consultarPuntuacion(){


	int puntuacion;
	char str[10];

	FILE* file;
		
	file=fopen("Puntuaciones.txt","r");
	if(file==NULL)
		{
			cout << "Todavia no ha habido puntuaciones" <<endl;
		}
	else
		{

			cout << "Pulse intro"<<endl;
			char str[10];
			file=fopen("Puntuaciones.txt","r");

			while(fgets(str,10,file)!=NULL)
			{
				clear_if_neededotro(str);

				sscanf(str,"%i",&puntuacion);
				
			}
			
			
			
		}
		fclose(file);


	return puntuacion;
}

int Gestor::aumentarAsistencia(string titulo){

	sqlite3_stmt *stmt;
	int actualizar;
	char sentencia[] = "select asistencia from basededatos where titulo=?";
	int result = sqlite3_prepare_v2(db, sentencia, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout <<  sqlite3_errmsg(db) << endl;
		}

		//printf("SQL query prepared (SELECT)\n");

		 result = sqlite3_bind_text(stmt, 1, titulo.c_str(), titulo.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout <<  sqlite3_errmsg(db) << endl;
		}

		
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				actualizar = sqlite3_column_int(stmt, 0) + 1;
				
			}
		} while (result == SQLITE_ROW);
		
		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout <<  sqlite3_errmsg(db) << endl;
		}

		//printf("Prepared statement finalized (SELECT)\n");
		
		return actualizar;
}

int Gestor::actualizarAsistencia(string titulo){

		sqlite3_stmt *stmt;
		int meter = aumentarAsistencia(titulo);
		char sql[] = "update basededatos set asistencia=? where titulo=?";
		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (UPDATE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		//printf("SQL query prepared (UPDATE)\n");
		result = sqlite3_bind_int(stmt, 1, meter);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		 result = sqlite3_bind_text(stmt, 2, titulo.c_str(), titulo.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (UPDATE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		//printf("Prepared statement finalized (UPDATE)\n");

		return SQLITE_OK;
	}

void Gestor::guardarAsistencia(){

	int asistencia =1;
	int asistenciaf;
	char str[10];

	FILE* file;
		
	file=fopen("Asistenciatotal.txt","r");
	if(file==NULL)
		{
			file=fopen("Asistenciatotal.txt","w");
			fprintf(file,"%i",asistencia);
		}
	else
		{

			//cout << "Pulse intro"<<endl;
			char str[10];
			file=fopen("Asistenciatotal.txt","r");

			while(fgets(str,10,file)!=NULL)
			{
				clear_if_neededotro(str);

				sscanf(str,"%i",&asistenciaf);
				asistenciaf++;	
			}
			fclose(file);
			
			file=fopen("Asistenciatotal.txt","w");
			
			fprintf(file,"%i",asistenciaf);
		}
		fclose(file);


}

int Gestor::consultarAsistencia(){


	int asistencia;
	char str[10];

	FILE* file;
		
	file=fopen("Asistenciatotal.txt","r");
	if(file==NULL)
		{
			cout << "Todavia no ha habido visitas" <<endl;
		}
	else
		{

			cout << "Pulse intro"<<endl;
			char str[10];
			file=fopen("Asistenciatotal.txt","r");

			while(fgets(str,10,file)!=NULL)
			{
				clear_if_neededotro(str);

				sscanf(str,"%i",&asistencia);
				
			}
			
			
			
		}
		fclose(file);


	return asistencia;
}

int Gestor::sacarPrecio(string titulo){

	sqlite3_stmt *stmt;
	int actualizar=-1;
	char sentencia[] = "select precio from basededatos where titulo=?";
	int result = sqlite3_prepare_v2(db, sentencia, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout <<  sqlite3_errmsg(db) << endl;
		}

		//printf("SQL query prepared (SELECT)\n");

		 result = sqlite3_bind_text(stmt, 1, titulo.c_str(), titulo.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout <<  sqlite3_errmsg(db) << endl;
		}

		
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				actualizar = sqlite3_column_int(stmt, 0);
				
			}
		} while (result == SQLITE_ROW);
		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout <<  sqlite3_errmsg(db) << endl;
		}

		//printf("Prepared statement finalized (SELECT)\n");
		//cout<<actualizar;
		return actualizar;
}

void Gestor::guardarRecaudacion(string titulo){

	int recaudacion;
	int recaudacionf;

	FILE* file;
		
	file=fopen("Recaudacion.txt","r");
	if(file==NULL)
		{
			file=fopen("Recaudacion.txt","w");
			recaudacion=sacarPrecio(titulo);
			fprintf(file,"%i",recaudacion);
		}
	else
		{

			cout << "Pulse intro"<<endl;
			char str[10];
			file=fopen("Recaudacion.txt","r");

			while(fgets(str,10,file)!=NULL)
			{
				clear_if_neededotro(str);

				sscanf(str,"%i",&recaudacionf);
			}
			fclose(file);
			
			file=fopen("Recaudacion.txt","w");
			recaudacionf += sacarPrecio(titulo);	
			fprintf(file,"%i",recaudacionf);
		}
		fclose(file);
		//cout<<recaudacionf;
}
int Gestor::consultarRecaudacion(){


	int recaudacion;
	char str[10];

	FILE* file;
		
	file=fopen("Recaudacion.txt","r");
	if(file==NULL)
		{
			cout << "Todavia no hay tesoreria" <<endl;
		}
	else
		{

			cout << "Pulse intro"<<endl;
			char str[10];
			file=fopen("Recaudacion.txt","r");

			while(fgets(str,10,file)!=NULL)
			{
				clear_if_neededotro(str);

				sscanf(str,"%i",&recaudacion);
				
			}
			
			
			
		}
		fclose(file);

		return recaudacion;

	}