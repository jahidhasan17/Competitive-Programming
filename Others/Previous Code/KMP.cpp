#include <bits/stdc++.h>
using namespace std;

string t,p;
int a[100];

void pi_table()
{
    int k=0;
    a[0]=0;
    for(int i=1;i<p.size();)
    {
        int t=0;
        k=0;
        if(p[k]!=p[i])
        {
            a[i+1]=t;
            i++;
            continue;
        }
        while(p[k]==p[i])
        {
            t++;
            a[i+1]=t;
            i++,k++;
        }
    }
}

int main()
{
    cin>>t>>p;
    pi_table();
    p.insert(0,"0");
    int n=(int)t.size(),l=p.size();
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(t[i]!=p[j+1] && j>0) j=a[j];
        if(t[i]==p[j+1]) j++;
        if(j==l-1)
        {
            cout<<i+1-l+1<<endl;
        }
    }
}