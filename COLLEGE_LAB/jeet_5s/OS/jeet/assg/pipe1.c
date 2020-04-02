#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int fd[2];
	char* s="abcd";
	int x,i=pipe(fd);
	if(i==0)
	{
		x=fork();
		if(x==0)
		{
			close(fd[1]);
			printf("IN CHILD\n");
			read(fd[0],s,5);
			printf("\n%s",s);
		}
		else
		{
			close(fd[0]);
			printf("IN PARENTS\n");
			write(fd[1],s,5);
		}
	}
	return 0;
}	
