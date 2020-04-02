#include<stdio.h>
#include<pwd.h>
#include<grp.h>
#include<unistd.h>
typedef struct passwd pass;
typedef struct group grp;


int main()
{
	int x;
	x=getuid();
	y=getgid();
	pass  *p	;
	grp  *q;	
		p=getpwuid(x);
		q=getgrgid(y);
	printf("User_ID: %d",x);
	printf(" User_Name :%s\n",p->pw_name);
	printf(" User_passwd :%s\n",p->pw_passwd);
	printf("User_Full name :%d\n",p->pw_uid);
	printf("User_Group id :%d\n",p->pw_gid);
	printf("User_Full Name :%s\n",p->pw_gecos);
	printf("User_Dir :%s\n",p->pw_dir);
	printf("User_Shell :%s\n",p->pw_shell);
	printf("Group_ID:%s",)
		return 0;	
}	
