#include<iostream>
using namespace std;
class celc
{
		int c,f;
	public:
		celc(int i)
		{
			c=i;
		}
		void far()
		{
			f=((c*9)/5)+32;
			cout<<"FAR VALUE WILL BE:"<<f;
		}
};
class farh
{
		int c,f;
	public:
		farh(int i)
		{
			f=i;
		}
		void cel()
		{
			c=((f-32)*5)/9;
			cout<<"CEL VALUE WILL BE:"<<c;
		}
};

int main()
{
	int c,f;
	cout<<"\nENTER CEL VALUE:";
	cin>>c;
	celc c1(c);
	c1.far();
	cout<<"\nENTER FAR VALUE:";
	cin>>f;
	farh f1(f);
	f1.cel();
	cout<<"\n";
	return 0;
}
