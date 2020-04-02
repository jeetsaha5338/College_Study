#include<stdio.h>
int main()
{
	int n,d=0,s=0,p=1;
	printf("enter the number");
	scanf("%d",&n);
	while(n!=0)
	{
		d=n%2;
		n=n/2;
		s=s+d*p;
		p=p*10;
		}
		printf("%d",s);
		return 0;
		}
		
		
