#include<iostream>
using namespace std;
class circle
{
		int r;
		float A,P;
	public:
		circle(int i)
		{
			r=i;
		}
		void area()
		{
			A=(r*r*22)/7;
			cout<<"\nVALUE OF AREA:"<<A;
		}
		void peri()
		{
			P=(2*22*r)/7;
			cout<<"\nVALUE OF PERIMTER:"<<P;
		}
};

int main()
{
	int n;
	cout<<"ENTER THE VALUE OF RADIUS:";
	cin>>n;
	circle c(n);
	c.area();
	c.peri();
	return 0;
}
