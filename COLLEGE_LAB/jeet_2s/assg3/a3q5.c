#include<stdio.h>
int main()
{
	int n,m,d=0,r,f,i,sum=0;
	printf("the number=",n);
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
		r=n%10;
		n=n/10;
		f=1;
		for(i=1;i<=d;i++)
		{
			f=f*r;
			sum=sum+f;
		}
	}
	if(sum==n)
	{
		printf("amstrong");
	}
	else
	{
		printf("not amstrong");
	}
	return 0;
}
