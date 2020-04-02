#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
main()
{
	int sockfd,no=0;
	struct sockaddr_in serv_addr;
	int i;
	char buf[100];

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("Unable to create socket\n");
		exit(0);
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("172.16.7.5");
	serv_addr.sin_port = htons(6003);
	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
	{
		printf("Unable to connect local address\n");
		exit(0);
	}
	for(i=0;i<100;i++)
	buf[i]='\0';
	recv(sockfd,buf,100,0);
	printf("%s\n",buf);
	for(i=0;buf[i]!='\0';i++)
	{
	   if(buf[i]=='1')
	   {
	       no++;
	    }
	}
	if(no%2==0)
	{
	   printf("\nRIGHT FOR EVEN, WRONG FOR ODD\n");
	}
	else
	{
	   printf("\nRIGHT FOR ODD, WRONG FOR EVEN\n");
	}
	for(i=0;i<100;i++)
	buf[i]='\0';
	strcpy(buf,"\nCHECKING IS SUCCESSFULL");
	send(sockfd,buf,100,0);

	close(sockfd);
}
