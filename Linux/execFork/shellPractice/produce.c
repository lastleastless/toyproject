#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <semaphore.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

bool in;
char message[10];
int counter;
void* producer(void*);
void* consumer(void*);
pthread_mutex_t m;
sem_t create;
sem_t consumed;
sem_t msg;
int main()
{
	in = false;
	counter = 0;
	pthread_t tid1,tid2,tid3,tid4;
	pthread_mutex_init(&m,NULL);
	pthread_create(&tid1,NULL,producer,NULL);
	pthread_create(&tid2,NULL,consumer,NULL);
	pthread_create(&tid3,NULL,consumer,NULL);
	pthread_create(&tid4,NULL,consumer,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
	pthread_join(tid4,NULL);
	pthread_mutex_destroy(&m);
}
void* producer(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&m);
		for(int i=0;i<10;i++)
		{
			message[i]='a' + rand() % 10;
		}
		printf("making msg:%s Done by %u thread\n",message,(unsigned int)pthread_self());
		pthread_mutex_unlock(&m);
		sleep(1);
	}

}
void* consumer(void* arg)
{
	while(1){
	pthread_mutex_lock(&m);
	printf("%u gets %s!\n",(unsigned int)pthread_self(),message);
	pthread_mutex_unlock(&m);
	sleep(1);
	}
}
