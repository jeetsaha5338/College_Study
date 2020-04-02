#include<stdio.h>
int check_rev(char *s,int n)
{
    int i;
    for(i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
        {
            return 0;
            break;
        }
    }
    return 1;
}
int main()
{
    int i,len,k;
    char str[50];
    printf("Enter String:");
    scanf("%s",str);
    for(len=0;str[len]!='\0';len++);
    printf("%s\t%d",str,len);
    for(i=0;i<len;i++)
    {
        k=check_rev(str,len-i);
        if(k!=0)
        {
            printf("\nMinimum Deletion %d Required\n",i);
            break;
        }
    }
    return 0;
}
