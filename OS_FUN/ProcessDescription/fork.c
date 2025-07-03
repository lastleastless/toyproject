#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int counter = 0;
int main(int argc,char * argv[])
{
	pid_t pid;
	int status;
	pid = fork();
	while(counter < 10)
	{
		if(pid>0)
		{
			printf("Hello from parent[%d]! Create child: %d\n",getpid(),pid);
			counter++;
			pid = fork();
		}
		else if(pid == 0)
		{
			printf("I am a child [%d] from [%d]!\n",getpid(),getppid());
			break;
		}
	}
}
	
