#include<iostream>
using namespace std;
class DM
{
		float m,cm;
	public:
		DM()
		{
			m=0;cm=0;
		}
		DM(float a,float b)
		{
			m=a;cm=b;
		}
		void display()
		{
			cout<<"METER:"<<m<<"\tCENT.:"<<cm<<"\n";
		}
		float convertB()
		{
			float x=cm+(m*100);
			return (x*0.3937);
		}
		float convertM()
		{
			return cm+(m*100);
		}
		//friend void addition(DB& ,DM&);
};
class DB
{
		float feet,inch;
	public:
		DB()
		{
			feet=0;inch=0;
		}
		DB(float a,float b)
		{
			feet=a;inch=b;
		}
		void display()
		{
			cout<<"FEET:"<<feet<<"\tINCH:"<<inch<<"\n";
		}
		float convertM()
		{
			float x=inch+(feet*12);
			return (x*2.54);
		}
		float convertB()
		{
			return inch+(feet*12);
		}
		friend void addition(DB&,DM&);
};
void addition(DB& a,DM& b)
{
	float x=a.convertB()+b.convertB();
	int y=x/12;
	x=x-(y*12);
	cout<<"FEET:"<<y<<"\tINCH:"<<x<<"\n";
	float i=a.convertM()+b.convertM();
	int j=i/100;
	i=i-(j*100);
	cout<<"METER:"<<j<<"\tCENT.:"<<i<<"\n";
}
int main()
{
	DB b(0,10);
	DM m(0,0);
	b.display();
	m.display();
	addition(b,m);
	return 0;
}
