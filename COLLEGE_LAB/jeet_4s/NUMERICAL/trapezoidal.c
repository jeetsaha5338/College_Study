//TRAPEZOIDAL RULE//
#include<stdio.h>
#include<math.h>
float fn(float x)
{
	float y;
	y=4*x-3*x*x;
	return y;
}
int main()
{
	int i,n;
	float u,l,s=0,y=0,h;
	printf("ENTER THE NUMBER OF INTERVALS===>\n");
	scanf("%d",&n);
	printf("ENTER THE LOWER LIMIT===>\n");
	scanf("%f",&l);
	printf("ENTER THE UPPER LIMIT===>\n");
	scanf("%f",&u);
	h=(u-l)/n;
	for(i=1;i<=n-1;i++)
	{
		s=s+fn(l+i*h);
	}
	y=(fn(l)+fn(u)+2*s)*h/2;
	printf("The value of y is :%f \n",y);
	return 0;
}
