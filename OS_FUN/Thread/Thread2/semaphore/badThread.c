#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int ITER;
extern void* thread_increment(void*);
extern void* thread_decrement(void*);
pthread_mutex_t m;
int x;

int main()
{
	pthread_mutex_init(&m,NULL);
	ITER = 100;
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,thread_increment,NULL);
	pthread_create(&tid2,NULL,thread_decrement,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	if(x!=0)
		printf("BOOM! counter %d\n",x);
	else
		printf("OK counter %d/n",x);
	pthread_mutex_destroy(&m);
}
