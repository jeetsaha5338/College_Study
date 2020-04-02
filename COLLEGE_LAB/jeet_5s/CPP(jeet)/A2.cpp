#include<iostream>
using namespace std;
class DATE
{
		int d,m,y;
	public:
		int f=0;
		int setdate(int i,int j,int k)
		{
			switch(j)
			{
				case 1:		case 3:		case 5:		case 7: 	case 8:		case 10:	case 12:	
							
							if(i>31)	{	f=1;	}
							break;	

				case 2:		if(k%4==0)
							{
								if((k%100==0)&&(k%400==0))
								{
									if(i>29) { f=1; }
								}
								else if(k%100==0)
								{	
									if(i>28) { f=1; }
								}
							}
							else
							{	
								if(i>28) { f=1; }
							}
							break;

				case 4:		case 6:		case 9:		case 11:	
							
							if(i>30)	{	f=1;	}
							break;
		
			}




			if(f==0)
			{
				d=i;m=j;y=k;
				return 1;
			}
			else
			{
				cout<<"\nINVALID DATE\n";
				return 2;
			}
		}
		void getdate()
		{
			cout<<"\nYOUR DATE IS:"<<d<<"/"<<m<<"/"<<y;
		}
};

int main()
{
	int d,m,y,k;
	cout<<"ENTER YOUR DATE:";
	cin>>d>>m>>y;
	DATE o;
	k=o.setdate(d,m,y);
	if(k==1)
	{
		o.getdate();
	}
	return 0;
}
	

