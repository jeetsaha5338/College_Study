#include<stdio.h>
int main()
{
	float i,n,term;
	float sum=0;
	printf("enter the value of n=",n);
	scanf("%f",&n);
	for(i=1;i<=n;i++)
	{	
		term=1/i;
		sum=(sum+term);
	}
	printf("sum of series=%f",sum);
	return 0;
}
