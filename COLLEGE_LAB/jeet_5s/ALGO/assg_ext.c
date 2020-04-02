#include<stdio.h>

int main()
{
	int n,i,a;
	FILE* fp;
	fp=fopen("a.txt","w");
	printf("ENTER YOUR NO. OF DATA:");
	scanf("%d",&n);
	fprintf(fp,"%d\n",n);
	printf("ENTER YOUR DATA:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		fprintf(fp,"%d\n",a);
	}	
	fclose(fp);
	fp=fopen("a.txt","r");
	int b[10];
	for(i=0;i<n+1;i++)
	{
		fscanf(fp,"%d\n",&b[i]);
		//printf("%d",b[i]);
	}
	for(i=1;i<n+1;i++)
	{
		//fscanf(fp,"%d\n",&b[i]);
		printf("%d\n",b[i]);
	}
	fclose(fp);
	return 0;
}
