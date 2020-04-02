#include<iostream>
using namespace std;
class complex
{
		int a,b;
	public:
		complex(int i,int j)
		{
			a=i;
			b=j;
		}
		void add(complex c1, complex c2)
		{
			a=c1.a+c2.a;
			b=c1.b+c2.b;
			cout<<"ADDED VALUE:"<<a<<"+"<<b<<"i";
		}
};

int main()
{
	int a,b;
	cout<<"ENTER THE 1ST NUMBER:";
	cin>>a;
	cin>>b;
	complex c1(a,b);
	cout<<"ENTER THE 2ND NUMBER:";
	cin>>a;
	cin>>b;
	complex c2(a,b);
	complex c3(0,0);
	c3.add(c1,c2);
}	
