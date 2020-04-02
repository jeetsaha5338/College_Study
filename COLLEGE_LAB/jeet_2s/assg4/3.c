#include<stdio.h>
int main()
{
	int  a[100],i,j,n,t;
	printf("enter the range\n");
	scanf("%d",&n);
	printf("enter the ellememnts\nn");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
			{
				if(a[j]>a[j+1])
				{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				}
			}
		}
		printf("shorted array\n");
		for(i=0;i<n;i++)
		{
		printf("%d",a[i]);
		}
		return 0;
}
































