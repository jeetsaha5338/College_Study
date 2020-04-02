#include<iostream>
#define MAX 100
using namespace std;
template<class T>
class STACK
{
        int n,i=0;
        T a[MAX];
    public:
        STACK(int i) {n=i;}
    void exc()
    {
        int ch;
        do{
		cout<<"\n"<<"ENTER YOUT CHOISE:\n1 FOR INSERT\n2 FOR DELETE\n3 FOR DISPLAY\n4 FOR EXIT\n";
        cin>>ch;
            switch(ch)
            {
                case 1 : this->insertion();
                        break;
                case 2 : this->deletion();
                        break;
                case 3 : this->display();
                        break;
            }
        }while(ch<4);
    }
    void insertion()
    {
        if(i==n)
        {
            cout<<"INSERTION NOT POSSIBLE"<<"\n";
        }
        else
        {
            cout<<"ENTER YOUR ELEMENT:";
            T x;
            cin>>x;
            a[i++]=x;
        }
    }
    void deletion()
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
    void display()
    {
        int k;
        cout<<"\n"<<"YOUR ARRAY ELEMENTS:";
        for(k=0;k<i;k++)
        {
            cout<<a[k]<<",";
        }
        cout<<"\n";
    }
};
int main()
{
    int n;
    cout<<"ENTER N:";
    cin>>n;
    STACK <char>s(n);//instade of char you may write int/float.
    s.exc();
}

