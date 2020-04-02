//insertion sort
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n,j,t,k;
	int *a;
	printf("ENTER THE NO. OF NUMBERS:");
	scanf("%d",&n);
	printf("ENTER THE DATA:");
	a= (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		k=a[i];
		for(j=i-1;j>=0;j--)
		{
			if(k<a[j])
			{
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
			else
				j=-1;//go to outer for loop
		}
		//a[j+1]=k;
	}
	/*for(j=1;j<n;j++)
	{
		i=j-1;
		k=a[j];
		while((i>=0) && (k<a[i]))
		{
			a[i+1]=a[i];
			i=i-1;
		}
		a[i+1]=k;
	}*/
	for(i=0;i<n;i++)
	{
		printf("\n%d\n",a[i]);
	}
	return 0;
}
