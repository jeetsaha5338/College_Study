#include<stdio.h>
int main()
{	 
	int i,f=1,n;
	printf("\n Enter the number\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{ f=f*i;
	}

	printf("\n Factorial=%d\n",f);
	return 0;
}
