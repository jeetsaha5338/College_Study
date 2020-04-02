#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct stack
{
	int a[MAX];
	int top;
};
typedef struct stack st;
void push(int,st*);
void pop(st*);
void display(st*);
void main()
{
	int item,choise;
	st s;
	s.top=-1;
	do{	
		printf("\n\n\t\tENTER YOUR CHOISE:\n\n\tPRESS 1: PUSH.\n\tPRESS 2. POP\n\tPRESS 3: DISPLAY\n\tPRESS 4: EXIT\n\n");
		scanf("%d",&choise);
		switch(choise)
		{	
			case 1: printf("enter the element:\t");
					scanf("%d",&item);
					push(item,&s);
					break;
			case 2: pop(&s);
					break;
			case 3: display(&s);
					break;
			case 4: exit(0);
					break;
		}
	  }while(1);
}
void push(int item,st *p)
{
	if(p->top==MAX-1)
	{
		printf("insertion is not posible\n\n");
	}
	else
	{
		p->top++;
		p->a[p->top]=item;
	}
}
void pop(st *p)
{
	if(p->top==-1)
	{
		printf("deletetion is not posible\n\n");
	}
	else
	{
		printf("the deleted item is=\t%d\n\n",p->a[p->top]);
		p->top--;
	}
}
void display(st *p)
{
	int i;
	printf("element(s) present in the array is:");
	for(i=0;i<=p->top;i++)
	{
		printf("%5d\t",p->a[i]);
	}
	printf("\n\n");
}


