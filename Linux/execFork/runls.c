#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int fatal(char *s)
{
	perror(s);
	exit(1);
}
int main()
{
	pid_t pid;
	switch(fork())
	{
		case -1:
			fatal("fork failed\n");
			break;
		case 0:
			execl("/bin/ls","ls","-1",(char*)0);
			fatal("execcl failed");
		case 1:
			wait((int*)0);
			printf("is completed!.\n");
			exit(0);
	}
}

