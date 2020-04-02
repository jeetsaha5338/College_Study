#include<stdio.h>
#include<stdlib.h>
int power(int a,int b)
{
	int i,p=1;
	for(i=0;i<b;i++)
	{
		p*=a;
	}
	return p;
}
int chng_D2O(int n,int b)
{
	int a[100],i,k=0,r=0;
	while(n>0)
	{
		a[k++]=n%b;
		n=n/b;
	}
	for(i=k-1;i>=0;i--)
	{
		r=(r*10)+a[i];
	}
	return r;
}
int chng_O2D(int n,int b)
{
	int a[100],i,k=0,t=0;
	while(n>0)
	{
		a[k++]=n%10;
		n=n/10;
	}
	for(i=0;i<k;i++)
	{
		t+=power(b,i)*a[i];
	}
	return t;
}
int main(int c,char **v)
{
	int i,j,n1,n2,b1,b2;
	if(c!=4)
	{
		printf("ERORR");
		return 0;
	}
	for(i=1;i<c;i++)
	{
		for(j=0;v[i][j]!='\0';j++)
		{
			if(v[i][j]<48 || v[i][j]>57)
			{
				printf("ERORR");
				return 0;
			}
		}
	}
	n1=atoi(v[1]);
	b1=atoi(v[2]);
	b2=atoi(v[3]);
	if(b1==b2)
    {
        n2=n1;
    }
	else if(b1==10)
	{
		n2=chng_D2O(n1,b2);
	}
	else if(b2==10)
	{
		n2=chng_O2D(n1,b1);
	}
	else
	{
		n2=chng_O2D(n1,b1);
		n2=chng_D2O(n2,b2);
	}
	printf("\n%d\n",n2);
	return 0;
}


