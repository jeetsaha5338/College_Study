#include<stdio.h>
#include<stdlib.h>
#define MAX 4
void insertcq(int);
void deletecq();
void displaycq();
int a[MAX];
int front=0;
int rear=0;
int flag=0;
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
					insertcq(item);
					break;
			case 2: deletecq();
					break;
			case 3: displaycq();
					break;
			case 4: exit(0);
					break;
		}
	  }while(1);
}
void insertcq(int item)
{
	if((rear==front)&&(flag==1))
	{
		printf("CQ is full,insertion is not posible\n");
	}
	else
	{
		a[rear]=item;
		rear=(rear+1)%MAX;
		flag=1;
	}
}
void deletecq()
{
	if((front==rear)&&(flag==0))
	{
		printf("CQ is empty,deletetion is not posible\n");
	}
	else
	{
		printf("the deleted item is=%d\n",a[front]);
		front=(front+1)%MAX;
		flag=0;
	}
}
void displaycq()
{
	int f,i;
	printf("remain element in the array is:");
	i=front;
	f=flag;
	while(i!=rear||f==1)
	{
		printf("%5d\t",a[i]);
		f=0;
		i=(i+1)%MAX;
	}
	printf("\n");
}


