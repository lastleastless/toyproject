#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
void catchint(int);

int main()
{
	static struct sigaction act;
	act.sa_handler = catchint;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT,&act,NULL);
	printf("sleep call#1\n");
	sleep(1);
	printf("sleep call#2\n");
	sleep(1);
	printf("sleep call#3\n");
	sleep(1);
	printf("Exit\n");
	exit(0);
}

void catchint(int signo)
{
	printf("\nCATCHINT: signo=%d\n",signo);
	printf("CATCHINT: returning\n\n");
}
