#include<stdio.h>
#include<math.h>
float f(double x)
{
	return x*x*x*x-32;
}
void main()
{
	float a,b,x,y,e,pn,p=0,l,u,re=1;
	printf("Enter the limits: ");
	scanf("%f%f",&a,&b);
	printf("Enter max error: ");
	scanf("%f",&e);
	if(f(a)*f(b)>0)
	{	
		printf("Invalid Input, Enter Again: ");
		scanf("%f%f",&a,&b);
	}
	l=a;
	u=b;
	while(re>e)
	{
		pn=p;
		p=(l*f(u)-u*f(l))/(f(u)-f(l));
		y=f(p);
		if(y<0)
			l=p;
		else
			u=p;
		re=fabs(p-pn)/fabs(pn);
	}
	printf("Root of the equation=%.4f\n",p);
}	
