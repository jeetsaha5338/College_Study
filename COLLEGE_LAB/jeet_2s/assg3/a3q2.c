#include<stdio.h>
int main()
{
	int i=2,n,f=0;
	printf("enter the number=",n);
	scanf("%d",&n);
	while(i<n)
	{
		if(n%i==0)
		{
			f=1;
			break;
		}
		i++;
	}
	if(f==0)
	{
		printf("the number is prime");
	}
	else
	{
		printf("the number is not prime");
	}
	return 0;
}
