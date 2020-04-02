#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
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
void send_code()
{
    int data[20];
    int r,i,d,j,k,n,s,f,m;
    printf("\nEnter Data Size:");
    scanf("%d",&d);
    int a[10];//={1,0,1,1};
    printf("\nEnter Data Elements:");
    for(i=0;i<d;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<20;i++)
    {
        data[i]=0;
    }
    r=0;
    do{
        r++;
    }while(power(2,r)<(d+r+1));
    n=d+r;
    j=d-1;
    k=0;
    for(i=0;i<n;i++)
    {
        if(i==(power(2,k)-1))
        {
            data[i]=2;
            k++;
        }
        else
        {
            data[i]=a[j];
            j--;
        }
    }
    /*printf("\nINIT_ARRY:\n");
    for(i=0;i<n;i++)
    {
        printf(" %d",data[i]);
    }*/
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
        m=s%2;
        data[f-1]=m;
    }
    printf("\nDATA:\n");
    for(i=0;i<n;i++)
    {
        if(data[i]==1)
            buff[i]='1';
        else
            buff[i]='0';
        printf(" %d",data[i]);
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
		{
		   buf[i]='\0';
		   buff[i]='\0';
		}
      send_code();
		//strcpy(buf,"Message from server");
		strcpy(buf,buff);
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


