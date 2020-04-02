#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int main(int argc,char *argv[])
{
	int shmid;
	char *data;
	shmid=shmget(123,10*sizeof(char),0000|IPC_CREAT);
	printf("\n%d\n",shmid);
	data=(char*)shmat(shmid,0,0);
	strcpy(data,argv[1]);
	printf("data=%s\n",data);
	shmdt(data);
	return 0;
}
