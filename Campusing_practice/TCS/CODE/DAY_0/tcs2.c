#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int root(int n)
{
	int i=1;
	while(i*i<=n)
	{
		i++;
	}
	return i-1;
}
int main(int c,char **v)
{
	if(c!=2)
	{
		printf("\nERROR\n");
		exit(1);
	}
	int i,x,j;
	for(i=0;v[1][i]!='\0';i++)
	{
		if(v[1][i]<48 || v[1][i]>57)
		{
			printf("\nERROR\n");
			exit(1);
		}
	}
	x=atoi(v[1]);
	for(i=2;i<=x;i++)
	{
		for(j=2;j<=root(i);j++)
		{
			if(i%j==0)
			{
				printf("\t%d",i);
				break;
			}
		}
	}
	return 0;
}
