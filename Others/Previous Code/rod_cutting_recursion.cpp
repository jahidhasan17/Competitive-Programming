//TIME COMPLEXITY n^n
#include <bits/stdc++.h>
using namespace std;

int n,rod;
int a[100],b[200];

int ff(int i,int si,int val)
{
	if(i>=n || si>=rod)
	{
		if(si==rod)
		{
			//cout<<val<<endl;
			return val;
		}
		else return 0;
	}
	int p1=ff(i+1,si,val);
	int p2=ff(i,si+a[i],val+b[i]);
	return max(p1,p2);
}


int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=1;i<=10;i++)
	{
		rod=i;
		cout<<ff(0,0,0)<<endl;
	}
}