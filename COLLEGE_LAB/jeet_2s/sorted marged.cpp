#include<stdio.h>
int main()
{	int n1,n2;
	int i=0,j=0,k=0;
	int a[30],b[30],c[30];
	printf("enter the no of element of two array:");
	scanf("%d%d",&n1,&n2);
	printf("enter the elements of 1st aaray:");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the element of 2nd array:");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&b[i]);
	}
	i=0;
	while((i<n1)&&(j<n2))
	{
		if(a[i]>b[j])
		{
			c[k]=b[j];
			j++;
		}
		else if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;
		}
		k++;
	}
	while((i<n1)||(j<n2))
	{
		if(i<n1)
		{
			c[k]=a[i];
			i++;
		}
		else if(j<n2)
		{
			c[k]=b[j];
			j++;
		}
		k++;
	}
	printf("the marged array is:\n");
	for(i=0;i<k;i++)
	{
		printf("%5d\t",c[i]);
	}
	return 0;
}
