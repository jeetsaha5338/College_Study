#include<stdio.h>
#include<stdlib.h>
int chng(int d,int m,int y)
{
	int t,i;
	t=(y-1)*365;
	t+=(y-1)/4-(y-1)/100+(y-1)/400;
	for(i=m-1;i>0;i--)
	{
		if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
		{
			t+=31;
		}
		else if(i==4 || i==6 || i==9 || i==11)
		{
			t+=30;
		}		
		else if(i==2)
		{
			if(y%4==0 && y%100!=0 || y%400==0)
			{
				t+=29;
			}
			else
			{
				t+=28;
			}
		}
	}
	t+=d;
	return t;
}
int main(int c,char **v)
{
	int i,j;
	int d[2],m[2],y[2];//01*34*6789
	if(c!=3)
	{
		printf("ERROR\n");
		return 0;
	}
	for(i=1;i<c;i++)
	{
		for(j=0;v[i][j]!='\0';j++)
		{
			if(v[i][j]==47)
			{
				if(j!=2 && j!=5)
				{
					printf("ERROR\n");
					return 0;
				}
			}
			else if(v[i][j]<48 || v[i][j]>57)
			{
				printf("ERROR\n");
				return 0;
			}
		}
		d[i-1]=(v[i][0]-48)*10+(v[i][1]-48);
		m[i-1]=(v[i][3]-48)*10+(v[i][4]-48);
		y[i-1]=(v[i][6]-48)*1000+(v[i][7]-48)*100+(v[i][8]-48)*10+(v[i][9]-48);
	}
	for(i=0;i<2;i++)
	{
		printf("%d/%d/%d\n",d[i],m[i],y[i]);
	}
	for(i=0;i<2;i++)
	{
		if(y[i]<0)
		{
			printf("ERROR2\n");
			return 0;
		}
		if(m[i]<0 || m[i]>12)
		{
			printf("ERROR2\n");
			return 0;
		}		
		if(m[i]==2)
		{
			if(y[i]%4==0 && y[i]%100!=0 || y[i]%400==0)
			{
				if(d[i]<1 || d[i]>29)
				{
					printf("ERROR1\n");
					return 0;
				}
			}
			else
			{
				if(d[i]<1 || d[i]>28)
				{
					printf("ERROR2\n");
					return 0;
				}
			}
		}
		else if(m[i]==1 || m[i]==3 || m[i]==5 || m[i]==7 || m[i]==8 || m[i]==10 || m[i]==12)
		{
			if(d[i]<1 || d[i]>31)
			{
				printf("ERROR2\n");
				return 0;
			}
		}
		else if(m[i]==4 || m[i]==6 || m[i]==9 || m[i]==11)
		{
			if(d[i]<1 || d[i]>30)
			{
				printf("ERROR2\n");
				return 0;
			}
		}				
	}
	//printf("%d\n",chng(d[0],m[0],y[0]));
	//printf("%d\n",chng(d[1],m[1],y[1]));
	j=chng(d[1],m[1],y[1])-chng(d[0],m[0],y[0]);
	printf("\n%d\n",j);
	return 0;
}
		
