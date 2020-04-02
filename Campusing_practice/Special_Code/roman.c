#include<stdio.h>
#include<string.h>
int chng(int r,int t)
{
	if(t==1)
	{
		printf("I");
	}
	else if(t==5)
	{
		printf("V");
	}
	else if(t==10)
	{
		printf("X");
	}
	else if(t==50)
	{
		printf("L");
	}
	else if(t==100)
	{
		printf("C");
	}
	else if(t==500)
	{
		printf("D");
	}
	else if(t==1000)
	{
		printf("M");
	}
	else if(r==(5-1))
	{
		chng(1,1);
		chng(1,(5*(t/r)));
	}
	else if(r==(10-1))
	{
		chng(1,1);
		chng(1,(10*(t/r)));
	}
	else if(r<4)
	{
		chng(1,(t/r));
		chng(r-1,t-(t/r));
	}
	else if(r<9)
	{
		chng(1,5*(t/r));
		chng(r-5,t-(5*(t/r)));
	}
	return 0;
}
int power(int n)
{
	int f=1,i;
	for(i=0;i<n;i++)
	{
		f=f*10;
	}
	return f;
}
int main()
{
	int r=0,n,t=0,k,m;
	printf("Enter Your Number:");
	scanf("%d",&n);
	if(n<0 || n>3999)
    {
        printf("Invalid Input");
        return 0;
    }
	m=n;
	while(n>0)
	{
		r=r*10+(n%10);
		n=n/10;
		t++;
	}
	printf("\tRoman Number Is:");
	n=r;
	while(n>0)
	{
		r=n%10;
		k=r*power(--t);
		n=n/10;
		chng(r,k);

	}
	printf("\n");
	return 0;
}
