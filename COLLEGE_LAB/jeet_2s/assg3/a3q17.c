#include<stdio.h>
int main()
{
		int f,k,i;
	for(i=1;i<=5;i++)
	{
		k=((2*i)-1);
		for(f=1;f<=(5-i);f++)
		{
			printf(" ");
		}
		for(f=i;f<k;f++)
		{
			printf("%d",f);
		}
		for(f=k;f>=i;f--)
		{
			printf("%d",f);
		}
		printf("\n");
	}
	return 0;
}
