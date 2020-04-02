#include<stdio.h>
#include<string.h>
int main()
{
    FILE *fp;
    fp=fopen("file.txt","w+");
    char ch[50],*s="This is code::blocks";
    fputs(s,fp);
    fseek(fp,5,SEEK_SET);
    fgets(ch,7,fp);
    printf("%s\n",ch);
    fseek(fp,5,SEEK_CUR);
    fgets(ch,7,fp);
    printf("%s\n",ch);
    fseek(fp,-5,SEEK_END);
    fgets(ch,4,fp);
    printf("%s\n",ch);
    fclose(fp);
    return 0;
}
