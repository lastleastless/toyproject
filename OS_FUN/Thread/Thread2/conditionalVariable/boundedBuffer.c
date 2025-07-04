#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 5

void* Producer(void*);
void* Consumer(void*);
void put();
int get();
int buffer[MAX_SIZE];
int counter;
static pthread_mutex_t m;
static pthread_cond_t empty;
static pthread_cond_t fill;
int main(int argc,char* argv[])
{
	counter = 0;
	pthread_t producer;
	pthread_t consumer;
	pthread_mutex_init(&m,NULL);
	pthread_cond_init(&empty,NULL);
	pthread_cond_init(&fill,NULL);
	pthread_create(&producer,NULL,Producer,NULL);
	pthread_create(&consumer,NULL,Consumer,NULL);
	pthread_join(producer,NULL);
	pthread_join(consumer,NULL);
	return 0;

	
}
int get()
{
	int index;
	counter--;
	while(counter>=0)
	{	
		printf("switch a value 1 to 0 at index: %d\n",counter);
		buffer[counter]=0;
		counter--;
		sleep(2);
	}
	printf("Current counter: %d\n",counter);
	return 0;
}
void put()
{
	while(counter <= MAX_SIZE-1)
	{
		buffer[counter]=1;
		printf("Put a value 1 to index:%d.\n",counter);
		counter++;
		sleep(2);
	}
	printf("Current Counter: %d\n",counter);
}

void* Producer(void* args)
{
	while(1){
	pthread_mutex_lock(&m);
	while(counter>0)
		pthread_cond_wait(&empty,&m);
	put();
	pthread_cond_signal(&fill);
	pthread_mutex_unlock(&m);
	printf("Done filling Buffer.\n");
	;}
}
void* Consumer(void* args)
{
	while(1){
	pthread_mutex_lock(&m);
	while(counter==0)
		pthread_cond_wait(&fill,&m);
	get();
	pthread_cond_signal(&empty);
	pthread_mutex_unlock(&m);
	printf("Done empty Buffer.\n");
	;}
}
