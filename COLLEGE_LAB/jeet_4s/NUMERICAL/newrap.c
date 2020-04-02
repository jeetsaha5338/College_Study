#include<stdio.h>
#include<math.h>
#define f(x)(3*x-cos(x))
#define df(x) (3+sin(x))
int main()
{
	float a,b,p,c,e;
	printf("enter accuracy : ");
	scanf("%f",&e);
	do
	{
		printf("enter the value of a and b : ");
		scanf("%f %f",&a,&b);
	}while((f(a)*f(b))>0);
	do
	{
		p=a;
		c=a-(f(a)/df(a));
		a=c;
	}while(fabs(p-c)>=e);
	printf("the required root is %f",p);
	return 0;
}
