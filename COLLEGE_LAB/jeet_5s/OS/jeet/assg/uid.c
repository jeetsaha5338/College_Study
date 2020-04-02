#include<stdio.h>
#include<pwd.h>
#include<unistd.h>
typedef struct passwd pass;
int main()
{
	int x;
	x=getuid();
	pass *p;
	p=getpwuid(x);
	printf("hehe_ID\n:%d",x);
	printf("hoho_n:%s\n",p->pw_name);
	printf("hoho_p:%s\n",p->pw_passwd);
	printf("hoho_f:%d\n",p->pw_gecos);
	printf("hoho_d:%s\n",p->pw_dir);
	printf("hoho_s:%s\n",p->pw_shell);
	return 0;
}


