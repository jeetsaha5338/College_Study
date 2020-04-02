//file create

#include<stdio.h>

int main()
{

	int i,v1,v2,v,e,c;
	FILE *fp;
	fp=fopen("file_graph.txt","w");
	printf("Enter the Number of Vertex And Edge:");
	scanf("%d%d",&v,&e);
	fprintf(fp,"%d %d\n",v,e);
	
	for(i=0;i<v;i++)
	{	
		printf("Enter the cost for Vertex1 to Vertex2:");
		scanf("%d%d%d",&v1,&v2,&c);
		fprintf(fp,"%d\t%d\t%d\n",v1,v2,c);
	}
	fclose(fp);
	return 0;
}
