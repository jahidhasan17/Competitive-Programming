#include <bits/stdc++.h>
using namespace std;
#define mx 100001
int arr[mx];
int tree[mx * 3];

void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node]=arr[b];
		return;
	}
	int left=node*2;
	int right=node*2+1;
	int mid=(b+e)/2;
	init(left,b,mid);
	init(right,mid+1,e);
	tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j)
{
	if(b>j || e<i)
	{
		return 0;
	}
	if(b>=i&&e<=j)
	{
		return tree[node];
	}
	int left=2*node;
	int right=2*node+1;
	int mid=(b+e)/2;
	int p1=query(left,b,mid,i,j);
	int p2=query(right,mid+1,e,i,j);
	return p1+p2;
}

void update(int node,int b,int e,int i,int value)
{
	if(b>i||e<i)
	{
		return;
	}
	if(b>=i && e<=i)
	{
		tree[node]=value;
		return;
	}
	int left=node*2;
	int right=node*2+1;
	int mid=(e+b)/2;
	update(left,b,mid,i,value);
	update(right,mid+1,e,i,value);
	tree[node]=tree[left]+tree[right];
}

int main()
{
	///cout<<tree[1]<<endl;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	init(1,1,n);
	/*for(int i=0;i<=n*4;i++)
	{
		if(tree[i]!=0)cout<<i<<" "<<tree[i]<<endl;
	}*/
	update(1,1,n,3,10);
	cout<<query(1,1,n,2,6);
}
