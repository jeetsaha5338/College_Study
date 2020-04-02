#include<stdio.h>
int main()
{
	int i,n,a[30],k;
	printf("enter no. of element:");
	scanf("%d",&n);
	printf("enter key element:");
	scanf("%d",&k);
	input(a,n);
	output(a,n,k);
	return 0;
}
input(int *p,int n)
{
	int i;
	printf("enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	return p;
}
output(int *p,int n,int k)
{
	int i,f=0;
	for(i=0;i<n;i++)
	{	
		if(p[i]==k)
		{	
			f=1;
			break;
		}
	}
	if(f==1)
	{
		printf("succssful");
	}
	else
	{
		printf("unsuccssful");
	}
}
