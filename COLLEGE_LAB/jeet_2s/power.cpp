#include<stdio.h>
int main()
{
		int n,r,i,sum,a=1;
		printf("enter the value=",n);
		scanf("%d",&n);
		while(n>0)
		{
				r=n%10;
				n=n/10;
				sum=1;
				for(i=1;i<=a;i++)
				{
						sum=sum*r;
				}
				a=sum;
		}
		printf("%d",a);
		return 0;
}
