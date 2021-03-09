#include <bits/stdc++.h>
using namespace std;
int we[100],cost[100];
int q,cap;
int dp[100][100];

int fn(int i,int w)
{
	int pro1,pro2;
	
	if(i==q+1) return 0;
	if(dp[i][w]!=-1)
	{
		return dp[i][w];
	}

	if(w+we[i]<=cap) 
	{
		pro1=cost[i]+fn(i+1,w+we[i]);
		
	}
	else
	{
		pro1=0;
	
	}

	pro2=fn(i+1,w);
	
	if(pro1>pro2)
	{
		dp[i][w]=pro1;
		return dp[i][w];
	}
	else
	{
		dp[i][w]=pro2;
		return dp[i][w];
	}

	//return max(pro1,pro2);

	
}

int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>q>>cap;
	for(int i=1;i<=q;i++)
	{
		cin>>we[i]>>cost[i];
	} 

	cout<<fn(1,0)<<endl;
}