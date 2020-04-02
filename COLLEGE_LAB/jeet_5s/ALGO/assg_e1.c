#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int val; 
	struct queue *next;
};

typedef struct queue node;


node* insert(node *start)
{
	int i;
	printf("enter ur data:\n");
	scanf("%d",&i);
	node *nd=(node*)malloc(sizeof(node));
	nd->val=i;
	nd->next=NULL;
	node *cur;
	cur=start;
	if(start==NULL)
	{
		start=nd;
	}
	else
	{
		while(cur->next)		
		{
			cur=cur->next;
		}
		cur->next=nd;
	}
	return start;
}

node* delete(node *start)
{
	node *cur;
	if(start!=NULL)
	{
		cur=start;
		start=cur->next;
		free(cur);
	}
	else
	{
		printf("\nEmpty stack\n");
	}
	return start;
}

node* display(node *start)
{
	node *cur=start;
	if(start==NULL)
	{
		printf("Empty\n");
	}
	else
	{
		while(cur)		
		{
			printf("\t%d",cur->val);
			cur=cur->next;
		}
	}
	return start;
}

int main()
{
	int ch;
	node *start;
	do
	{
		printf("\nenter your choise:\n1 for INSERT\n2 for DELETE\n3 for DISPLAY\n4 for EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : start=insert(start);
					 break;
			case 2 : start=delete(start);
					 break;
			case 3 : printf("Your Queue is:");
					 start=display(start);
					 break;
			case 4 : exit(0);
		}
	}while(1);
	return 0;
}


