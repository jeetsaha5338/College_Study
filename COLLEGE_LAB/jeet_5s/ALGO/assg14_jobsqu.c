//jobsequence
#include<stdio.h>
int n;
int dl[100],P[100];
char result[100],slot[100],job[100];
int min(int a,int b)
{
	if(a<b) return a;
	return b;
}
void swap(int a,int b)
{
	int t;
	t=P[b];
	P[b]=P[a];
	P[a]=t;
	t=dl[b];
	dl[b]=dl[a];
	dl[a]=t;
	char c;
	c=job[b];
	job[b]=job[a];
	job[a]=c;
}
void selection()
{
	int i,j;
	float t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(P[j]<P[j+1])
			{
				swap(j,j+1);
			}
		}
	}
}
int main()
{
	int i,j,k;
	float u;
	FILE *fp;
	fp=fopen("jobsequence.txt","r");
	fscanf(fp,"%d\n",&n);
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%c\t%d\t%d\n",&job[i],&P[i],&dl[i]);
	}
	selection();
	for(i=0;i<n;i++)
	{
		printf("%c\t%d\t%d\n",job[i],P[i],dl[i]);
	}
	for(i=0;i<n;i++)
	{
		slot[i]='f';
	}
	for(i=0;i<n;i++)
	{
		k=min(n,dl[i]);
		for(j=k-1;j>=0;j--)
		{
			if(slot[j]=='f')
			{
				result[j]=job[i];
				slot[j]='t';
				break;
			}
		}
	}
	printf("OUTPUT:\n");
	for(i=0;i<n;i++)
	{
		printf("\t%c",result[i]);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
