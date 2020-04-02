#include<stdio.h>
int main()
{
int a[10],n,k,f=0,i;
printf("number of elements");
scanf("%d",&n);
printf("enter array elements");
for(i=0;i<n;i++);
scanf("%d",a[i]);
printf("enter the search elements");
scanf("%d",&k);
for(i=0;i<n;i++)
{
f=1;
break;
}
if(f==0)
printf("no match");
else
printf(" match found at position%d",i+1);
return 0;
}
