#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
void main()
{
	int sockfd,i;
	struct sockaddr_in serv_addr;
	char buff1[100],buff2[100];
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0){
		printf("can not create socket");
		exit(0);
	}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
serv_addr.sin_port=htons(9005);
do{
	
	int serv=sizeof(serv_addr);
for(i=0;i<100;i++)buff1[i]='\0';
	scanf("%s",buff1);
	sendto(sockfd,buff1,100,0,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	for(i=0;i<100;i++)
			buff2[i]='\0';
	recvfrom(sockfd,buff2,100,0,(struct sockaddr*)&serv_addr,&serv);
	//printf("\n aftr recv\n");
	printf("%s\n",buff2);
}while(strcmp(buff2,"bye"));
close(sockfd);
}

