#include<stdio.h>
int main()
{
	int i,n,a[30];
	printf("enter no. of element:");
	scanf("%d",&n);
	input(a,n);
	maximum(a,n);
	minimum(a,n);
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
maximum(int *p,int n)
{
	int i,max;
	max=p[0];
	for(i=1;i<n;i++)
	{	
		if(p[i]>max)
		{	
			max=p[i];
		}
	}
	printf("the maximum value is:%d\n",max);
}
minimum(int *p,int n)
{
	int i,min;
	min=p[0];
	for(i=1;i<n;i++)
	{	
		if(p[i]<min)
		{	
			min=p[i];
		}
	}
	printf("the minimum value is:%d\n",min);
}
