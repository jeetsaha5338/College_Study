#include<iostream>
using namespace std;
class complex
{
	public:
		int p,q;
		complex(){}
		complex(int i,int j)
		{
			p=i;q=j;
		}
};
class ADD:public complex
{
		int i,j;
	public:
		ADD(){}
		ADD(int m,int n)
		{
			i=m;j=n;
		}
		int Addition(int x,int y)
		{
			return (x+y);
		}
		float Addition(float a,float b,int c)
		{
			return (a+b+c);
		}
		void Addition(complex& a,complex& b)
		{
			int i=a.p+b.p;
			int j=a.q+b.q;
			cout<<"Result3=>"<<i<<"+"<<j<<"i"<<"\n";
		}
};

int main()
{
	int i,j,c,m,n;
	float a,b;
	cout<<"Enter value for two integers=>";
	cin>>m>>n;
	ADD A1;
	cout<<"Result1=>"<<A1.Addition(m,n)<<"\n";
	cout<<"Enter value for two float & one integers=>";
	cin>>a>>b>>c;
	cout<<"Result2=>"<<A1.Addition(a,b,c)<<"\n";
	cout<<"Enter value for 1st complex no.=>";
	cin>>i>>j;
	complex c1(i,j);
	cout<<"Enter value for 2nd complex no.=>";
	cin>>i>>j;
	complex c2(i,j);
	A1.Addition(c1,c2);
	return 0;
}
