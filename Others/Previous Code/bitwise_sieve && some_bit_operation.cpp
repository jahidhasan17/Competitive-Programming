#include <bits/stdc++.h>
using namespace std;

bool Check(int N,int pos) {return (bool)(N&(1<<pos));}
int Set(int N,int pos) {return N|=(1<<pos);}

int a[1000000];

int main()
{
	int n;
	cin>>n;

	for(int i=3;i*i<=n;i+=2)
	{
		if(Check(a[i/32],i%32)==0)
		{
			for(int j=i*i;j<=n;j+=(2*i))
			{
				a[j/32]=Set(a[j/32],j%32);
			}
		}
	}
	for(int i=3;i<=n;i+=2)
	{
		if(i==3) cout<<2<<endl;
		if(Check(a[i/32],i%32)==0)
		{
			cout<<i<<endl;
		}
	}

	int number=5,q=0;
	//TO SET qth BIT IS ON
	number|=(1<<q);
	cout<<number<<endl; //5

	number=5;
	//TO SET qth BIT IS OFF
	number&=~(1<<q);
	cout<<number<<endl; //4

	number=5;
	//TO TOGGLE qth BIT
	number^=(1<<q);
	cout<<number<<endl; //4

	number=5;
	//TO CHECK qth BIT IS ON OR OFF
	cout<<(bool)(number&(1<<q))<<endl; //1
}