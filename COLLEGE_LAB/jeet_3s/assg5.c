#include<stdio.h>
int main()
{
	int n,i,j,m;
	int a[10],b[10];
	printf("enter the no. of elements of two array:",n,m);
	scanf("%d%d",&n,&m);
	printf("enter the elements of the array1:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the elements of the array2:");
	for(i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<m;i++)
	{
		a[n+i]=b[i];
	}
	printf("the elements of the  new array:");
	for(i=0;i<n+m;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
