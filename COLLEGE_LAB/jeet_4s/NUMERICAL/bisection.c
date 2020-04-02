#include<stdio.h>
#include<math.h>
void main()
{
	float a,e,x,y,p=0,pn,re=1,h,l,b,u;
	e=0;
	printf("Enter max error: ");
	scanf("%f",&e);
	printf("Enter the limits:");
	scanf("%f%f",&a,&b);
	l=a;
	u=b;
while(re>e)
{
	pn=p;
	
	p=(l+u)/2;
	y=p*p*p-9*p+1;
	if(y<0)
	l=p;
	else
	u=p;
	re=fabs(p-pn)/fabs(pn);
}
printf("f(x)=%.4f\n",p);
}
