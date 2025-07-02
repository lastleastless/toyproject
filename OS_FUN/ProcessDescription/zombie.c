#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc,char* argv[])
{
	pid_t pid = fork();
	printf("start[%d]\n",getpid());
	if(pid==0){
		printf("bye[%d]\n",getpid());
		exit(0);
	}
	else{
		sleep(20);
		printf("bye[%d]\n",getpid());
	}
	exit(0);
}

