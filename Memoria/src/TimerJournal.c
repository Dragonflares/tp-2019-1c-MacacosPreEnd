#include "TimerJournal.h"

void journalInTime(){
	while(1){
		usleep(info_memoria.tiempo_jour *1000);
		printf("Se procedera a realizar el journal debido a su timer");
		pthread_mutex_lock(&mutex_estructuras_memoria);
		journalReq();
		pthread_mutex_unlock(&mutex_estructuras_memoria);
	}
}
