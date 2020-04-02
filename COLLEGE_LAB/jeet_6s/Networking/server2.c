#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
char b[10];
	
void fun()
{
   
	int n1,n,sum=0,c,k,a[20],a1[20],x1[10],x2[10],x[10],i=1,ch,j;
	for(j=0;j<20;j++)
   {
      b[j]='\0';
   }

	printf("Enter your number of bit:\n");
	scanf("%d",&n);
	printf("Enter your numbers:\n");
	for(i=0;i<n;i++)
	{
	   scanf("%d",a[i]);
	   sum=sum+a[i];
	}
	i=0
	printf("\nsum=%d\n",sum);
	while(sum>0)
	{
		a[i]=sum%2;
		sum=sum/2;
		c=c+a1[i];
		i++;
	}
	n1=i-1;
	for(i=0;i<n1/2;i++)
	{
	   c=a1[i];
	   a1[i]=a1[n1-i-1];
	   a1[n1-i-1]=c;
	}
	printf("BINARY CODE OF THE SUM:");
	for(i=0;i<n1;i++))
	{
		printf("%d",a1[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
	   x1[i]=a1[n1-n+i];
	}
	for(i=0;i<n;i++)
	{
	   x2[i]=0;
	}
	for(i=0;i<n1-n;i++)
	{
	   x2[n-i]=a1[n1-n-1-i];
	}
	c=0;
	for(i=n-1;i>=0;i--)
	{
	   k=x1[i]+x2[i]+c;
	   if(k==3)
	   {
	      x[i]=1;
	      c=1;
	   }
	   else if(k==2)
	   {
	      x[i]=0;
	      c=1;
	   }
	   else
	   {
	      x[i]=k;
	      c=0;
	   }
	 }  
	for
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


