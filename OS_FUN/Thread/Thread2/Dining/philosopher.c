#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define true 1
#define NUM 5
sem_t forks[NUM];
void pickup(int);
void putdown(int);
void thinking(int);
void eating(int);
void *philo(void*);
int main()
{
	pthread_t threads[NUM];
	for(int i = 0; i < NUM ; i++)
		sem_init(&forks[i],0,1);
	for(unsigned long int i =0; i < NUM ; i++)
		pthread_create(&threads[i],NULL,philo,(void*)i);
	for(int i=0; i < NUM; i++)
		pthread_join(threads[i],NULL);
	printf("No deadlock!\n");
	return 0;
}
void pickup(int num)
{
	sem_wait(&forks[num % NUM]);
}
void putdown(int num)
{
	sem_post(&forks[num % NUM]);
}
void thinking(int num)
{
	printf("philosopher %d is thinking.\n",num);
	return;
}
void eating(int num)
{
	printf("philosopher %d is eating.\n",num);
	return;
}
void *philo(void* arg)
{
	int p_num;
	p_num = (unsigned long int)arg;
	while(true)
	{
		pickup(p_num);
		printf("philosopher %d picks up the fork %d\n",p_num,p_num);
		pickup(p_num+1);
		printf("philosopher %d picks up the fork %d\n",p_num,(p_num+1) % NUM);
		eating(p_num);
		putdown(p_num+1);
		printf("philosopher %d puts down the fork %d\n",p_num,(p_num+1)%NUM);
		putdown(p_num);
		printf("philosopher %d puts down the fork %d\n",p_num,p_num);
		thinking(p_num);
	}
	return NULL;
}
