#include<iostream>
using namespace std;
class person
{
    protected:
        string name;
        int age;
    public:
        void getdata()
        {
            cout<<"Enter the name: ";
            cin>>name;
            cout<<"Enter the age: ";
            cin>>age;
        }
        void showdata()
        {
            cout<<"Name: "<<name<<"\n";
            cout<<"Age: "<<age<<"\n";
        }
        void print_address()
        {
            cout<<"\n The address of object is "<<this;
        }
};
class student: public person
{
    private:
        int ID;
    public:
        void getdata()
        {
            cout<<"Enter the information for student"<<"\n";
            person::getdata();
            cout<<"Enter Student ID: "<<"\n";
            cin>>ID;
        }
        void showdata()
        {
            cout<<"The information on student is"<<"\n";
            person::showdata();
            cout<<"ID : "<<ID<<"\n";
        }
};


class employee: public person

{
        private:
            float salary;
        public:
            void getdata()
            {
                cout<<"Enter the information for employee"<<"\n";
                person::getdata();
                cout<<"Enter Employee's salary: ";
                cin>>salary;
            }
            void showdata()
            {
                cout<<"The information on employee is"<<"\n";
                person::showdata();
                cout<<"Salary: "<<salary<<endl;
            }
};
int main()
{
    student s;
    employee e;
    s.getdata();
    e.getdata();
    s.showdata();
    e.showdata();
    s.print_address();
    e.print_address();
    return 0;
}
