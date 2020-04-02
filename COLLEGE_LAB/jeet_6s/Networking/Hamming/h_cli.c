#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
char buff[100];
int power(int m,int m1)
{
    int i,f=1;
    for(i=1;i<=m1;i++)
    {
        f=f*m;
    }
    return f;
}
int recv_code()
{
    int data[20];
    int r,i,j,k,n,s,f,m,l;
    for(i=0;buff[i]!='\0';i++)
    {
        if(buff[i]=='0')
            data[i]=0;
        else
            data[i]=1;
    }
    n=i;
    /*printf("\nGET_ARRY:\n");
    for(i=0;i<n;i++)
    {
        printf(" %d",data[i]);
    }*/
    r=0;
    do{
        r++;
    }while(power(2,r)<(n+1));
    m=0;
    l=0;
    for(i=1;i<=r;i++)
    {
        k=power(2,i-1);
        f=k;
        s=0;
        j=0;
        while(k<=n)
        {
            m=k+(j%f)-1;
            s=s+data[m];
            j++;
            if(j%f==0)
            {
                k=k+2*f;
            }
        }
        l=l+(s%2);
    }
     return l;   
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
    buff[i]='\0';
   }
	strcpy(buff,buf);
   ch=recv_code();
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
