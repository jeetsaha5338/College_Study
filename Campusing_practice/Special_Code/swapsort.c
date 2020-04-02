#include<stdio.h>
int main()
{
	int a[10]={9,8,7,6,5,4,3,2,1,0};
	int i,k=0,t,f=0,n=10,l=0;
	printf("\nSTART\n");
	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}
	do{
		f=0;
		if(k%2==0)
		{
			for(i=0;i<n-1;i=i+2)
			{
				if(a[i]>a[i+1])
				{
					t=a[i];
					a[i]=a[i+1];
					a[i+1]=t;
					f=1;
				}
			}
			k++;
		}
		else
		{
			for(i=1;i<n-1;i=i+2)
			{
				if(a[i]>a[i+1])
				{
					t=a[i];
					a[i]=a[i+1];
					a[i+1]=t;
					f=1;
				}
			}
			k++;
		}
		l++;
	}while(f==1);
	printf("\nSORT\n");
	printf("\nL:%d\n",l-1);
	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}
	return 0;
}
