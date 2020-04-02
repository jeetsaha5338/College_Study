#include<stdio.h>
int main()
{
	int i,n,p=0,f=0;
	int a[30];
	printf("the number of elements:",n);
	scanf("%d",&n);
	printf("enter the numbers:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>=0)
		{
			p=p+a[i];
		}
		else
		{
			f=f+a[i];
		}
	}
	printf("the sum of positive number=%d",p);
	printf("the sum of negetive number=%d",f);
	return 0;
}
