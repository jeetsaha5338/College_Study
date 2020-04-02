#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k;
    char str[500];
    printf("Enter String:");
    scanf("%s",str);
    int c,l=strlen(str);
    int *a=(int*)malloc(l*sizeof(int));
    for(i=0;i<l;i++)
    {
        c=0;
        for(j=0;j<l;j++)
        {
            if(str[i]==str[j])
                c++;
        }
        a[i]=c;
        c=0;
    }
    k=0;
    for(i=0;i<l;i++)
    {
        if(a[i]>k)
            k=a[i];
    }
    printf("%d\n",k);
    j=0;
    for(i=0;i<l;i++)
    {
        if(a[i]>j && a[i]!=k)
            j=a[i];
    }
    printf("%d\n",j);
    for(i=0;i<l;i++)
    {
        if(a[i]==j)
        {
            printf("%c",str[i]);
            return 0;
        }
    }
    printf("No");
    return 0;
}
