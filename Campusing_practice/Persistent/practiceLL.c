#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define length 10
struct student
{
	char name[length];
	int age;
	char *rollno;
	struct student *next;
};
typedef struct student std;
std* insert_begining(std *start)
{
	std *temp=(std*)malloc(sizeof(std*));
	if(temp==NULL){	printf("\nCan't Create\n"); }
	else
	{
        printf("\nEnter Details:\n");
        printf("\tName:");
        scanf("%s",temp->name);
        printf("\tAge:");
        scanf("%d",&temp->age);
        printf("\tRoll No.:");
        scanf("%s",temp->rollno);
        temp->next=start;
		start=temp;
	}
	return start;
}
std* insert_end(std *start)
{
    std *current;
	std *temp=(std*)malloc(sizeof(std*));
	if(temp==NULL){	printf("\nCan't Create\n"); }
	else
	{
        printf("\nEnter Details:\n");
        printf("\tName:");
        scanf("%s",temp->name);
        printf("\tAge:");
        scanf("%d",&temp->age);
        printf("\tRoll No.:");
        scanf("%s",temp->rollno);
		temp->next=NULL;
		current=start;
		if(start==NULL)
		{
			start=temp;
		}
		else
		{
			current=start;
			while(current->next!=NULL)
			{
				current=current->next;
			}
			current->next=temp;
		}
	}
	return start;
}
std* delete_begining(std *start)
{
	std *cur;
	if(start==NULL)
	{
		printf("\nDeletion Not Posible");
	}
	else
	{
		cur=start;
		start=cur->next;
		free(cur);
	}
	return start;
}
std* delete_end(std* start)
{
	std *cur,*prev;
	if(start==NULL)
	{
		printf("\nDeletion Not Possible");
	}
	else
	{
		cur=start;
		while(cur->next!=NULL)
		{
			prev=cur;
			cur=cur->next;
		}
		prev->next=NULL;
		free(cur);
	}
	return start;
}
void search(std *start)
{
	std* i;
	char n[length],r[10];
	int a;
	printf("\nEnter Details:(If Don't Know Then Insert Random)\n");
    printf("\tName:");
    scanf("%s",n);
    printf("\tAge:");
    scanf("%d",&a);
    printf("\tRoll No.:");
    scanf("%s",r);
	printf("THE Searched LIST IS:");
	for(i=start;i!=NULL;i=i->next)
	{
		if((i->age)==a || strcmp(i->name,n)==0 || strcmp(i->rollno,r)==0)
		{
			printf("\n\tName:%s\tAge:%d\tRoll No.:%s",i->name,i->age,i->rollno);
		}
	}
}
void display(std *start)
{
	std* i;
	printf("THE LINKED LIST IS:");
	for(i=start;i!=NULL;i=i->next)
	{
		printf("\n\tName:%s\tAge:%d\tRoll No.:%s",i->name,i->age,i->rollno);
	}
}
int main()
{
	std *start=NULL;
	//start=insert_begining(start);
	//display(start);
	start=insert_end(start);
	display(start);
	start=insert_end(start);
	display(start);
	printf("\nhihih");
	start=insert_end(start);
	display(start);
	start=delete_begining(start);
	display(start);
	start=delete_end(start);
	display(start);
	//search(start);
	printf("\n\njojo");
	return 0;
}
