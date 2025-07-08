#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
char buffer[1024];
int main(int argc,char* argv[])
{
	int fd;
	ssize_t nread;
	char buf[1024];
	char* path = argv[1];
	int size = strlen(path);
	if(path[size-1] !='t'|| path[size-2]!='x'|| path[size-3]!='t'||path[size-4]!='.')
	{
		printf("only takes input as .txt file.\n");
		exit(-3);
	}
	if(argc != 2)
	{
		printf("argument number is not matched. expected 2.\n");
		exit(-1);
	}
	for(int i = 0; i < sizeof(buffer)/sizeof(buffer[0]);i++)
	{
		int random = rand() % 10;
		buffer[i] = 'a' + random;
	}
	fd = open(path,O_WRONLY|O_CREAT|O_EXCL,0644);
	ssize_t wr = write(fd,buffer,1000);
	if(wr==-1)
	{
		printf("write is failed.\n");
		exit(-2);
	}
	else
	{
		printf("byte writing success!\n");
	}
	nread = read(fd,buf,1024);
	close(fd);

}

