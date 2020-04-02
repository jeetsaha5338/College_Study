#include<stdio.h>
int main()
{
	int i,sum=0,n;
	printf("enter the number=",n);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum=sum+i;
	}
	printf("the sum=%d",sum);
	return 0;
}

