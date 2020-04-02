#include<stdio.h>
int main()
{
	int n=3,d,f,i;
	printf("enter the last number=",d);
	scanf("%d",&d);
	while(n<=d)
	{
		f=0;
		i=2;
		while(i<n)
		{
			if(n%i==0)
			{
				f=1;
				break;
			}
			i++;
		}
		if(f==0)
		{	
			printf("%d,",n);
		}
		n++;
	}
	
	return 0;
}
