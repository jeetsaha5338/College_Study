#include<stdio.h>
int main()
{
	float i,n,term,x;
	float sum=0;
	printf("enter the value of x=",x);
	scanf("%f",&x);
	printf("enter the value of n=",n);
	scanf("%f",&n);
	term=x;
	for(i=1;i<(2*n);i=i+2)
	{
		sum=sum+term;
		term=(term*(x*x)*(-1))/((i+1)*(i+2));
	}
	printf("sum of series=%f",sum);
	return 0;
}
	
