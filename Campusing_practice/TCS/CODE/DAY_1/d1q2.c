#include<stdio.h>
#include<stdlib.h>
int main(int c,char **v)
{
	int i,j,f;
	if(c!=3)
	{
		printf("ERORR");
		return 0;
	}
	for(i=0;v[1][i]!='\0';i++)
	{
		f=0;
		for(j=0;v[2][j]!='\0';j++)
		{
			if(v[1][i]==v[2][j])
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			printf("%c",v[1][i]);
		}
	}
	printf("\n");
	return 0;
}
		
