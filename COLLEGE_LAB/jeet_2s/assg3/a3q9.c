#include<stdio.h>
int main()
{
	int n,i,f=1;
	printf("enter the number=",n);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		f=f*i;
	}
	printf("the FAC value=%d",f);
	return 0;
}
