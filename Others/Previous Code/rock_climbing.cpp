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
int h,w;
int a[100][100];
int dp[100][100];
int f(int i,int j)
{
	if(dp[i][j]!=-1) return dp[i][j];
	if(i<0||j<0||i>h||j>w) return 0;
	int r=-1000;
	r=max(r,a[i][j]+f(i+1,j));
	r=max(r,a[i][j]+f(i+1,j+1));
	r=max(r,a[i][j]+f(i+1,j-1));
	return dp[i][j]=r;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>h>>w;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<f(0,0)<<endl;
}
/*
3 3
-1 2 5
4 -2 3
1 2 10
*/