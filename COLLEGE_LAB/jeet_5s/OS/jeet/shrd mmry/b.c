#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int main(int argc,char *argv[])
{
	int shmid;
	char *x,*y;
	shmid=shmget(123,10*sizeof(char),0777|IPC_CREAT);
	printf("\n%d\n",shmid);
	x=(char*)shmat(shmid,0,0);
	//strcpy(y,argv[1]);
	printf("x=%s\n",x);
	//printf("x=%s\n",y);
	shmdt(x);
	return 0;
}
