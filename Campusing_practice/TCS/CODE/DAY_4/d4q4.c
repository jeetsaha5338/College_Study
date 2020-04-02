#include<stdio.h>
#include<stdlib.h>
int main()
{
	char str[30],str1[30];
	int i,j,len,c=0;
	scanf("%s",str);
	i=0;
	while(str[i]!='\0')
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
		{
			c++;
		}
		i++;
	}
	i=0;
	while(str[i]!='\0')
	{
		if(str[i]>='a' && str[i]<='z')
		{
			str[i]=str[i]-32;
		}
		i++;
	}
	len=strlen(str);
	j=0;
	for(i=len-1;i>0;i--)
	{
		str1[j++]=str[i];
	}
	str1[j]='\0';
	printf("%d",c);
	printf("\n%s",str);
	printf("\n%s",str1);
	return 0;
}
