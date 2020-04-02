#include<stdio.h>
#include<math.h>
float main()
{                                                                                                                                 
	float x[10],y[10];
	int i,j;
	float n,k,l=0,t,r,m;
	printf("ENTER THE NO. OF ITEM:");
	scanf("%f",&n);
	printf("\nENTER VALUE OF 'X':\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&x[i]);
	}
	printf("\nENTER VALUE OF 'Y':\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&y[i]);
	}
	printf("\n\tX:");
	for(i=0;i<n;i++)
	{
		printf("\t%f",x[i]);
	}
	printf("\n\tY:");
	for(i=0;i<n;i++)
	{
		printf("\t%f",y[i]);
	}
	printf("\n");
	printf("ENTER VALUE OF K:");
	scanf("%f",&k);
	for(i=0;i<n;i++)
	{
		t=1;
		r=1;
		for(j=0;j<n;j++)
		{
			if(j!=i)
			{
				t=t*(k-x[j]);
				r=r*(x[i]-x[j]);
			}
		}
		m=(t/r)*y[i];
		l=l+m;
	}
	printf("VALUE OF LANGRAGIAN VALUE OF F(%f) IS:%f\n",k,l);
	return 0;

}
		
		
	
