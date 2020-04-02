#include<stdio.h>
int main()
{
	int n,c=0,k,a[20],i=1,ch,j;
	printf("Enter your number:\n");
	scanf("%d",&n);
	printf("Even/Odd?\n");
	scanf("%d",&ch);
	while(n>0)
	{
		a[i]=n%2;
		n=n/2;
		c=c+a[i];
		i++;
	}
	i--;
	if(ch==0)
	{	
		if(c%2==0){	a[0]=0;}
		else{	a[0]=1;}
	}
	else
	{	
		if(c%2==0){	a[0]=1;}
		else{	a[0]=0;}
	}
	printf("binary=");
	j=i;
	while(i>=1)
	{
		printf("%d",a[i]);
		i--;
	}
	printf("\nsending code=");
	while(j>=0)
	{
		printf("%d",a[j]);
		j--;
	}
	printf("\n%d\n",c);
	return 0;
}
		
