#include<stdio.h>
int fact(int x)
{
	int i,f=1;
	for(i=1;i<=x;i++)
	{
		f=f*i;
	}
	return f;
}
int main()
{
	int n,r,result;
	printf("the value of n&r:");
	scanf("%d%d",&n,&r);
	result=fact(n)/(fact(r)*fact(n-r));
	printf("the result=%d",result);
	return 0;
}
