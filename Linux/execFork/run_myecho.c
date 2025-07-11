#include <unistd.h>
#include <stdio.h>

int main(int argc,char * argv[])
{
	char* const inarg[] = {"./myecho","hello","from","here!",(char*)0};
	execvp(inarg[0],inarg);
	printf("this line doesn't print\n");
}
