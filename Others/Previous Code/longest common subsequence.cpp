#include <bits/stdc++.h>
using namespace std;
char s1[1000],s2[1000];
int dp[1000][1000];
bool visit[1000][1000];
int l1,l2,k=-1;
int lcs(int i,int j)
{
	if(s1[i]=='\0'||s2[j]=='\0') return 0;
	int ans=0;
	if(visit[i][j]) return dp[i][j];
	if(s1[i]==s2[j])
	{
		ans=lcs(i+1,j+1)+1;
	}
	else
	{
		ans=max(lcs(i+1,j),lcs(i,j+1));
	}
	visit[i][j]=1;
	dp[i][j]=ans;
	return ans;
}
string ss="";
void print_lcs(int i,int j)
{
	if(s1[i]=='\0'||s2[j]=='\0') return;
	if(s1[i]==s2[j])
	{
		ss+=s1[i];
		print_lcs(i+1,j+1);
	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1]) print_lcs(i+1,j);
		else print_lcs(i,j+1);
	}
}

int main()
{
	scanf("%s",s1);
	scanf("%s",s2);
	l1=strlen(s1);
	l2=strlen(s2);
	cout<<lcs(0,0)<<endl;
	print_lcs(0,0);
	cout<<ss<<endl;
}
/*
input
HELLOM
HMLLD

output
3
HLL

*/