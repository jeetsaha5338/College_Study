//knapsack
#include<stdio.h>
#define max 100
int n,M;
float P[max],W[max],W1[max],X[max];
void swap(int a,int b)
{
	int t;
	t=P[b];
	P[b]=P[a];
	P[a]=t;
	t=W[b];
	W[b]=W[a];
	W[a]=t;
}
void selection()
{
	int i,j;
	float t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if((P[j]/W[j])<(P[j+1]/W[j+1]))
			{
				swap(j,j+1);
			}
		}
	}
}
int main()
{
	int i,l,j;
	float u;
	FILE *fp;
	fp=fopen("knapsack.txt","r");
	fscanf(fp,"%d\t%d\n",&n,&M);
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%f\t%f\n",&P[i],&W[i]);
	}
	selection();
	for(i=0;i<n;i++)
	{
		X[i]=0;
	}
	u=M;
	for(i=0;i<n;i++)
	{
		if(W[i]>u)
		{	break;
		}
		else
		{
			X[i]=1;
			u=u-W[i];
		}
	}
	if(i<n)
	{
		X[i]=u/W[i];
	}
	printf("OUTPUT:\n");
	for(i=0;i<n;i++)
	{
		printf("\t%f\t%f\t%f\n",P[i],W[i],X[i]);
	}
	fclose(fp);
	return 0;
}

	
