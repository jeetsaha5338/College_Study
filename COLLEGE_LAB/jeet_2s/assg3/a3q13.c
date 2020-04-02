#include<stdio.h>
int main()
{
	int s=0,n,m,r;
	printf("enter the value=",n);
	scanf("%d",&n);
	m=n;
	while(n>0)
	{
		r=n%10;
		n=n/10;
		s=r+(10*s);
	}
	printf("the reverse value=%d",s);
	return 0;
}
