#include<stdio.h>
int main()
{
	int n,i,j,v;
	int a[10];
	printf("enter the no. of elements:",n);
	scanf("%d",&n);
	printf("enter the elements of the array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the value:",v);
	scanf("%d",&v);
	for(i=0;i<n;i++)
	{
		if(v==a[i])
		{
			printf("the element present in position:%d\n",i);
		}
	}
	return 0;
}
