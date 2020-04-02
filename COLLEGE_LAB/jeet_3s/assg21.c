#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct queue
{
	int a[MAX];
	int front;
	int rear;
};
typedef struct queue st;
void insertq(int,st*);
void deleteq(st*);
void displayq(st*);
void main()
{
	int item,choise;
	st s;
	s.front=-1;
	s.rear=-1;
	do{	
		printf("\n\n\t\tENTER YOUR CHOISE:\n\n\tPRESS 1: INSERT\n\tPRESS 2. DETELE\n\tPRESS 3: DISPLAY\n\tPRESS 4: EXIT\n\n");
		scanf("%d",&choise);
		switch(choise)
		{	
			case 1: printf("\n\tENTER THE ELEMENT:\t");
					scanf("%d",&item);
					insertq(item,&s);
					break;
			case 2: deleteq(&s);
					break;
			case 3: displayq(&s);
					break;
			case 4: exit(0);
					break;
		}
	  }while(1);
}
void insertq(int item,st *p)
{
	if(p->rear==MAX-1)
	{
		printf("\n\tINSERTION IS NOT POSSIBLE\n\n");
	}
	else
	{
		p->rear++;
		p->a[p->rear]=item;
	}
}
void deleteq(st *p)
{
	if(p->front==p->rear)
	{
		printf("\n\tDELETION IS NOT POSSIBLE\n\n");
	}
	else
	{
		p->front++;
		printf("\n\tDELETED ELEMENT IS=\t%d\n\n",p->a[p->front]);
		
	}
}
void displayq(st *p)
{
	int i;
	if(p->front==p->rear)
	{
		printf("\n\tTHE QUEUE IS EMPTY\n");
	}
	else
	{
		printf("\n\tELEMENT(S) PRESENT IN THE QUEUE IS:");
		for(i=(p->front+1);i<=p->rear;i++)
		{
			printf("%5d\t",p->a[i]);
		}
		printf("\n\n");
	}
}


