#include<stdio.h>
int main()
{
	int i=1,n,r=0,s =0,d ;
	printf("enter the number n");
	scanf("%d",&n);
	while(n>0)
		{
			r=n%10;
			n=n/10;
			s=s+r*i;
			i=i*2;
		}
		printf("result=%d",s);
return 0;
}
	
