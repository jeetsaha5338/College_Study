#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
void main()
{
	int sockfd,client,i;
	struct sockaddr_in cli_addr,serv_addr;
	char buff1[100],buff2[100];
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0){
		printf("can not create socket");
		exit(0);
	}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(9005);
int bb =bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
if(bb<0){
		printf("can not bind local host");
		exit(0);
	}
	do
	{
		client=sizeof(cli_addr);
		for(i=0;i<100;i++)
			buff1[i]='\0';
		recvfrom(sockfd,buff1,100,0,(struct sockaddr*)&cli_addr,&client);
		//printf("\n aftr recv\n");
		printf("%s\n",buff1);
		for(i=0;i<100;i++)
			buff2[i]='\0';
		scanf("%s",buff2);
		sendto(sockfd,buff2,100,0,(struct sockaddr*)&cli_addr,client);
	}while(strcmp(buff1,"bye"));
	close(sockfd);
}
