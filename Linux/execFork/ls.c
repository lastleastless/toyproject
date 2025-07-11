#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("executing ls\n");
	execl("/bin/ls","ls","-1",(char*)0);
	perror("execl failed to run.\n");
	exit(1);
}
