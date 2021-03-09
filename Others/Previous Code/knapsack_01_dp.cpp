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
int n,w;
int a[1000];
int weight[1000],cost[1000];
int dp[1000][1000];
int f(int i,int ww)
{
	if(dp[i][ww]!=-1)return dp[i][ww];
	if(i==n) return 0;
	int pro1=0,pro2=0;

	if((ww+weight[i])<=w)
	{
		pro1=cost[i]+f(i+1,ww+weight[i]);
	}
	else
	{
		pro1=0;
	}
	pro2=f(i+1,ww);
	dp[i][ww]=max(pro1,pro2);
	return max(pro1,pro2);
}

int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>n>>w;
	for(int i=0;i<n;i++) cin>>weight[i]>>cost[i];
	cout<<f(0,0)<<endl;
}	