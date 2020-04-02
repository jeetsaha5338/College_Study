#include<stdio.h>
#include<math.h>
int main()
{
	int i,n,sum=0,a[60];
	float sd,avg,var=0,v;
	printf("enter no of elements=");
	scanf("%d",&n);
	printf("enter the elements=",a[i]);
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<=n-1;i++)
	{
		sum=sum+a[i];
		avg=sum/n;
		var=var+((a[i]-avg)*(a[i]-avg));
		v=var/n;
		sd=sqrt(v);
	}
	printf("the mean=%f\n",avg);
	printf("the var=%f\n",v);
	printf("the SD=%f",sd);
	return 0;
}
