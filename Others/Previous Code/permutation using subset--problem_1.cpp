/*problem*/
// count number of permutation where difference between
//two consecutive element not greater then 1

/* INPUT*/
/*
4
1 3 5 7
*/
// OUTPUT
//24

#include <bits/stdc++.h>
using namespace std;

bool Check(int N,int pos) {return (bool)(N&(1<<pos));}
int Set(int N,int pos) {return (N|=(1<<pos));}
int reset(int N,int pos) {return N&=~(1<<pos);}


int main()
{
	int n;cin>>n;

	int dp[1<<n][n];
	memset(dp,0,sizeof(dp));
	int a[n+10];

	//base case
	for(int i=0;i<n;i++) dp[1<<i][i]=1;

	for(int i=0;i<n;i++) cin>>a[i];

	for(int b=0;b<(1<<n);b++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(abs(a[i]-a[j])>1 && (b&(1<<i)) && (b&(1<<j)))
				{
					dp[b][i]+=dp[b^(1<<j)][i];
				}
			}
		}
	}
	int re=0;
	for(int i=0;i<n;i++)
	{
		re+=dp[(1<<n)-1][i];
	}
	cout<<re<<endl;
}