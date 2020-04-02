#include<iostream>
using namespace std;
class base
{
		float a,b;
	public:
		base(){ a=0;b=0; }
		base( float i, float j){ a=i;b=j; }
		void show()
		{
			cout<<"complex:"<<a<<"+"<<b<<"i"<<"\n";
		}
		float geta(){return a;}
		float getb(){return b;}
};
class derive: public base
{

		float x,y,da,db;
	public:

		derive(){ x=0;y=0; }
		derive( float i, float j)
		{
			x=i;y=j;
		}
		void add(base& b)
		{
			da=b.geta();
			db=b.getb();
			float m,n;
			m=da+x;
			n=db+y;
			cout<<"complex:"<<m<<"+"<<n<<"i"<<"\n";
		}
		void show()
		{
			cout<<"complex:"<<x<<"+"<<y<<"i"<<"\n";
		}
		friend class third;
};
class third
{
	public:
		void sub(derive& d,base& b1)
		{
			float m,n,i,j;
			m=b1.geta()-d.x;
			n=b1.getb()-d.y;
			cout<<"complex:"<<m<<"+"<<n<<"i"<<"\n";
		}
};
int main()
{
	base b(2.5,3.5);
	derive d(1.5,2.5);
	third t;
	b.show();
	d.show();
	d.add(b);
	t.sub(d,b);
	return 0;
}
