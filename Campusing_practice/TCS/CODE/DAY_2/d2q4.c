#include<stdio.h>
int main(int c,char **v)
{
    int i;
    if(c!=2)
    {
        printf("Error");
        return 0;
    }
    for(i=0;v[1][i]!='\0';i++)
    {
        if(v[1][i]<65 || v[1][i]>122)
        {
            printf("Error");
            return 0;
        }
        if(v[1][i]>90 && v[1][i]<97)
        {
            printf("Error");
            return 0;
        }
    }
    printf("%s\n",v[1]);
    char s[50];
    int flag,j,k=0;
    s[k++]=v[1][0];
    for(i=1;v[1][i]!='\0';i++)
    {
        flag=0;
        for(j=0;j<k;j++)
        {
            if(s[j]==v[1][i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            s[k++]=v[1][i];
        }
    }
    s[k]='\0';
    printf("\n%s\n",s);
	return 0;
}
