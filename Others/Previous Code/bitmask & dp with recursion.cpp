#include <bits/stdc++.h>
using namespace std;

bool Check(int N,int pos) {return (bool)(N&(1<<pos));}
int Set(int N,int pos) {return (N|=(1<<pos));}
int reset(int N,int pos) {return N&=~(1<<pos);}

int dp[1<<15];
int n;
int a[16][16];
int qq=0;
int call(int mask)
{
	if(mask==(1<<n)-1) return 0;
	if(dp[mask]!=-1) return dp[mask];
	int to=1e9;
	for(int i=0;i<n;i++)
	{
		if(Check(mask,i)==0)
		{
			int price=a[i][i];
			for(int j=0;j<n;j++)
			{
				if(i!=j && Check(mask,j)==1) price+=a[j][i];
			}
			to=min(to,price+call(Set(mask,i)));
		}
	}
	qq++;
	return dp[mask]=to;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0; i<n; i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<call(0)<<endl;
}