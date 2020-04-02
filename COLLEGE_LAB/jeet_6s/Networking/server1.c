#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
char b[10];
	
void fun()
{
   
	int n,c=0,k,a[20],i=1,ch,j;
	for(j=0;j<20;j++)
   {
      b[j]='\0';
   }

	printf("Enter your number:\n");
	scanf("%d",&n);
	printf("Even/Odd?\n");
	scanf("%d",&ch);
	while(n>0)
	{
		a[i]=n%2;
		n=n/2;
		c=c+a[i];
		i++;
	}
	//printf("%d\n",i);
	i--;
	k=i;
	printf("BINARY CODE:\n");
	while(i>=1)
	{
		printf("%d",a[i]);
		i--;
	}
	
	if(ch==0)
	{	
		if(c%2==0){	a[0]=0;}
		else{	a[0]=1;}
	}
	else
	{	
		if(c%2==0){	a[0]=1;}
		else{	a[0]=0;}
	}
	
	
	
//   printf("\nc=");
   i=k;
	while(i>=0)
	{
		//printf("%d",a[i]);
		if(a[i]==0)
		{
		   b[i]='0';
		}
		else
		{
		     b[i]='1';
		}
		i--;
	}
	
}
int main()
{
	int sockfd,new;
	int clilen;
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
		buf[i]='\0';
		fun();
		//strcpy(buf,"Message from server");
		strcpy(buf,b);
		send(new,buf,100,0);
		for(i=0;i<100;i++)
		buf[i]='\0';
		recv(new,buf,100,0);
		printf("%s\n",buf);
		printf("\nPERFECTLY RECIVE FROM CLIENT\n");
		close(new);
	}
	return 0;
}


