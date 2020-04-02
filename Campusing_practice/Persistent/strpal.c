#include<stdio.h>
#include<string.h>
int p=0;
char result[100];
void palprint(char *f,char *s,int l)
{
    if(strlen(s)==1)
    {
        strcat(f,s);
        strcat(result,f);
        strcat(result,"\n");
        p++;
        return;
    }
    char temp[2],k[5],str[100];
    int i,j;
    for(i=0;i<5;i++)
        k[i]='\0';
    for(i=0;i<100;i++)
        str[i]='\0';
    temp[1]='\0';
    strcpy(k,"");

    for(i=0;i<l;i++)
    {
        strcpy(k,"");
        strcpy(str,"");
        for(j=0;j<l;j++)
        {
            if(j!=i)
            {
                temp[0]=s[j];
                strcat(k,temp);
            }
        }
        temp[0]=s[i];
        strcpy(str,f);
        palprint(strcat(str,temp),k,strlen(k));
    }
    return;
}
int main()
{
    char str1[10],t;
    int i,j,l;
    printf("\nEnter the String:");
    gets(str1);
    l=strlen(str1);
    printf("\nEntered String:");
    for(i=0;i<l;i++)
    {
        printf("%c",str1[i]);
    }
    for(i=0;i<l-1;i++)
    {
        for(j=i+1;j<l;j++)
        {
            if(str1[j]<str1[i])
            {
                t=str1[i];
                str1[i]=str1[j];
                str1[j]=t;
            }
        }
    }
    printf("\nSorted String:");
    for(i=0;i<l;i++)
    {
        printf("%c",str1[i]);
    }
    for(i=0;i<100;i++)
        result[i]='\0';
    palprint("",str1,l);
    printf("\n\n%s",result);
    printf("\n%d\n",p);
    return 0;
}
