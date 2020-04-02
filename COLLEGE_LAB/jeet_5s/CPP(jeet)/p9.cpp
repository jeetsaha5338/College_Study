#include<iostream>
using namespace std;
class shape
{
	public:
		virtual void find_area()=0;
		virtual void display()=0;
};
class circle: public shape
{
	int r;
	float a;
	public:
		circle(int i){ r=i; }
		void find_area()
		{
			a=(22*r*r)/7;
		}	
		void display()
		{
			cout<<"Arae Of Circle Is:"<<a<<"\n";
		}
};
class rectangle: public shape
{
	int x,y;
	float a;
	public:
		rectangle(int i,int j){ x=i; y=j; }
		void find_area()
		{
			a=x*y;
		}	
		void display()
		{
			cout<<"Arae Of Rectangle Is:"<<a<<"\n";
		}
};
int main()
{
	rectangle r(5,6);
	circle c(7);
	r.find_area();
	r.display();
	c.find_area();
	c.display();
	return 0;
}



		
