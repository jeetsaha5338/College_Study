#include<iostream>
#include<math.h>
using namespace std;
class TRIANGLE
{
		int b,h;
	public:
		float x;
		//TRIANGLE(){	}
		TRIANGLE(int i,int j)
		{
			b=i;
			h=j;
		}
		void hypo()
		{
			x=sqrt(b*b+h*h);
			cout<<"Hypo=>"<<x<<"\n";
		}
		void area()
		{
			cout<<"Area=>"<<(b*h)/2<<"\n";
		}
};
int main()
{
	int m,n;
	cout<<"Enter The Values=>:";
	cin>>m>>n;
	TRIANGLE a(m,n);
	a.hypo();
	a.area();
	return 0;
}
	
