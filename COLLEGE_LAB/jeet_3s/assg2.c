#include<stdio.h>
int main()
{
	int n,i,j,p;
	int a[10];
	printf("enter the no. of elements:",n);
	scanf("%d",&n);
	printf("enter the elements of the array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the position:",p);
	scanf("%d",&p);
	if(p>n-1)
	{
		printf("not posible");
	}
	else
	{
		for(j=p;j<n-1;j++)
		{
			a[j]=a[j+1];
		}
		printf("the new array is:");
		for(i=0;i<n-1;i++)
		{
			printf("%d ",a[i]);
		}
	}
	return 0;
}

