#include<stdio.h>
#include<math.h>
int main()
{                                                                                                                                 
	int x[10],y[15][15];
	int i,j,h,l,n;
	float k,u,r,t=1;
	printf("ENTER THE NO. OF ITEM:");
	scanf("%d",&n);
	printf("ENTER THE NO. OF H:");
	scanf("%d",&h);
	printf("\nENTER VALUE OF 'X'\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	printf("\nENTER VALUE OF 'Y'\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&y[i][0]);
	}
	for(j=1;j<n;j++)
	{
		for(i=0;i<(n-j);i++)
		{
			y[i][j]=y[i+1][j-1]-y[i][j-1];
		}
	}
	printf("\n\n______________FORWARD DIFFERENCE TABLE______________\n\n");
	for(i=0;i<n;i++)
	{
		printf("\t%d\t",x[i]);
		for(j=0;j<(n-i);j++)
		{
			printf("\t%d",y[i][j]);
		}
		printf("\n\n");
	}     
	for(j=1;j<n;j++)
	{
		for(i=n-1;i>(j-1);i--)
		{
			y[i][j]=y[i][j-1]-y[i-1][j-1];
		}
	}
	printf("\n\n______________BACKWARD DIFFERENCE TABLE_____________\n\n");
	for(i=0;i<n;i++)
	{
		printf("\t%d",x[i]);
		for(j=0;j<=i;j++)
		{
			printf("\t%d",y[i][j]);
		}
		printf("\n\n");
	}   
	printf("ENTER THE VALUE OF K:");
	scanf("%f",&k);
	printf("\tFORWARD PRESS 1\n\tBACKWARD PRESS 2\t");
	scanf("%d",&l);
	if(l==1)
	{
		u=(k-x[0])/h;
		r=y[0][0];
		for(j=1;j<(n-0);j++)
		{
			t=t*(u-(j-1))/j;
			r=r+(t*y[0][j]);
		}
		printf("\nVALUE OF Y(K) IS[FORWARD]:%f\n",r); 
	}
	if(l==2)
	{
		u=(k-x[n-1])/h;
		r=y[n-1][0];
		for(j=1;j<(n-0);j++)
		{
			t=t*(u+(j-1))/j;
			r=r+(t*y[n-1][j]);
		}
		printf("\nVALUE OF Y(K) IS[BACKWARD]:%f\n",r); 
	}
	return 0;
}
			
	
