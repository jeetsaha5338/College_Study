#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char *ch;
    int k=0,i,j;
    fp=fopen("strsort.txt","r");
    if(fp==NULL)
    {
        printf("ERROR");
    }
    while(fgetc(fp)!=EOF)
        k++;
    //printf("%d\n",k);
    ch=(char*)malloc(k*sizeof(char));
    fseek(fp,0,SEEK_SET);
    fgets(ch,k+1,fp);
    printf("%s",ch);
    char *s=strtok(ch," ");
    char s1[50][50];
    k=0;
    while(s!=NULL)
    {
        strcpy(s1[k++],s);
		//puts(s);
        s=strtok(NULL," ");
    }
    printf("\n%d\n",k);
    for(i=0;i<k;i++)
    {
        printf("%s\t%d\n",s1[i],strlen(s1[i]));
    }
    char t[50];
    for(i=0;i<k-1;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(strcasecmp(s1[i],s1[j])>0)
            {
                strcpy(t,s1[i]);
                strcpy(s1[i],s1[j]);
                strcpy(s1[j],t);
            }
        }
    }
    for(i=0;i<k;i++)
        printf("%s\n",s1[i]);
    return 0;
}
