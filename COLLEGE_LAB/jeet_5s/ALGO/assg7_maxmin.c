//maxmin
#include<stdio.h>
#include<stdlib.h>
void MM_search(int,int);
int *a,max,min;
int main()
{
	int n,i;
	printf("Enter Your No. Of Elemnet:");
	scanf("%d",&n);
	a=(int*)malloc(n*(sizeof(int)));
	printf("Enter Your Elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	MM_search(0,n-1);
	printf("\nMax Value:%d\nMin Value:%d\n",max,min);
	return 0;
}

void MM_search(int i,int j)
{
	int max1,min1,mid;
	if(i==j)
	{
		max=min=a[i];
	}
	else if(i==j-1)
	{
		if(a[i]>a[j])
		{
			max=a[i];
			min=a[j];
		}
		else
		{
			max=a[j];
			min=a[i];
		}
	}
	else
	{
		mid=(i+j)/2;
		MM_search(i,mid);
		max1=max;
		min1=min;
		MM_search(mid+1,j);
		if(max<max1)
		{
			max=max1;
		}
		if(min>min1)
		{
			min=min1;
		}
	}
}
	
