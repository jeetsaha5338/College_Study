#include<stdio.h>
#include<stdlib.h>
int main(int c,char **v)
{
	int i,j,f;
	float n[2];
	if(c!=3)
	{
		printf("\nERROR\n");
		exit(1);
	}
	else
	{
		for(i=1;i<c;i++)
		{
			f=0;
			for(j=0;v[i][j]!='\0';j++)
			{
				if(v[i][j]==45 && j==0)// '-' can only placed in 0'th pos
				{
					if(v[i][1]<48 || v[i][1]>57)//if 1'th pos not a digit	
					{
						if(v[i][1]==46 && v[i][2]>47 && v[i][2]<58){}
						//if 1'th pos is '.' then 2'th should a digit
						else//if not then error
						{
							printf("\nERROR\n");
							exit(1);
						}
					}
				}
				else if(v[i][j]==46 && f==0)// no of '.' is more than one or not
				{
					f=1;
				}				
				else if(v[i][j]<48 || v[i][j]>57 )// it is digit or not
				{
					printf("\nERROR\n");
					exit(1);
				}
			}
			n[i-1]=atof(v[i]);
		}
		printf("%f+%f=%f",n[0],n[1],n[0]+n[1]);
	}
	return 0;
}
