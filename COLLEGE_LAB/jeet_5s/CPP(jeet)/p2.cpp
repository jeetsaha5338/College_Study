#include<iostream>
#include<math.h>
using namespace std;
class area
{
		int a,b,c,x,y,l,s;
		float ta;
	public:
		area(int i,int x1,int y1,int a1,int b1,int c1)
		{
			l=i;
			a=a1;
			b=b1;
			c=c1;
			x=x1;
			y=y1;
		}
		
		void printarea( )
		{
			cout<<"\nVALUE OF AREA OF SQUARE:"<<l*l;
			cout<<"\nVALUE OF AREA OF RECTANGLE:"<<x*y;
			s=(a+b+c)/2;
			ta=(s*(s-a)*(s-b)*(s-c));
			cout<<"\nVALUE OF AREA TRIANGLE:"<<ta;
			cout<<"\nVALUE OF AREA TRIANGLE:"<<sqrt(ta);
		}
};

int main()
{
	int a,b,c,x,y,l;
	cout<<"ENTER THE VALUE OF SIDE OF SQUARE,SIDES OF RECTANGLE,SIDES OF TRIANGLE:";
	cin>>l;
	cin>>x;
	cin>>y;
	cin>>a;
	cin>>b;
	cin>>c;
	
	area A(l,x,y,a,b,c);
	A.printarea();
	return 0;
}
		
