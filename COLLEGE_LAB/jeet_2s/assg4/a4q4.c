#include<stdio.h>
int main()
{
	int i,n,t,f,a[60];
	printf("enter no of elements=");
	scanf("%d",&n);
	printf("enter the elements=",a[i]);
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	for(f=0;f<n-1;f++)
	{
		for(i=0;i<n-f-1;i++)
		{
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}

	}
	printf("after reverse:");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
