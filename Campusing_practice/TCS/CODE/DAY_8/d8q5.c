#include<stdio.h>
#include<stdlib.h>
int main()
{
    char s[50],temp;
    int i,st,e,len,j;
    printf("Enter The String:");
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++);
    len=i;
    st=0;
    printf("%s\n",s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='_')
        {
            //printf("%d %d",i,len);
            e=i-1;
            for(j=st;j<=(st+e)/2;j++)
            {
                temp=s[st+e-j];
                s[st+e-j]=s[j];
                s[j]=temp;
            }
            st=i+1;
        }
    }
    e=i-2;
    for(j=st;j<=(st+e)/2;j++)
    {
        temp=s[st+e-j];
        s[st+e-j]=s[j];
        s[j]=temp;
    }
    printf("%s\n",s);
    return 0;
}
