#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#define NUM 5
void pickup(int);
void eating(int);
void thinking(int);
void putdown(int);
void* philo(void*);
sem_t forks[NUM];
sem_t room;
int main()
{
	for(int i=0;i<NUM;i++)
	{
		sem_init(&forks[i],0,1);
	}
	sem_init(&room,0,4);
	for(unsigned long int i=0;i<NUM;i++)
	{
		pthread_create(&forks[i],NULL,philo,(void*)i);
	}
	for(int i =0;i<NUM;i++)
	{
		pthread_join(&forks[i],NULL);
	}
	printf("No deadlock! process End.\n");
	return 0;

}
void eating(int num)
{
	printf("philosopher %d is eating!\n",num);
	return;
}
void thinking(int num)
{
	printf("philosopher %d is thinking!\n",num);
	return;
}
void pickup(int num)
{
	printf("philosopher %d is picking up fork %d!\n",(num)%NUM);
        return;	
}
void putdown(int num)
{
	printf("philosopher %d is putting down fork %d\n",(num) % NUM);
	return;
}
void* philo(void* arg)
{
	int p_num = (unsigned long int)arg;
	sem_wait(&room);
	sem_wait(&fork[p_num]);
	pickup(p_num);
	sem_wait(&fork[(p_num+1) % NUM]);
	pickup(p_num+1);
	sem_post(&fork[(p_num+1) % NUM]);
	putdown(p_num+1);
	sem_post(&fork[(p_num)]);
	putdown(p_num);
	sem_post(&room);

}

