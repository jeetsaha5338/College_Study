//HEAP SORT
#include<stdio.h>
#include<stdlib.h>
int *a,length,size;
int parent(int);
int L_child(int);
int R_child(int);
void M_heapify(int);
void heap_sort();
void B_M_heap();
void swap(int,int);
int main()
{
	int i,n,j,t,k;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	length=n;
	printf("Enter the elements of an array\n");
	a= (int*)malloc((n+1)*sizeof(int));	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	heap_sort();
	printf("sorted array:");
	for(i=1;i<=n;i++)
	{
		printf("\t%d",a[i]);
	}
	printf("\n");
	return 0;
}

void heap_sort()
{
	int i;	
	B_M_heap();
	for(i=length;i>=2;i--)
	{
		swap(1,i);
		size--;
		M_heapify(1);
	}	
}
int parent(int i)
{
	return i/2;
}
int L_child(int i)
{
	return (2*i);
}
int R_child(int i)
{
	return (2*i)+1;
}
void M_heapify(int i)
{
	int l,r,max;
	l=L_child(i);
	r=R_child(i);
	if((l<=size)&&(a[l]>a[i]))
	{
		max=l;
	}
	else
	{
		max=i;
	}
	if((r<=size)&&(a[r]>a[max]))
	{
		max=r;
	}
	if(max!=i)
	{
		swap(i,max);
		M_heapify(max);
	}
}
void B_M_heap()
{
	int i;
	size=length;
	for(i=length/2;i>=1;i--)
	{
		M_heapify(i);
	}
}
void swap(int i,int j)
{
	int t;
	t=a[i];
	a[i]=a[j];
	a[j]=t;
}
