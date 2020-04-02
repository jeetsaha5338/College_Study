#include<stdio.h>
int main()
{
	int i,n;
	printf("enter the value=",n);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%7!=0)
		{
			printf("%d,",i);
		}
	}
	return 0;
}
