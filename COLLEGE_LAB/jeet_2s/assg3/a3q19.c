#include<stdio.h>
int main()
{
	int n,d,r,D=0,a,c=0;
	printf("enter the binary value=",n);
	scanf("%d",&n);
	while(n>0)
	{
		r=n%10;
		n=n/10;
		c++;
		for(a=1;a<c;a++)
		{
			r=r*2;
		}
		D=D+r;
		
	}
	printf("%d",D);
	return 0;
}
