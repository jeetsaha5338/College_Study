#include<stdio.h>
int main()
{
	int n,i,j,ne,p;
	int a[10];
	printf("enter the no. of elements:",n);
	scanf("%d",&n);
	printf("enter the elements of the array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the position and the new element:",p,ne);
	scanf("%d%d",&p,&ne);
	if((p>n-1)||(n==10))
	{
		printf("not posible");
	}
	else
	{
		for(j=n-1;j>=p;j--)
		{
			a[j+1]=a[j];
		}
		a[p]=ne;
		printf("the new array is:");
		for(i=0;i<=n;i++)
		{
			printf("%d\n",a[i]);
		}
	}
	return 0;
}
		
