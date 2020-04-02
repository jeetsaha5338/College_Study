// Linked Representation OF graph
#include<stdio.h>
#include<stdlib.h>
void create_adj(int,int);
void disp();
struct nd
{
	int val; 
	struct nd *next;
};

typedef struct nd node;
node **head;
int v,e;
int main()
{
	int i,v1,v2;
	printf("Enter The Total no. Vertices & Edges:");
	scanf("%d%d",&v,&e);
	head=(node**)malloc(v*sizeof(node*));
	for(i=0;i<v;i++)
	{
		head[i]=NULL;
	}
	for(i=0;i<e;i++)
	{
		printf("Enter Vertices For Edge %d\n",i+1);
		scanf("%d%d",&v1,&v2);
		
		create_adj(v1,v2);
		create_adj(v2,v1);
		
	}
	disp();
}

void create_adj(int v1,int v2)
{
	node *newnode=(node*)malloc(v*sizeof(node));
	node *temp;
	newnode->val=v2;
	newnode->next=NULL;
	if(head[v1]==NULL)
	{
		head[v1]=newnode;
	}
	else
	{
		temp=head[v1];
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

void disp()
{
	node *temp;
	int i;
	for(i=0;i<v;i++)
	{
		printf("%d",i);
		temp=head[i];
		while(temp)
		{
			printf("\t%d",temp->val);
			temp=temp->next;
		}
		printf("\n");
	}
}
