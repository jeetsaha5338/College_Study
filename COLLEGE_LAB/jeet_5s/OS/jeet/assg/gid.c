#include<stdio.h>
#include<pwd.h>
#include<grp.h>
#include<unistd.h>
int main()
{
	unsigned int x;
	struct passwd *p;
	struct group *q;
	x=getuid();
	p=getpwuid(x);
	q=getgrgid(p->pw_gid);

	printf("%u",q);
	//printf("USER_ID:%u\n",x);
	printf("GROUP_ID:%u\n",q->gr_gid);
	printf("GROUP_NAME:%s\n",q->gr_name);
	printf("GROUP_PASS:%s\n",q->gr_passwd);
	
	/*while(q->gr_mem)
	{	
		printf("GROUP_MEM:%s\n",q->gr_mem[i++]);
	}*/
	return 0;
}


