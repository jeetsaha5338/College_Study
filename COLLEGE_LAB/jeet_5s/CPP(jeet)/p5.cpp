#include<iostream>
using namespace std;
class student
{
	char *name;
	char *address;
	int roll;
	int age;
	public:
		student(){}
		student(char n[],char a[],int i,int j)
		{
			name=n;
			address=a;
			roll=i;
			age=j;
		}
		~student()
		{
			cout<<"\nDealocate Memory\n";
		}
		void show()
		{
			cout<<"\nYour Roll:"<<roll<<"\nName:"<<name<<"\nAge:"<<age<<"\nAddress:"<<address;
		}
};
int main()
{
	int roll,age;
	char name[20],add[20];
	cout<<"Enter Roll,Name,Age,Address:";
	cin>>roll>>name>>age>>add;
	student s(name,add,roll,age);
	s.show();	
	return 0;
}
