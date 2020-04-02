#include<stdio.h>
#include<stdlib.h>
#define MAX 4
void insertq(int);
void deleteq();
void displayq();
int a[MAX];
int front=-1;
int rear=-1;
void main()
{
	int choise,item;
	do{	
		printf("PRESS 1: INSERT\nPRESS 2. DELETE\nPRESS 3: DISPLAY\nPRESS 4: EXIT\n");
		scanf("%d",&choise);
		switch(choise)
		{	
			case 1: printf("enter the element:");
					scanf("%d",&item);
					insertq(item);
					break;
			case 2: deleteq();
					break;
			case 3: displayq();
					break;
			case 4: exit(0);
					break;
		}
	  }while(1);
}
void insertq(int item)
{
	if(rear==MAX-1)
	{
		printf("insertion is not posible\n");
	}
	else
	{
		rear++;
		a[rear]=item;
	}
}
void deleteq()
{
	if(front==rear)
	{
		printf("deletetion is not posible\n");
	}
	else
	{
		front++;
		printf("the deleted item is=%d\n",a[front]);
		
	}
}
void displayq()
{
	int i;
	if(front==rear)
	{
		printf("the array is empty\n");
	}
	else
	{
		printf("remain element in the array is:");
		for(i=(front+1);i<=rear;i++)
		{
			printf("%5d\t",a[i]);
		}
		printf("\n");
	}
}


