#include<stdio.h>
int main()
{
	int i,n,a[30];
	float avg;
	printf("enter no. of element:");
	scanf("%d",&n);
	input(a,n);
	avg=avarage(a,n);
	printf("the avarage value is=%f",avg); 
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
avarage(int *p,int n)
{
	int i;
	float avg=0;
	for(i=0;i<n;i++)
	{
		avg=avg+p[i];
	}
	avg=avg/n;
	return avg;
}
	

