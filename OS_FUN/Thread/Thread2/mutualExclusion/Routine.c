#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
extern int ITER;
extern int x;
bool enter_thread[2];
int turn;
extern int turn;

void initializer()
{
	enter_thread[0] = false;
        enter_thread[1] = false;	
}
void *thread_increment(void* arg)
{
	//critical Section
	do{
		enter_thread[0] = true;
		turn = 1;
		while(enter_thread[1]&&turn==1);
		int i, val;
		for(i=0;i<ITER;i++)
		{
			val = x;
			printf("%u:     %d\n",(unsigned int)pthread_self(),val);
			x=val+1;
		}
		enter_thread[0] = false;
		return NULL;
	} while(true);
	//remainder critical Section
}

void *thread_decrement(void* arg)
{
	int i,val;
	//critical section
	do{
		enter_thread[1]= true;
		turn = 0;
		while(enter_thread[0] && turn == 0);
		for(i=0;i<ITER;i++){
			val = x;
			printf("%u:     %d\n",(unsigned int)pthread_self(),val);
			x=val-1;}
		enter_thread[1] = false;
		return NULL;
	} while(true);
	//remainder critical_section
}

