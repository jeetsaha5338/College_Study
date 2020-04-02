#include<stdio.h>
#include<stdlib.h>
int *a,*stack,top=0,n;
void push(int a)
{
    if(top==n)
    {
        printf("\nPUSH NOT POSSIBLE\n");
        return;
    }
    stack[top++]=a;
}
void pop()
{
    top--;
}
void prisoner()
{
    int c=0,i;
    for(i=0;i<n;i++)
    {
        if(c%2!=0)
            a[i]=0;
        else
            push(a[i]);
        c++;
    }
    if(top==1)
    {
        printf("%d\n\n",stack[0]);
        return;
    }
    else
    {
        if(n%2!=0)
        {
            c=stack[top-1];
            for(i=top-1;i>0;i--)
            {
                stack[i]=stack[i-1];
            }
            stack[0]=c;
        }
        for(i=0;i<top;i++)
        {
            a[i]=stack[i];
        }
        n=top;
        top=0;
        prisoner();
    }
    return;
}
int main()
{
    int i;
    printf("Enter The Number Of PRISONER:");
    scanf("%d",&n);
    stack=(int*)malloc(n*sizeof(int));
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    printf("\nThe Man Who Survived is:\tP-");
    prisoner();
    return 0;

}
