#include<stdio.h>
#include<pwd.h>
#include<grp.h>
#include<unistd.h>
typedef struct passwd pass;
typedef struct group grp;


int main()
{
	int x,i=0;
	pass  *p	;
	grp  *q;	
	x=getuid();	
		p=getpwuid(x);
		q=getgrgid(p->pw_gid);
		char **member=q->gr_mem;

	printf("Group_ID:%u\n",q->gr_gid);
	printf("Group_Name:%s\n",q->gr_name);
	printf("Group_Pass:%s\n",q->gr_passwd);	
	printf("Group_Members\n");	
		while(*member)
				{
						printf("%s\n",*(member));
						member++;
				}		
	
	return 0;	
}	
