#include<iostream>
using namespace std;
class employee
{
		int i,id,oc,ot;
	public:
		employee(){}
		void setdata(int a)
		{
			//employee e= *this;
			i=a;
			cout<<"employee no.=>"<<i<<"\n";
			cout<<"enter id=>";
			cin>>id;
			cout<<"enter overcome=>";
			cin>>oc;
			cout<<"enter overtime=>";
			cin>>ot;


			/*cout<<"employee no.=>"<<e.i<<"\n";
			cout<<"id=>"<<e.id<<"\n";
			cout<<"overcome=>"<<e.oc<<"\n";
			cout<<"overtime=>"<<e.ot<<"\n";*/
		}
		 void getdata()
		{
			
			cout<<"employee no.=>"<<i<<"\n";
			cout<<"id=>"<<id<<"\n";
			cout<<"overcome=>"<<oc<<"\n";
			cout<<"overtime=>"<<ot<<"\n";
		}
};
int main()
{
	int n=1,j=1;
	employee e;
	//for(int j=1;j<=n;j++)
	//{
		e.setdata(j);
		//employee::getdata(e);
	//}
	//for(int j=1;j<=n;j++)
	//{
		e.getdata();
	//}
	return 0;
}
