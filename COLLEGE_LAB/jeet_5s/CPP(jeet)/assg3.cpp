#include<iostream>

using namespace std;

int insertion();

int deletion();

int search();

int display();

int *a,i,n;

int main()
{
	int ch,b;
	i=0;
	cout<<"ENTER NO. OF ELEMENT:";
	cin>>n;
	a=(int*)malloc(n*sizeof(int));
	
	do{
		cout<<"\n"<<"ENTER YOUT CHOISE:\n1 FOR INSERT\n2 FOR DELETE\n3 FOR SEARCH\n4 FOR DISPLAY\n5 FOR EXIT\n";
	cin>>ch;
		switch(ch)
		{
			case 1 : insertion();
				 	 break;
			case 2 : deletion();
					 break;
			case 3 : search();
				 	 break;
			case 4 : display();
				 	 break;
		}
	}while(ch<5);
	return 0;
}

int insertion()
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
		return 0;
}

int deletion()
{
	if(i==0)
	{
		cout<<"DELETION NOT POSSIBLE"<<"\n";
	}
	else
	{
		cout<<"ENTER THE INDEX:";
		int x,y;
		cin>>x;
		for(y=x;y<n-1;y++)
		{
			a[y]=a[y+1];
		}
		i--;
		return 0;
	}
}

int search()
{
	int k,f=0,m;
	cout<<"ENTER SEARCHING ELEMENT:";
	cin>>m;
	for(k=0;k<i;k++)
	{
		if(a[k]==m)
		{
			f=1;
			break;
		}
	}
	if(f==1)
	{
		cout<<"SEARCHING ELEMENT FOUND AT "<<k;
	}
	else
	{
		cout<<"SEARCHING ELEMENT NOT FOUND:";
	}
	return 0;
}

int display()
{
	int k;
	cout<<"\n"<<"YOUR ARRAY ELEMENTS:";
	for(k=0;k<i;k++)
	{
		cout<<a[k]<<",";
	}
	return 0;
}
		
