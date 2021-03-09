#include <bits/stdc++.h>
using namespace std;

const int infinity=1000000;
int cost[100][100];
int e,n;

void floyd()
{
    int i,j,k;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(cost[i][j]>cost[i][k]+cost[k][j])
                {
                    cost[i][j]=cost[i][k]+cost[k][j];

                }
                cout<<cost[i][j]<<" ";
            }
        }
    }
}

int main()
{
    cin>>e>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) cost[i][j]=0;
            else
            cost[i][j]=1000;
        }
    }

    for(int i=0;i<e;i++)
    {
        int node1,node2,w;
        cin>>node1>>node2>>w;
        cost[node1][node2]=w;
        cost[node2][node1]=w;
    }

    floyd();
    for(int i=0;i<n;i++)
    {
        cout<<"3--"<<i<<" "<<cost[3][i]<<endl;
    }
    return 0;
}
