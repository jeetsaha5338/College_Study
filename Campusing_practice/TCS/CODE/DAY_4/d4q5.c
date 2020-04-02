#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	FILE *fp1,*fp2;
	char ch;
	if(argc!=3)
	{
		printf("ERROR");
		exit(0);
	}
	else
	{
		fp1=fopen(argv[1],"r");
		if(fp1==NULL)
			exit(0);
		fp2=fopen(argv[2],"w");
		ch=fgetc(fp1);
		while(ch!=EOF)
		{
			fputc(ch,fp2);
			ch=fgetc(fp1);
		}
		fclose(fp1);
		fclose(fp2);
	}
}
