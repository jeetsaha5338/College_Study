#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>


	
int main()
{
	int sockfd,new;
	int clilen;
   char sms[100];
	struct sockaddr_in cli_addr,serv_addr;
	int i;
	char buf[100];

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0){
		printf("Cannot create socket\n");
		exit(0);
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(6003);
	int bb=bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	if(bb<0){
		printf("Unable to bind local address\n");
		exit(0);
	}
	listen(sockfd,5);
	while(1)
	{
		clilen=sizeof(cli_addr);
		new=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
		if(new<0)
		{
			printf("Accept error\n");
			exit(0);
		}
		for(i=0;i<100;i++)
		{
		   buf[i]='\0';
		   sms[i]='\0';
		}
		while(strcmp(sms,"bye")!=0)
		{
	      printf("Enter Your Message:");
	      scanf("%s",sms);
	      //strcpy(buf,"Message from server");
		   strcpy(buf,sms);
		   send(new,buf,100,0);
		   for(i=0;i<100;i++)
		   buf[i]='\0';
		   recv(new,buf,100,0);
		   printf("\n%s\n",buf);
		   strcpy(buf,sms);
		}
		printf("\nCONVERSATION END\n");
		close(new);
	}
	return 0;
}


