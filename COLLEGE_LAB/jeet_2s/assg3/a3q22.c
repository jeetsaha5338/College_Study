#include<stdio.h>
int main()
{
	int i,k,n,j,s,v=64,o=70;
	printf("no.=",n);
	scanf("%d",&n);
	for(k=1;k<=n;k++)
	{
		printf("%c",k+v);
	}
	for(k=n-1;k>=1;k--)
	{
		printf("%c",k+v);
	}
	printf("\n");
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf("%c",v+j);
		}
		for(s=1;s<=(2*i)-1;s++)
		{
			printf(" ");
		}
		for(j=n-i;j>=1;j--)
		{
			printf("%c",v+j);
		}
		printf("\n");
	}
	return 0;
}
