#include<stdio.h>
FILE *fp;
char v[1000];
int i;
char check(char ch)
{
    if(ch=='/')
    {
        fscanf(fp,"%c",&ch);
        while(ch!='\n')
        {
            v[i++]=ch;
            fscanf(fp,"%c",&ch);
        }
        v[i++]='\n\n';
        return ch;
    }
    else if(ch=='*')
    {
        while(1)
        {
            fscanf(fp,"%c",&ch);
            if(ch=='*')
            {
                fscanf(fp,"%c",&ch);
                if(ch=='/')
                {
                    fscanf(fp,"%c",&ch);
                    v[i++]='\n\n';
                    return ch;
                }
                v[i++]='*';
                v[i++]=ch;
            }
            else
            {
                v[i++]=ch;
            }
        }
    }
}
int main()
{
    int k=0;
    for(i=0;i<1000;i++)
        v[i]='\0';
    i=0;
    char ch;
    fp=fopen("hihi.txt","r");
    fscanf(fp,"%c",&ch);
    while(ch!='$')
    {
        printf("%c",ch);
        fscanf(fp,"%c",&ch);
        if(ch=='/')
        {
            fscanf(fp,"%c",&ch);
            if(ch=='*' || ch=='/')
            {
                k++;
                ch=check(ch);
            }
            else
                printf("/");
        }
    }
    printf("\n\nTotal Commented line:%d\nThese are->\n",k);
    for(i=0;v[i]!='\0';i++)
        printf("%c",v[i]);
    fclose(fp);
    return 0;
}
