#include<stdio.h>
int main()
{
	int i,t1=0,t2=1,t3=0,n;
	printf("\n Enter the range  ");
	scanf("%d",&n);
	//printf("\n Fibonacci series: 0 1");
	for(i=n;i!=0;i--)
	{
 			printf(" %d", t1);	
			t3=t1+t2;
		 	t1=t2;
		 	t2=t3;
		}
	printf("\n");
 return 0;
}
