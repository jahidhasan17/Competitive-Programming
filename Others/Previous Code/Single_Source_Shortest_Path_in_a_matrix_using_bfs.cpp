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
//#define int ll
char edge[1005][1005];
int d[1005][1005];
int n,m,q;
bool bo[1005][1005];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
void bfs(int i,int j)
{
	d[i][j]=0;
	pair<int,int>p1;
	p1={i,j};
	queue<pair<int,int>>q;
	q.push(p1);
	int ii,jj;
	bo[i][j]=1;
	while(!q.empty())
	{
		p1=q.front();
		q.pop();
		i=p1.F;
		j=p1.S;
		for(int k=0;k<4;k++)
		{
			ii=i+dx[k];
			jj=j+dy[k];
			if(ii>=0&&ii<n&&jj>=0&&jj<m&&bo[ii][jj]==0&&edge[ii][jj]=='O')
			{
				d[ii][jj]=d[i][j]+1;
				q.push({ii,jj});
				bo[ii][jj]=1;
			}
		}
	}
}

int main()
{
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>edge[i][j];
			d[i][j]=10000;
		}
	}
	
	int x,y;
	cin>>x>>y;
	bfs(x-1,y-1);
	for(int i=0;i<q;i++)
	{
		int q,w;
		cin>>q>>w;
		int ww=d[q-1][w-1];
		if(ww==10000) cout<<-1<<endl;
		else cout<<ww<<endl;
	}
}

/*
3 3 2
O*O
OOO
*OO
2 2
1 1
1 2
*/