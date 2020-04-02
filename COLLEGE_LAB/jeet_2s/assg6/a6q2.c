#include<stdio.h>
float cos(float x)
{
	int i,n,term=1,sum=0;
	printf("no. of term:",n);
	scanf("%d",&n);
	for(i=1;i<2n;i=i+2)
	{
		sum=sum+term;
		term=((-1)*x*x)/(i*(i+1);
	}
	printf("the result=%d",sum);
	return sum;
}
int main()
{
	int result,a;
	float r;
	printf("the degree value:",a);
	scanf("%d",&a);
	r=(a*22)/(180*7);
	result=cos(r);
	printf("the result=%d",result);
	return 0;
}
