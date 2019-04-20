#include "Consola.h"

COMANDO comandos[] = {
		{"SELECT",selectt},
		{"INSERT",insert},
		{"CREATE",create},
		{"DESCRIBE",describe},
		{"DROP",drop},
		{(char *) NULL, (Funcion *) NULL}
};

void consola()
{
	puts("-_____________________________________________________");
	puts("CONSOLA");
	puts("------ Escriba un comando ------");
	puts("1. - SELECT");
	puts("2. - INSERT");
	puts("3. - CREATE");
	puts("4. - DESCRIBE");
	puts("5. - DROP");
	char* linea;
//ejecutar prueba.txt
	while (1) {
		linea = readline("\nIngrese su comando deseado y los parámetros que necesite: ");

		if (strcmp(linea, "exit")==0){
			free(linea);
			puts("EXIT.");
			break;
		}

		if (ejecutar_linea(linea)){
			add_history(linea);
		}
		free(linea);
	}
}

COMANDO * buscar_comando(char* linea) {
	int i;

	for (i = 0; comandos[i].nombre; i++){
		// Paso a miniscula y comparo
		string_to_lower(linea);
		char* comando = string_duplicate(comandos[i].nombre);
		string_to_lower(comando);

		if (strcmp (linea, comando) == 0){
			free(comando);
			return (&comandos[i]);
		}
		free(comando);

	}
	return ((COMANDO *) NULL);
}

int ejecutar_linea (char * linea){
	char * linea_aux = string_duplicate(linea);
	int i = 0;
	char * funcion;

	if(string_contains(linea, " "))
	{
			while (linea_aux[i] != ' ') i++;

			funcion = malloc((sizeof(char) * i) + 1);
			strncpy(funcion, linea_aux, i);
			funcion[i] = '\0';
	}else{
			funcion = string_duplicate(linea_aux);
	}

	COMANDO * comando = buscar_comando(funcion);

	char** args = string_split(linea_aux, " ");
	if (!comando) {
		printf ("%s: el comando ingresado es incorrecto.", funcion);
		return (-1);
	}

	free(funcion);
	free(linea_aux);
	//Llamo a la función
	(*(comando->funcion)) (args);
	free(args[0]);
	free(args[1]);

	free(args);
	return 1;
}

void selectt (char** args)
{
	log_info(loggerLFL, "Consola: Se ha recibido un pedido de select.");
	if(chequearParametros(args, 3) == 1)
	{
		printf("Por favor, especifique la cantidad de parámetros solicitada");
		log_error(loggerLFL, "Consola: solicitud errónea de parámetros");
	}
	else
	{
		char* tabla = string_new();
		tabla = malloc(strlen(args[1]));
		strcpy(tabla, args[1]);
		char* claveaux = string_new();
		claveaux = malloc(strlen(args[2]));
		strcpy(claveaux, args[2]);
		uint16_t key = atoi(claveaux);
//		t_keysetter keysetterObtenido = selectKey(tabla, key);
		free(tabla);
		free(claveaux);
	}
}

void insert (char** args)
{
	log_info(loggerLFL, "Consola: Se ha recibido un pedido de insert.");
	int chequeo = 0;
	if(args[4] == NULL )
		chequeo = chequearParametros(args, 4);
	else
		chequeo = chequearParametros(args, 5);
	if(chequeo == 1)
	{
		printf("Por favor, especifique la cantidad de parámetros solicitada");
		log_error(loggerLFL, "Consola: solicitud errónea de parámetros");
	}
	else
	{
		char* tabla = string_new();
		tabla = malloc(strlen(args[1]));
		strcpy(tabla, args[1]);
		char* claveaux = string_new();
		claveaux = malloc(strlen(args[2]));
		strcpy(claveaux, args[2]);
		uint16_t key = atoi(claveaux);
		char* value = string_new();
		value = malloc(strlen(args[3]));
		if(args[4] == NULL)
		{
			time_t timestampact = time(NULL);
			insertKeysetter(tabla, key, value, timestampact);
			log_info(loggerLFL, "Consola: Insert realizado.");
		}
		else
		{
			char* timestampaux = string_new;
			timestampaux = malloc(strlen(args[4]));
			strcpy(timestampaux, args[4]);
//			time_t timestamp = strftime();
//			insertKeysetter(tabla, key, value, timestamp);
		}
		free(tabla);
		free(claveaux);
		free(value);
	}
}

void create (char** args)
{
	log_info(loggerLFL, "Consola: Se ha recibido un pedido de create.");
	if(chequearParametros(args, 5) == 1)
	{
		printf("Por favor, especifique la cantidad de parámetros solicitada");
		log_error(loggerLFL, "Consola: solicitud errónea de parámetros");
	}
	else
	{
		char* tabla = string_new();
		tabla = malloc(strlen(args[1]));
		strcpy(tabla, args[1]);
		char* consistencia = string_new();
		consistencia = malloc(strlen(args[2]));
		strcpy(consistencia, args[2]);
		char* particionesaux = string_new();
		particionesaux = malloc(strlen(args[3]));
		strcpy(particionesaux, args[3]);
		int particiones = atoi(particionesaux);
		char* intervaloCompactacionaux = string_new();
		intervaloCompactacionaux = malloc(strlen(args[4]));
		int intervaloCompactacion = atoi(intervaloCompactacionaux);
		switch(llamadoACrearTabla(tabla, consistencia, particiones, intervaloCompactacion))
		{
			case 0:
			{
				log_info(loggerLFL, "Consola: Tabla creada satisfactoriamente");
				break;
			}
			case 2:
			{
				log_info(loggerLFL, "Consola: Tabla ya existía");
				break;
			}
			default:
			{
				log_error(loggerLFL, "Consola: La tabla o alguna de sus partes no pudo ser creada");
				break;
			}
		}
	}
}

void describe (char** args)
{

}

void drop (char** args)
{

}

int chequearParametros(char** args, int cantParametros)
{
	int i;
	int parametroinvalido = 0;
	for(i = 1 ; i < cantParametros; i++)
	{
		if(args[i] == NULL || args[cantParametros] != NULL)
		{
			parametroinvalido = 1;
			break;
		}
		else
			parametroinvalido = 0;

	}
	return parametroinvalido;
}
