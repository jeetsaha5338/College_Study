#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node nd;


void display(nd*);
nd*insert_end(nd *start,int item)
{
	nd *temp,*current;
	temp=(nd*)malloc(sizeof(nd*));
	if(temp==NULL)
		printf("ALLOCATION UNSUCCSSFULL");
	else
	{
		temp->data=item;
		temp->next=start;
		if(start==NULL)
		{
			start=temp;
		}
		else
		{
			current=start;
			while(current->next!=start)
			{
				current=current->next;
			}
			current->next=temp;
		}
	}
	return start;
}

void display(nd *start)
{
	nd* i;
	printf("Elements Are:");
	for(i=start;i->next!=start;i=i->next)
	{
		printf("\t%d",i->data);
	}
	if(i!=NULL)
    {
        printf("\t%d",i->data);
    }

}

int main()
{
    int i,n;
    nd *start=NULL;
    printf("Enter No. Of Elements:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        start=insert_end(start,i);
    }
    display(start);
    return 0;
}
