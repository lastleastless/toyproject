#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int sum;

void *runner(void *param)
{
	int i, upper = atoi(param);
	sum = 0;
	for(i=1; i<=upper ; i++)
		sum+=i;
	pthread_exit(0);
}

