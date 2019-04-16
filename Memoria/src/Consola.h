/*
 * Consola.h
 *
 *  Created on: 14 abr. 2019
 *      Author: utnso
 */

#ifndef CONSOLA_H_
#define CONSOLA_H_


#include "stddef.h"
#include "stdlib.h"
#include <readline/readline.h>
#include <commons/string.h>
#include <readline/history.h>
#include <stdio.h>

typedef void Funcion ();

typedef struct {
	char* nombre;
	Funcion* funcion;
} COMANDO;


void handleConsola();
void selectt (char** args);
void insert (char** args);
void create (char** args);
void describe (char** args);
void drop (char** args);
void journal (char** args);
void add (char** args);
void run (char** args);
void readLatency (char** args) ;
void writeLatency (char** args);
void reads (char** args);
void writes (char** args);
void memoryLoad (char** args);
int ejecutar_linea(char* linea);


#endif /* CONSOLA_H_ */
