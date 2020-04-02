#include<stdio.h>
int main()
{
	int i,j,m,n,k;
	int a[10],b[10],c[20];
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
	if(m>n)
	{
		for(i=0,j=0;i<m;i++,j=j+2)
		{
			if(a[i]>b[i])
			{
				c[i]=b[i];
				c[i+1]=a[i];
			}
			else
			{
				c[i]=a[i];
				c[i+1]=b[i];
			}
		}
		for(i=m,j=2*m;i<n;i++,j++)
		{
			c[j]=b[i];
		}
	}
	else
	{
		for(i=0,j=0;i<n;i++,j=j+2)
		{
			if(a[i]>b[i])
			{
				c[j]=b[i];
				c[j+1]=a[i];
			}
			else
			{
				c[j]=a[i];
				c[j+1]=b[i];
			}
		}
		for(i=n,j=2*n;i<m;i++,j++)
		{
			c[j]=a[i];
		}
	}
	printf("the elements of the  new array:");
	for(i=0;i<n+m;i++)
	{
		printf("%d",c[i]);
	}
	return 0;
}
