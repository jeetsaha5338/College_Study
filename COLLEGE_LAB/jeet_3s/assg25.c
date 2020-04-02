#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node nd;

nd*insert_begining(nd*,int);

nd*insert_end(nd*,int);

nd*search_key(nd*,int);

nd*insert_after_key(nd*,int);

nd*insert_before_key(nd*,int);

nd*delete_begining(nd*);

nd*delete_end(nd*);

nd*delete_any_position(nd*,int);

void display(nd*);

void main()
{
	int item,key,choise;
	nd *start=NULL;
	do{
		printf("\n\n\t\tENTER TOUR CHOISE:\n\n\tPRESS 1: ENTER NODE AT BEGINIG\n\tPRESS 2. ENTER NODE AT END\n\tPRESS 3: SEARCH\n\tPRESS 4: ENTER A NODE AFTER A GIVEN KEY\n\tPRESS 5: ENTER A NODE BEFORE A GIVEN KEY\n\tPRESS 6: DELETE NODE AT BEGINIG\n\tPRESS 7: DELETE NODE AT END\n\tPRESS 8: DELETE NODE AT ANY POSITION\n\tPRESS 11: DISPLAY\n\tPRESS 12: EXIT\n\n");
		scanf("%d",&choise);
		switch(choise)
		{
			case 1 :	printf("ENTER THE ELEMENT:\t");
						scanf("%d",&item);
						start=insert_begining(start,item);
						break;

			case 2 :	printf("ENTER THE ELEMENT:\t");
						scanf("%d",&item);
						start=insert_end(start,item);
						break;

			case 3 :	printf("ENTER THE KEY VALUE:");
						scanf("%d",&key);
						start=search_key(start,key);
						break;

			case 4 :	printf("ENTER THE KEY VALUE:");
						scanf("%d",&key);
						start=insert_after_key(start,key);
						break;

			case 5 :	printf("ENTER THE KEY VALUE:");
						scanf("%d",&key);
						start=insert_before_key(start,key);
						break;

			case 6 :	start=delete_begining(start);
						break;

			case 7 :	start=delete_end(start);
						break;

			case 8 :	printf("ENTER THE KEY VALUE:");
						scanf("%d",&key);
						start=delete_any_position(start,key);
						break;

			case 11:	display(start);
						break;

			case 12:	 exit(0);
						break;
		}
	  }while(1);
}
nd*insert_begining(nd *start,int item)
{
	nd *temp;
	temp=(nd*)malloc(sizeof(nd*));
	if(temp==NULL)
		printf("ALLOCATION UNSUCCSSFULL");
	else
	{
		temp->data=item;
		temp->next=start;
		start=temp;
	}
	return start;
}
nd*insert_end(nd *start,int item)
{
	nd *temp,*current;
	temp=(nd*)malloc(sizeof(nd*));
	if(temp==NULL)
		printf("ALLOCATION UNSUCCSSFULL");
	else
	{
		temp->data=item;
		temp->next=NULL;
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
nd*search_key(nd *start,int key)
{
	int f=0;
	nd *temp,*current;
	current=start;
	while(current!=NULL)
	{
		if(current->data==key)
		{
			f=1;
		}
		current=current->next;
	}
	if(f==1)
	{
		printf("\nELEMENT FOUND\n");
	}
	else
	{
		printf("\nELEMENT NOT FOUND\n");
	}
	return start;
}
nd*insert_after_key(nd* start,int key)
{
	int f=0;
	nd *temp,*current;
	current=start;
	while(current!=NULL)
	{
		if(current->data==key)
		{
			f=1;
			break;
		}
		current=current->next;
	}
	if(f==1)
	{
		temp=(nd*)malloc(sizeof(nd*));
		if(temp==NULL)
			printf("ALLOCATION UNSUCCSSFULL");
		else
		{
			printf("\n\tENTER THE ELEMENT:");
			scanf("%d",&temp->data);
			temp->next=current->next;
			current->next=temp;
		}
	}
	else
	{
		printf("\nKEY VALUE NOT FOUND\n");
	}
	return start;
}
nd*insert_before_key(nd* start,int key)
{
	int f=0;
	nd *temp,*current,*prev;
	current=start;
	while(current!=NULL)
	{
		if(current->data==key)
		{
			f=1;
			break;
		}
		prev=current;
		current=current->next;
	}
	if(f==1)
	{
		temp=(nd*)malloc(sizeof(nd*));
		if(temp==NULL)
			printf("\nALLOCATION UNSUCCSSFULL");
		else
		{
			printf("\n\tENTER THE ELEMENT:");
			scanf("%d",&temp->data);
			temp->next=current;
			if(current==start)
				start=temp;
			else
				prev->next=temp;
		}
	}
	else
	{
		printf("\nKEY VALUE NOT FOUND\n");
	}
	return start;
}
nd*delete_begining(nd* start)
{
	nd *current;
	current=start;
	if(start==NULL)
	{
		printf("\nDELETION NOT POSSIBLE\n");
	}
	else
	{
		start=current->next;
		free(current);
	}
	return start;
}
nd*delete_end(nd* start)
{
	nd *current,*prev;
	current=start;
	if(start==NULL)
	{
		printf("\nDELETION NOT POSSIBLE\n");
	}
	else
	{
		if(start->next==NULL)
			start=NULL;
		else
		{
			while(current->next!=NULL)
			{
				prev=current;
				current=current->next;
			}
			prev->next=current->next;
		}
		free(current);
	}
	return start;
}
nd*delete_any_position(nd* start,int key)
{
	nd *current,*prev;
	current=start;
	prev=start;
	if(start==NULL)
	{
		printf("\nDELETION NOT POSSIBLE\n");
	}
	else
	{
		while(current!=NULL)
		{
			if(current->data==key)
				break;
			else
			{
				prev=current;
				current=current->next;
			}
		}
		prev->next=current->next;
		free(current);
	}
	return start;
}
void display(nd *start)
{
	nd* i;
	printf("THE LINKED LIST IS:");
	for(i=start;i!=NULL;i=i->next)
	{
		printf("\t%d",i->data);
	}
}

