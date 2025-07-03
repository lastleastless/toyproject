#include <stdio.h>
#include <pthread.h>
extern int ITER;
extern int x;
void *thread_increment(void* arg)
{
	int i, val;
	for(i=0;i<ITER;i++)
	{
		val = x;
		printf("%u:     %d\n",(unsigned int)pthread_self(),val);
		x=val+1;
	}
	return NULL;
}

void *thread_decrement(void* arg)
{
	int i,val;
	for(i=0;i<ITER;i++)
	{
		val = x;
		printf("%u:     %d\n",(unsigned int)pthread_self(),val);
		x=val-1;
	}
	return NULL;
}

