#include<iostream>
using namespace std;
class area
{
	int x,y;
	public:
	area( ){x=0;y=0;}
	area(int m, int n){x=m;y=n;}
	area(area &k){x=2*k.x;y=2*k.y;}
	void show()
	{
		cout<<"AREA:"<<x*y;
		cout<<"\n";
	}
};

int main()
{
	area a;
	area b(2,4);
	area c(b);
	a.show();
	b.show();
	c.show();
	return 0;
}
	
