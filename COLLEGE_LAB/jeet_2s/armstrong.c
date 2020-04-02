#include<stdio.h>
int main()
{
	int i,j=1,n,m,s,d=0,sum=0;
	printf("\n enter a number\n");
	scanf("%d",&n);
	m=n; 
	while(n>0)
	{ 
	  n=n/10;
	  d++;
	}
	n=m;
	while(n>0)
		{
		  s=n%10;
		  n=n/10;
		for(i=1,j=1;i<=d;i++)
			{	
			  j=j*s;
			}
		sum=sum+j;
		}
	if(sum==m)
	printf("\n Armstrong no.");
	else
	printf("\n Not an armstrong no");
	return 0;
}
