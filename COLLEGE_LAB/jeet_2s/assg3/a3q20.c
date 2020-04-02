#include<stdio.h>
int main()
{
	int i,n,r,s=0,k=0;
	printf("Enter the desimal value:",n);
	scanf("%d",&n);
	while(n>1)
	{
		r=n%2;
		s=(10*s)+r;
		n=n/2;
		if(n==1)
		s=(10*s)+n;
	}
	while(s>0)
	{
		r=s%10;
		s=s/10;
		k=(10*k)+r;
	}
	printf("the binary value=%d",k);
	return 0;
}
