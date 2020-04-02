#include<stdio.h>
int main()
{
	int n,i,s=0,sum=0;
	printf("\n Enter the no.  ");
	scanf("%d",&n);
	while(n>0)
	{ s=n%10;
	  n=n/10;
	  sum=sum+s;
	}
	printf("\n Sum= %d\n",sum);
	return 0;
}
