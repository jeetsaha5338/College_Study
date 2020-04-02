//TOWER OF HANOI

#include<stdio.h>

int toh(int,char,char,char);

int main()
{
	int n;
	char s,d,a;
	printf("ENTER NO. OF DISKS:");
	scanf("%d",&n);
	toh(n,'s','d','a');
	return 0;
}

int toh(int n,char s,char d,char a)
{
	if(n==1)
	{
		printf("MOVE DISK 1 FROM %c TO %c\n",s,d);
		return ;
	}
	else
	{
		toh(n-1,s,a,d);
		printf("MOVE DISK %d FROM %c TO %c\n",n,s,d);
		toh(n-1,a,d,s);
	}
}
