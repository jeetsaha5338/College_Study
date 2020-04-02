#include<stdio.h>
int main()
{
    char s[50],ch;
    int k=0;
    printf("Enter The File name:");
    scanf("%s",s);
    FILE *fp;
    fp=fopen(s,"r");
    if(fp==NULL)
    {
        printf("ERROR");
        return 0;
    }
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        if(ch=='\n')
            k++;
        ch=fgetc(fp);
    }
    printf("NO. OF LINES:%d",k);
    fclose(fp);
    return 0;
}
