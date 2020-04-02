#include<iostream>

using namespace std;

int main()
{
	int i,j,n;
	cout<<"ENTER THE LIMIT:";
	cin>>n;
	i=2;
	cout<<"PRIME NUMBERS ARE:";
	while(i<=n)
	{
		int f=0;
		for(j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			cout<<i<<",";
		}
		i++;
	}
	return 0;
}
			
