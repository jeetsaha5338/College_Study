//Newton's Divided Difference//
#include<stdio.h>
void main()
{
	int i,j,n;
	float x[100],y[100][100],m,h,u,s,p,q;
	printf("ENTER THE SIZE:\n");
	scanf("%d",&n);
	printf("ENTER THE VALUE OF X:\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&x[i]);
	}
	printf("ENTER THE VALUE OF Y:\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&y[i][0]);
	}
	printf("ENTER INTERPOLATING POINT=\n");
	scanf("%f",&m);
	for(j=1;j<n;j++)
	{
		for(i=0;i<n-j;i++)
		{
			y[i][j]=(y[i+1][j-1]-y[i][j-1])/(x[i+j]-x[i]);
		}
	}
	printf("\t\tDIVIDED DIFFARENCE TABLE:\n\n");
	for(i=0;i<n;i++)
	{
		printf("\t%f\t",x[i]);
		for(j=0;j<n-i;j++)
		{
			printf("%f\t",y[i][j]);
		}
		printf("\n");
	}
	q=1;
	s=y[0][0];
	for(j=1;j<=n-1;j++)
	{
		q=q*(m-x[j-1]);
		s=s+(q*y[0][j]);
	}
	printf("THE SUM IS=%f",s);
}
