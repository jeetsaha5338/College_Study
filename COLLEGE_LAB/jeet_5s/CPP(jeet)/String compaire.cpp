//

#include<iostream>
using namespace std;
#include<string.h>
class T
{
	 char str[20];
	 public:
	 	T(){strcpy(str,"");}
	 	T(char *s)
	 	{
	 		strcpy(str,s);
	 	}
	 	void show()
	 	{
	 		cout<<str<<"\n";
	 	}
	 	bool operator > (T &s)
	 	{
	 			int x=0;
	 		 if(strlen(str)==strlen(s.str))
	 		 {
	 			 x=strcmp(str,s.str);
	 		 }
	 		 else if(strlen(str)>strlen(s.str))
	 		 {
	 		 	x=1;
	 		 }
	 		 if(x>0)
	 		 {	return true;}
	 		 return false;
	 	}
	 	bool operator < (T &s)
	 	{
	 		int y=0;
	 		 if(strlen(str)==strlen(s.str))
	 		 {
	 			 y=strcmp(s.str,str);
	 		 }
	 		 else if(strlen(s.str)>strlen(str))
	 		 {
	 		 	y=1;
	 		 }
	 		 if(y>0)
	 		 {	return true;}
	 		 return false;
	 	}
};
int main()
{
	T s1("yes");
	T s2("no");
	s1.show();
	s2.show();
	if(s1>s2)
	{
		cout<<"s1 big\n";
	}
	if(s1<s2)
	{
		cout<<"s2 big\n";
	}
	
	return 0;
}
