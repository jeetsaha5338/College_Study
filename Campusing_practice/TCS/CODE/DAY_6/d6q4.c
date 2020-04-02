#include<stdio.h>
#include<stdlib.h>
int main(int c,char **v)
{
    int i,j,k=0;
    char ch,s[50];
    if(c!=4)
    {
        printf("ERORR");
        exit(1);
    }
    for(i=0;v[2][i]!='\0';i++);
    if(i!=1)
    {
        printf("ERORR");
        exit(1);
    }
    ch=v[2][0];
    for(i=0;v[1][i]!='\0';i++)
    {
        if(v[1][i]==ch)
        {
            for(j=0;v[3][j]!='\0';j++)
            {
                s[k++]=v[3][j];
            }
        }
        else
            s[k++]=v[1][i];
    }
    s[k]='\0';
    printf("%s",s);
    return 0;
}
