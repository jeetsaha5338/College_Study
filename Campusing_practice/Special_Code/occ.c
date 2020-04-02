#include<stdio.h>
int main()
{
	int a[100];
	int l[100][2];
	int i,t,f=0,k,m,n,j;
	printf("Enter The No. of Element:");
	scanf("%d",&n);
	printf("\nEnter The Elements:\n");
	for(i=0;i<n;i++)
	{
		scanf(" %d",&a[i]);
	}
	printf("\nSTART\n");
	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}
	//sorting
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
		{
			if(a[m]>a[j])
			{
				t=a[m];
				a[m]=a[j];
				a[j]=t;
			}
		}
	}
	printf("\nSORTED\n");
	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}
	m=a[0];
	j=0;
	l[j][0]=1;
	for(i=1;i<n;i++)
	{
		if(a[i]==m)
		{
			l[j][0]++;
		}
		else
		{
			l[j][1]=m;
			j++;
			l[j][0]=1;
			m=a[i];
		}
		if(i==n-1)
		{
			l[j][1]=m;
			j++;
		}
	}
	k=j;
	/*printf("\n============\n");
	for(i=0;i<k;i++)
	{
        printf(" %d____%d",l[i][0],l[i][1]);
	}*/

	//sorting
	for(i=0;i<k-1;i++)
	{
		m=i;
		for(j=i+1;j<k;j++)
		{
			if(l[m][0]>l[j][0])
			{
				t=l[m][0];
				l[m][0]=l[j][0];
				l[j][0]=t;
				t=l[m][1];
				l[m][1]=l[j][1];
				l[j][1]=t;
			}
			else if((l[m][0]==l[j][0])&&(l[m][1]>l[j][1]))
			{
				t=l[m][0];
				l[m][0]=l[j][0];
				l[j][0]=t;
				t=l[m][1];
				l[m][1]=l[j][1];
				l[j][1]=t;
			}
		}
	}
	/*printf("\n============\n");
	for(i=0;i<k;i++)
	{
        printf(" %d____%d",l[i][0],l[i][1]);
	}
	printf("\n============\n");*/
	printf("\nRESULT:\n");
	for(i=k-1;i>=0;i--)
	{
        printf(" %d",l[i][1]);
	}
	return 0;
}


