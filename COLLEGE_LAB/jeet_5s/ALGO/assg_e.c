#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int val; 
	struct stack *next;
};

typedef struct stack node;
node *start;

void insert()
{
	int i;
	printf("enter ur data:\n");
	scanf("%d",&i);
	node *nd=(node*)malloc(sizeof(node));
	nd->val=i;
		nd->next=start;
		start=nd;
}

void delete()
{
	if(start)
	{
		start=start->next;
	}
	else
	{
		node *temp;
		temp=start;
		printf("\nEmpty stack\n");
		free(temp);
	}
}

void display(node *head)
{
	if(head==NULL)
	{
		return ;
	}
	else
	{
		display(head->next);
	}
	printf("\t%d",head->val);
}

int main()
{
	int ch;
	do
	{
		printf("\nenter your choise:\n1 for PUSH\n2 for POP\n3 for DISPLAY\n4 for EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : insert();
					 break;
			case 2 : delete();
					 break;
			case 3 : printf("Your Stack is:");
					 display(start);
					 break;
			case 4 : exit(0);
		}
	}while(1);
	return 0;
}


