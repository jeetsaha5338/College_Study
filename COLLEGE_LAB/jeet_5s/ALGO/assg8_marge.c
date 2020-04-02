//marge sort
#include<stdio.h>
#include<stdlib.h>
int *a,*b;
void merge(int,int,int);
void merge_sort(int,int);
int main()
{
	int i,j,n,t,k;
	printf("enter the value of n\n");
	scanf("%d",&n);
	printf("enter the elements of an array\n");
	a= (int*)malloc(n*sizeof(int));	
	b= (int*)malloc(n*sizeof(int));	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	merge_sort(0,n-1);
	printf("sorted array:");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	printf("\n");
	return 0;
}

void merge_sort(int lb, int ub)
{
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		merge_sort(lb,mid);
		merge_sort(mid+1,ub);
		merge(lb,mid,ub);
	}
}

void merge(int lb,int mid,int ub)
{
	int i,j,h,k;
	i=lb;
	h=lb;
	j=mid+1;
	while((h<=mid)&&(j<=ub))
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h=h+1;
		}
		else
		{
			b[i]=a[j];
			j=j+1;
		}
		i=i+1;
	}
	if(h>mid)
	{
		for(k=j;k<=ub;k++)
		{
			b[i]=a[k];
			i=i+1;
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			b[i]=a[k];
			i=i+1;
		}
	}
	for(k=lb;k<=ub;k++)
	{
		a[k]=b[k];
	}
}		
