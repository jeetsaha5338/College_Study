#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void rev(char *s)
{
    if(strlen(s)==0)
        return;
    else
        rev(s+1);
    printf("%c",*s);
    return;
}
int main()
{
    int i,j,k;
    char s[50];
    printf("Enter the string:");
    gets(s);
    rev(s);
    return 0;
}
