#include<stdio.h>
int main()
{
	int i,n;
	printf("\n Enter the range  ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		{ 
			if(!(i%7==0)&&printf("%d  ",i));
	
				
		}
	printf("\n");
	
	return 0;
}
