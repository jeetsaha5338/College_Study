#include<stdio.h>
void swap(int *p,int *q)
{
	int t=*p;
	*p=*q;
	*q=t;
}
void rev(int *a,int l,int n)
{
	int i;
	for(i=l;i<(l+n)/2;i++)
	{
		swap(&a[i],&a[n-1+l-i]);
	}
}
	
void s_ace(int *a,int l,int n)
{
	int i,j;
	for(i=l;i<n;i++)
	{
		for(j=l;j<n-i-1+l;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
			}
		}
	}
	return;
}

				
int main()
{
	int a[10],i,j,n;
	printf("Enter N:");
	scanf("%d",&n);
	printf("Enter the array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}
	printf("\n");
	s_ace(a,0,n);
	j=n/2;
	rev(a,j,n);
	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}
	printf("\n");
	return 0;
}
