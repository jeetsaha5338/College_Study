#include<iostream>
using namespace std;

class A
{
	public:
		int a;

};

class B1:virtual public A
{
	public:
		int b1;
};

class B2:virtual public A
{
	public:
		int b2;
};

class C:public B1,public B2
{
	public:
		int c=9;
		void show(){cout<<c;}
};

int main()
{
	A obj;
	C ob1;
	obj.a=5;
	ob1.show();
	return 0;
}
