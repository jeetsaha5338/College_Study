#include<stdio.h>
int main()
{
	int i,s,j,c;
	for(i=0;i<5;i++)
	{
		for(s=1;s<=5-i;s++)
		{
			printf(" ");
		}
		for(j=0;j<=i;j++)
		{
			if(j==0||i==0)
				c=1;
			else
				c=c*(i-j+1)/j;
			printf("%d ",c);
		}
		printf("\n");
	}
	return 0;
}
			
