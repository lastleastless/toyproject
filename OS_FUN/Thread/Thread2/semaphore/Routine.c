#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
extern int ITER;
extern int x;
extern pthread_mutex_t m;
void *thread_increment(void* arg)
{
	int i, val;
	for(i=0;i<ITER;i++)
	{
		pthread_mutex_lock(&m);
		val = x;
		printf("%u:     %d\n",(unsigned int)pthread_self(),val);
		x=val+1;
		pthread_mutex_unlock(&m);
	}
	pthread_exit(NULL);
}

void *thread_decrement(void* arg)
{
	int i,val;
	for(i=0;i<ITER;i++)
	{
		pthread_mutex_lock(&m);
		val = x;
		printf("%u:     %d\n",(unsigned int)pthread_self(),val);
		x=val-1;
		pthread_mutex_unlock(&m);
	}
	pthread_exit(NULL);
}

