#include<iostream>
#include<stdlib.h>

using namespace std;

class stack
{
	public:
		int *a,i,n;
		stack(int n1)
		{
			a=(int*)malloc(n1*sizeof(int));
			i=0;
			n=n1;
		}
		void operator+();
		void operator-();
		void display();
};

void stack::operator+()
{
	if(i==n)
	{
		cout<<"INSERTION NOT POSSIBLE"<<"\n";
	}
	else
	{
		cout<<"ENTER YOUR ELEMENT:";
		int x;
		cin>>x;
		a[i]=x;
		i=i+1;
	}
}

void stack::operator-()
{
	if(i==0)
	{
		cout<<"DELETION NOT POSSIBLE"<<"\n";
	}
	else
	{
		i--;
	}
}

void stack::display()
{
	int k;
	cout<<"\n"<<"YOUR ARRAY ELEMENTS:";
	for(k=0;k<i;k++)
	{
		cout<<a[k]<<",";
	}
	cout<<"\n";
}

int main()
{
	int n;
	char ch;
	cout<<"ENTER THE VALUE OF TOP:";
	cin>>n;
	stack s(n);
	do{
		cout<<"\n"<<"ENTER YOUT CHOISE:\n'+' FOR INSERT\n'-' FOR DELETE\nELSE FOR EXIT\n";
	cin>>ch;
		switch(ch)
		{
			case '+' : +s;
					 s.display();
				 	 break;
			case '-' : -s;
					 s.display();
					 break;
			default  : exit(0);
		}
	}while(1);
	return 0;
}







