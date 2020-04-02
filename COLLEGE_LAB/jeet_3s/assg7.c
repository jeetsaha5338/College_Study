#include<stdio.h>
int main()
{
	int lb=0,mid,n,a[30],k;
	printf("enter no. of element:");
	scanf("%d",&n);
	printf("enter key element:");
	scanf("%d",&k);
	input(a,n);
	output(a,n,k);
	return 0;
}
input(int *p,int n)
{
	int i;
	printf("enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	return p;
}
output(int *p,int n,int k)
{
	int mid;
	int lb=0;
	int ub=n-1;
	while(lb<=ub)
	{
		mid=(lb+ub)/2;
		if(p[mid]==k)
		{
			printf("succssful");
			break;
		}
		else if(p[mid]>k)
		{
			ub=mid-1;
		}
		else if(p[mid]<k)
		{
			lb=mid+1;
		}
	}
	if(lb>ub)
	{
		printf("unsuccssful");
	}
}
		
		
