#include<iostream>
using namespace std;
class height
{
		int feet,inch;
		float cm;
	public:
		height()
		{
			feet=0;
			inch=0;
		}
		height(int i,int j)
		{
			feet=i;
			inch=j;
		}
		float convert()
		{
			float k;
			k=(feet*12)+inch;
			cm=(k*2.54);
			return (cm);
		}
		void operator-(height& h)
		{
			height& h1=*this;
			float k1=h1.convert();
			float k2=h.convert();
			cout<<k1<<"cm.\n";
			cout<<k2<<"cm.\n";
			float k3=k1-k2;
			cout<<k3<<"cm.\n";
		}
};
int main()
{
	height h1(5,10);
	height h2(4,6);
	h1-h2;
	return 0;
}
