#include<stdio.h>

int max(int *a,int n)
{
	int m,i;
	m=a[0];
	for(i=1;i<n;i++)
	{
		if(m<a[i])
		{
			m=a[i];
		}
	}
	
//	printf("\n%d\n",m);
	return m;
}

int main()
{
	int n,i,m1,m2,total=0;
	int a[20],b[20];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	
	m1=max(a,n);
	m2=max(b,n);
	total=m1+m2;
	printf("%d",total);	
	return 0;
}
