#include<iostream>
using namespace std;
class employee
{
		int i,id,oc,ot;
	public:
		employee(){}
		void setdata(int a)
		{
			i=a;
			cout<<"employee no.=>"<<i<<"\n";
			cout<<"enter id=>";
			cin>>id;
			cout<<"enter overcome=>";
			cin>>oc;
			cout<<"enter overtime=>";
			cin>>ot;
		}
		void getdata()
		{
			cout<<"employee no.=>"<<i<<"\n";
			cout<<"\t\tid=>"<<id<<"\n";
			cout<<"\t\tovercome=>"<<oc<<"\n";
			cout<<"\t\tovertime=>"<<ot<<"\n";
		}
};
int main()
{
	int n;
	cout<<"Enter Value Of n:";
	cin>>n;
	employee e[n];
	for(int j=1;j<=n;j++)
	{
		e[j].setdata(j);
	}
	for(int j=1;j<=n;j++)
	{
		e[j].getdata();
	}
	return 0;
}
