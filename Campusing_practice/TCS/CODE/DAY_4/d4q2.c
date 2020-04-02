#include<stdio.h>
int fact(int n)
{
	int f=1,i;
	for(i=1;i<=n;i++)
	{
		f*=i;
	}
	return f;
}
int ncr(int n,int r)
{
	int result,a,b,c;
	a=fact(n);
	b=fact(r);
	c=fact(n-r);
	result=a/(b*c);
	return result;
}
int main()
{
	int i,j,n,k;
	printf("Enter N:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		k=0;
		for(j=0;j<n;j++)
		{
			if(i+j>n-2)
			{
				printf("%3d",ncr(i,k++));
			}
			printf("   ");

		}
		printf("\n");
	}
	return 0;
}

