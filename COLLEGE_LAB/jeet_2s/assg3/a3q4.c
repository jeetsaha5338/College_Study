#include<stdio.h>
int main()
{
	int i=2,n,m=1;
	printf("enter the number=",n);
	scanf("%d",&n);
	while(i<n)
	{
		if(n%i==0)
		{
			m=m+i;
		}
		i++;
	}
	if(m==n)
	{
		printf("the number is perfect");
	}
	else
	{
		printf("the number is not perfect");
	}
	return 0;
}
