include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
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
void crc()
{
   int dn,pn,ndn;
   int a[10],a1[10];
   int b[10];
   int c[10],d[10],i,j;
   printf("Enter For data size & poly size\n");
   scanf("%d%d",&dn,&pn);
   printf("Enter poly:\n");
   for(i=0;i<pn;i++)
   {
      scanf("%d",&b[i]);
   }
   printf("Enter data:\n");
   ndn=dn+pn-1;
   for(i=0;i<ndn;i++)
   {
      if(i<dn)
      {
         scanf("%d",&a[i]);
      }
      else
      {
         a[i]=0;
      }
   }
   for(i=0;i<ndn;i++)
   {
      a1[i]=a[i];
   }
   printf("\n");
      
   for(i=0;i<ndn-pn+1;i++)
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
   
   for(i=0;i<pn;i++)
   {
       a[i]=a1[i];
   }
   for(i=0;i<ndn;i++)
   {
      if(a[i]==0)
      {
         st[i]='0';
      }
      else
      {
         st[i]='1';
      }
   }
   printf("\n\nSending String:%s\n",st);
   printf("\n");
   return;
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
		{
		   buf[i]='\0';
		   st[i]='\0';
		}
		crc();
		//strcpy(buf,"Message from server");
		strcpy(buf,st);
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


