#include<stdio.h>
#include<string.h>
int main()
{
    FILE *fp,*fp1;
    char ch,prev_ch='\0';
    int f=0;
    fp=fopen("persistent_in.txt","r");
    fp1=fopen("persistent_out.txt","w");
    while(!feof(fp))
    {
        fscanf(fp,"%c",&ch);
        if(ch==' ' || ch=='\n')
        {
            f=1;
            prev_ch=ch;
        }
        else
        {
            if(f==1 && ch!='.')
            {
                fprintf(fp1,"%c",prev_ch);
            }
            fprintf(fp1,"%c",ch);
            prev_ch=ch;
            f=0;
        }
    }
    fclose(fp);
    fclose(fp1);
    return 0;
}
