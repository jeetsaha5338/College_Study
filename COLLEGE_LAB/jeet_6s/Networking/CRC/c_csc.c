#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
char st[100];
int xor(int m,int n)
{
   if(m==n)
   {
      return 0;
   }
   return 1;
}
int check()
{
   int b[4]={1,1,0,1},s,i,a[10],pn=4,c1=0,c[10],d[10],j;
   for(s=0;st[s]!='\0';s++);
   for(i=0;i<s;i++)
   {
      if(st[i]=='0')
      {
         a[i]=0;
      }
      else
      {
         a[i]=1;
      }
   }
   for(i=0;i<s-pn+1;i++)
   {
      if(a[i]==0)
      {
         c[i]=0;
         d[0]=c[i]*b[0];
         d[1]=c[i]*b[1];
         d[2]=c[i]*b[2];
         d[3]=c[i]*b[3];
      }
      else
      {
         c[i]=1;
         d[0]=c[i]*b[0];
         d[1]=c[i]*b[1];
         d[2]=c[i]*b[2];
         d[3]=c[i]*b[3];
      }
      for(j=0;j<pn;j++)
      {
         a[i+j]=xor(a[i+j],d[j]);
      }
   }
   printf("\nRemainder Array:\n");
   for(i=0;i<s;i++)
   {
      if(a[i]!=0)
      {
         c1++;
      }
      printf("%d",a[i]);
   }
   return 0;
}
main()
{
	int sockfd,no=0,ch;
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
	printf("Recevied String:%s\n",buf);
	for(i=0;i<100;i++)
   {
    st[i]='\0';
   }
	strcpy(st,buf);
	ch=check();
	if(ch==0)
	{
	   printf("\nRIGHT\n");
	}
	else
	{
	   printf("\nWRONG\n");
	}
	for(i=0;i<100;i++)
	buf[i]='\0';
	strcpy(buf,"\nCHECKING IS SUCCESSFULL");
	send(sockfd,buf,100,0);

	close(sockfd);
}
