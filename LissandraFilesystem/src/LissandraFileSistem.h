#ifndef LISSANDRAFILESISTEM_H_
#define LISSANDRAFILESISTEM_H_

#include <stdio.h>
#include <stdlib.h>
#include <commons/config.h>
#include <commons/log.h>
#include <pthread.h>
#include <loggers.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <commons/collections/list.h>
#include <conexiones.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "Lissandra.h"
#include "Compactador.h"
#include "FileSistem.h"
#include "Consola.h"

/* ESTRUCTURAS */

t_list * hilos;

/* VARIABLES GLOBALES */
t_log * loggerLFL;




/* SEMAFOROS */

/* FUNCIONES */
int main(void);
void iniciar();
void setearValores(t_config * archivoConfig);
void iniciarConsola();
void iniciarLissandra();
void iniciarFileSistem();
void iniciarCompactador();


#endif /* LISSANDRAFILESISTEM_H_ */
