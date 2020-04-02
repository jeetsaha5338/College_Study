#include<stdio.h>
#include<math.h>
int amsrg(int n)
{
	int d=0,sum=0,m,s,r;
	m=n;
	while(n>0)
	{
		r=n%10;
		n=n/10;
		d++;
	}
	n=m;
	while(n>0)
	{
		r=n%10;
		n=n/10;
		s=pow(r,d);
		sum=sum+s;
	}
	return sum;
}
int main()
{
	int N;
	printf("the value of N:");
	scanf("%d",&N);
	if(N==amsrg(N))
	{
		printf("amstrong");
	}
	else
	{
		printf("not");
	}
	return 0;
}
