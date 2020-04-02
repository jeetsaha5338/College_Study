#include<stdio.h>
int main( )
{
	int i,key,n,a[30];
	printf("enter the no. of element:");
	scanf("%d",&n);
	printf("enter the element:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the value of key:");
	scanf("%d",&key);
	binary_search(a,n,key);
	return 0;
}
binary_search(int p[],int n,int key)
{
	int lb=0;
	int ub=n-1;
	int mid,i;	
	while(lb<=ub)
	{
		
		for(i=lb;i<=ub;i++)
		{
			printf("%d\t",p[i]);
		}
		printf("\n");
		mid=(lb+ub)/2;
		if(p[mid]==key)
		{
			printf("searching is successful\n");
			break;
		}
		else if(p[mid]>key)
		{
			ub=mid-1;
		}
		else
		{	
			lb=mid+1;
		}
	}
	if(lb>ub)
	{
		printf("searching is unsuccessful\n");
	}
}
