#include<stdio.h>
int gcd(int x,int y)
{
	int z;
	while(x%y!=0)
	{
		z=x%y;
		x=y;
		y=z;
	}
	return z;
}
int main()
{
	int a,b,c,k,result;
	printf("the value of a,b&c:");
	scanf("%d%d%d",&a,&b,&c);
	k=gcd(a,b);
	result=gcd(k,c);
	printf("the result=%d",result);
	return 0;
}
