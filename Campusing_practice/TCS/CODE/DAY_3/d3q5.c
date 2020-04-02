#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,k,f;
    char s[500],s2[50];
    printf("Enter the string:");
    scanf("%[^\ns]",s);
    for(i=0;s[i]!='\0';i++);
    k=i;
    j=0;
    for(i=0;i<k;i++)
    {
        if(s[i]==32 && i!=0)
            s2[j++]=s[i];
        else if(s[i]>64 && s[i]<91)
        {
            s2[j++]=s[i];
        }
        else if(s[i]>96 && s[i]<123)
        {
            s2[j++]=s[i];
        }
    }
    s2[j]='\0';
    printf("\n%s",s2);
    for(i=0;i<j;i++)
    {
        if(s2[i]>96 && s2[i]<123)
            s2[i]-=32;
    }
    printf("\n%s",s2);
    for(i=0;i<j/2;i++)
    {
        if(s2[i]!=s2[j-i-1])
        {
            f=1;
            break;
        }
    }
    if(f==1)
        printf("\nNO");
    else
        printf("\nYES");
    return 0;
}
