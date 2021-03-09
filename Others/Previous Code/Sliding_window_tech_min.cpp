#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define UN unsigned int
#define mod 1000000007
#define F first
#define S second
#define mk make_pair
#define B(v) v.begin(), v.end()
#define BS binary_search

void f(int a[],int n,int k)
{
	deque<int>de;

	int i;
	for( i=0;i<k;i++)
	{
		while(!de.empty() && a[i]<=a[de.back()])
		{
			de.pop_back();
		}
		de.push_back(i);
	}
	//cout<<a[de.front()]<<endl;
	//cout<<i<<endl;
	for(;i<n;i++)
	{
		cout<<a[de.front()]<<" ";
		while(!de.empty() && de.front()<(i-2))
		{
			de.pop_front();
		}
		while(!de.empty() && a[i]<=a[de.back()])
		{
			de.pop_back();
		}
		de.push_back(i);
	}
	cout<<a[de.front()]<<endl;
}

int main()
{	
	int n;
	cin>>n;
	int a[n+10];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	f(a,n,3);
}