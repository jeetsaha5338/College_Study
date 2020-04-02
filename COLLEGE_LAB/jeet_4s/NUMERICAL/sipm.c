//simpson
//simpson
#include<stdio.h>
#include<math.h>
void main()
{
	int n,i,j;
	float q=0,b,x[20],y[50],s,a,h;
	s=0;
	printf("Enter the value of n");
	scanf("%d",&n);
	printf("Enter the limits:");
	scanf("%f%f",&a,&b);
	h=(b-a)/(float)n;
	x[0]=a;
	
	for(i=1;i<=n;i++)
	{
		x[i]=x[i-1]+h;
		
	}
	y[0]=sin(x[0]*x[0]);
	for(i=1;i<n;i++)
{
	y[i]=sin(x[i]*x[i]);
	if(i%2==0)
	s=s+2*y[i];
	else
	q=q+4*y[i];
}
y[n]=sin(x[n]*x[n]);
for(i=0;i<=n;i++)
printf("%.3f\t%.3f\n",x[i],y[i]);
s=h/3*((y[0]+y[n])+s+q);
printf("integration=%.3f\n",s);
}
