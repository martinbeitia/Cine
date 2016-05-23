
#ifndef _SAVE_H_
#define _SAVE_H_
#include <stdio.h>
#include "sqlite3.h"
//typedef int bool;
//#define true 1
//#define false 0



#ifdef __cplusplus
extern "C" 
{
	#endif
	void save(char nombre[],char contra[]);
	bool read(char nombre[], char contra[]);
	bool comprobar(char nombre[]);
	#ifdef __cplusplus
}
#endif

#endif