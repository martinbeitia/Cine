
#ifndef _SAVE_H_
#define _SAVE_H_
#include <stdio.h>
#include "sqlite3.h"
typedef int bool;
#define true 1
#define false 0
typedef struct{
	char* nombre;
	char* contra;

}Usuario;



#ifdef __cplusplus
extern "C" 
{
	#endif
	void save(Usuario u);
	bool read(Usuario u);
	bool comprobar(Usuario u);
	#ifdef __cplusplus
}
#endif

#endif