#include<iostream>
using namespace std;
class complex
{
		double a,b;
	public:
		complex(double x,double y)
		{
			a=x;b=y;
		}
		complex(){}
		void show()
		{
			cout<<"value is:\n"<<a<<"+"<<b<<"i\n";
		}
		friend complex operator+(complex,complex);
		friend complex operator-(complex,complex);
		friend complex operator*(complex,complex);
};
complex operator +(complex r,complex t)
{
	complex temp;
	temp.a=r.a+t.a;
	temp.b=r.b+t.b;
	return temp;
}
complex operator -(complex r,complex t)
{
	complex temp;
	temp.a=r.a-t.a;
	temp.b=r.b-t.b;
	return temp;
}
complex operator *(complex r,complex t)
{
	complex temp;
	temp.a=(r.a*t.a)-(r.b*t.b);
	temp.b=(r.a*t.b)+(r.b*t.a);
	return temp;
}
int main()
{
	double x,y;
	cout<<"Enter 1st No:\n";
	cin>>x>>y;
	complex a(x,y);
	cout<<"Enter 2nd No:\n";
	cin>>x>>y;
	complex b(x,y);
	cout<<"Enter 3rd No:\n";
	cin>>x>>y;
	complex c(x,y);
	cout<<"Enter 4th No:\n";
	cin>>x>>y;
	complex d(x,y);
	complex e;
	e=a+b*c-d;
	e.show();
	return 0;
}

