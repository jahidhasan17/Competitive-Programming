#include <bits/stdc++.h>
using namespace std;
int tree[100];

void update(int idx,int x,int n)
{
	while(idx<=n)
	{
		tree[idx]+=x;
		idx+=idx&(-idx);
	}
}

int query(int idx)
{
	int sum=0;
	while(idx>0)
	{
		sum+=tree[idx];
		//cout<<sum<<endl;
		idx-=idx&(-idx);
	}
	return sum;
}

int main()
{
	for(int i=1;i<=100;i++)
	{
		tree[i]=0;
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int q;
		cin>>q;
		update(i,q,n);
	}
	//for(int i=1;i<=n;i++) cout<<tree[i]<<endl;
	cout<<"sum of all element between 1 to 8: ";
	cout<<query(8)<<endl;
	return 0;
}