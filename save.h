
#ifndef _SAVE_H_
#define _SAVE_H_
#include <stdio.h>
#include "sqlite3.h"

typedef struct{
	char* nombre;
	char* contra;

}Usuario;



#ifdef __cplusplus
extern "C" 
{
	#endif
	void save(Usuario u);
	int read(Usuario u);
	int comprobar(Usuario u);
	#ifdef __cplusplus
}
#endif

#endif