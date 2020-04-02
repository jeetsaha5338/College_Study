#include<stdio.h>
#include<stdlib.h>
struct node{int data;struct node *next;};
typedef struct node nd;
void main()
{
	int item,flag=0;
	nd *temp,*current;
	nd *start=NULL;
	do{
		printf("\nENTER DATA:");
		scanf("%d",&item);
		temp=(nd*)malloc(sizeof(nd));
		if(temp==NULL)
		{
			printf("\nALLOCATION UNSUCCSSFULL\n");
			return;
		}
		temp->data=item;
		temp->next=NULL;
		if(start==NULL)
		{
			start=temp;
		}
		else
		{
			current->next=temp;
		}
		current=temp;
		printf("IF YOU WANT TO CONTINUE THIS PRESS 1\n");
		scanf("%d",&flag);
		}while(flag==1);
		for(current=start;current!=NULL;current=current->next)
		{
			printf("%d\t",current->data);
		}
}
