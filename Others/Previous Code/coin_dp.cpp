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
int n;
int a[1000];
int make;
int dp[100][100];
int f(int i,int amount)
{
	if(i>=n)
	{
		if(amount==make) return 1;
		else return 0;
	}
	if(dp[i][amount]!=-1) return dp[i][amount];
	int ret1=0,ret2=0;
	if(amount+a[i]<=make)
	{
		ret1=f(i,amount+a[i]);
	}
	ret2=f(i+1,amount);
	return dp[i][amount]=ret1|ret2;
}

int main()
{	
	memset(dp,-1,sizeof(dp));
	cin>>n>>make;
	for(int i=0;i<n;i++) cin>>a[i];	
	cout<<f(0,0)<<endl;
}		