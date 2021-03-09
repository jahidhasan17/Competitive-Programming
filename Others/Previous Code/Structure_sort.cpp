#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pr printf
#define sc scanf

struct st
{
	int aa;
	int bb;
};

bool com(st a,st b)
{
	if(a.aa==b.aa) return a.bb<b.bb;
	return a.aa<b.aa;
}

int main()
{
	int n;
	cin>>n;
	//int a[n];
	struct st a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i].aa;
		cin>>a[i].bb;
	}
	sort(a,a+n,com);
	for(int i=0;i<n;i++)
	{
		cout<<a[i].aa<<" "<<a[i].bb<<endl;
	}

}
/*
5
2 3
3 4
1 2
6 3
6 2
*/