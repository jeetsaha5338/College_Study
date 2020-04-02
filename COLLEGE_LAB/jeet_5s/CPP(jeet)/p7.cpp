/*using operator overloading*/



#include<iostream>  
using namespace std;
class complex
{
	int x,y;
	public:
		complex()
		{
		}
		friend istream& operator >>(istream&,complex&);
		friend ostream& operator <<(ostream &,complex&);
		
		complex operator *(complex &c)
		{
			complex c3;
			c3.x=((x*c.x)-(y*c.y));
			c3.y=(x*c.y)+(y*c.x);
			return c3;
		}
};
istream& operator >>(istream &input,complex& c)
{
	input>>c.x;	
	input>>c.y;
}
ostream& operator <<(ostream &output,complex& c)
{
	output<<c.x;
	output<<"+"<<c.y<<"i\n";
}
int main()
{
	complex c1,c2,c3;
	cout<<"enter 1st complex number\n";
	cin>>c1;
	cout<<"enter 2nd complex number\n";
	cin>>c2;
	cout<<c1;
	cout<<c2;
	c3=c1*c2;
	cout<<"the mulpiled complex number\n";
	cout<<c3;
	return 0;
}
