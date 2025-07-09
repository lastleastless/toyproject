#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_ADDER 10000
int adder;
void* thread_fnc(void*);
sem_t s;
int main()
{
	adder = 0;
	pthread_t t1,t2,t3;
	sem_init(&s,0,1);
	pthread_create(&t1,NULL,thread_fnc,NULL);
	pthread_create(&t2,NULL,thread_fnc,NULL);
	pthread_create(&t3,NULL,thread_fnc,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	printf("Done! total adder: %d\n",adder);


}

void *thread_fnc(void* arg)
{
	sem_wait(&s);
	while(adder <=MAX_ADDER)
	{
		adder+=1;
		printf("+1 adder = %d from thread %u\n",adder,(unsigned int)pthread_self());
	}
	sem_post(&s);
	return NULL;
}
