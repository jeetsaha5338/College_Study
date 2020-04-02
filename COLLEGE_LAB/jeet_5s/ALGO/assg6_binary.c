//binary
#include<stdio.h>
#include<stdlib.h>
int B_search(int*,int,int,int);
int main()
{
	int n,i,k,v,*a;
	printf("Enter Your No. Of Elemnet:");
	scanf("%d",&n);
	a=(int*)malloc(n*(sizeof(int)));
	printf("Enter Your Elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter Your Search Element:");
	scanf("%d",&k);
	B_search(a,0,n-1,k);
	return 0;
}

int B_search(int *a,int lb,int ub,int k)
{
	int mid;
	mid=(lb+ub)/2;
	if(k==a[mid])
	{
		printf("Your Search Found At %d\n",mid+1);
		return 1;
	}
	else if(lb>=ub)
	{
		printf("Your Search Not Found\n");
		return 0;
	}
	else if(k>a[mid])
	{
		 return B_search(a,mid+1,ub,k);
	}
	else if(k<a[mid])
	{
		return B_search(a,lb,mid-1,k);
	}
	
	
}
	
