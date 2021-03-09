#include <bits/stdc++.h>
using namespace std;

int main()
{
	int q=100;
	for(int i=1;i*i<q;i++)
	{
		if(q%i==0)
		{
			cout<<i<<endl;
			if(q/i!=i)
			{
				cout<<q/i<<endl;
			}
		}
	}
}