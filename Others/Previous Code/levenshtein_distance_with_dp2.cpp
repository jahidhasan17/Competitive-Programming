#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int l1,l2;
int dp[100][100];
int editdis(int i,int j)
{
	if(i==0) return j;
	if(j==0) return i;
	if(dp[i][j]!=-1) return dp[i][j];
	if(s1[i-1]==s2[j-1])
	{
		return dp[i-1][j-1]=editdis(i-1,j-1);
	}
	return dp[i-1][j-1]=1+min(editdis(i-1,j),min(editdis(i,j-1),editdis(i-1,j-1)));
}

int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>s1>>s2;
	l1=s1.size();
	l2=s2.size();
	cout<<editdis(l1,l2)<<endl;
}