#include<bits/stdc++.h>
using namespace std;
int inf=1<<31;
int arr[100010];
int bst[4*100010];

void insert(int val)
{
    int curr_index=0;
    while(bst[curr_index]!=inf)
    {
        if(bst[curr_index]<val)curr_index=2*curr_index+2;
        else curr_index=2*curr_index+1;
    }
    bst[curr_index]=val;
}

void inOrderTraverse(int index)
{
    if(bst[index]!=inf)
    {
        inOrderTraverse(2*index+1);
        cout<<index<<' '<<bst[index]<<endl;
        inOrderTraverse(2*index+2);
    }
}
void preOrderTraverse(int index)
{
    if(bst[index]!=inf)
    {
        cout<<index<<' '<<bst[index]<<endl;
        preOrderTraverse(2*index+1);
        preOrderTraverse(2*index+2);
    }
}

void postOrderTraverse(int index)
{
    if(bst[index]!=inf)
    {
        postOrderTraverse(2*index+1);
        postOrderTraverse(2*index+2);
        cout<<index<<' '<<bst[index]<<endl;
    }
}
int minimumValue()
{
    int i;
    for(i=0;bst[2*i+1]!=inf;i=2*i+1);
    return bst[i];
}
int index_of_inorder_successor(int i)
{
    for(i=2*i+2;bst[2*i+1]!=inf;i=2*i+1);
    return i;
}
void copy(int i,int j)
{
    if(bst[j]!=inf)
    {
        swap(bst[i],bst[j]);
        bst[j]=inf;
        copy(2*i+1,2*j+1);
        copy(2*i+2,2*j+2);
    }
}
void del(int i)
{
    if(bst[2*i+1]==inf && bst[2*i+2]==inf)bst[i]=inf;
    else if(bst[2*i+1]==inf)copy(i,2*i+2);
    else if(bst[2*i+2]==inf)copy(i,2*i+1);
    else{
        int p=index_of_inorder_successor(i);
        swap(bst[p],bst[i]);
        del(p);
    }
}


int main()
{
    for(int i=0;i<4*100010;i++)bst[i]=inf;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        insert(arr[i]);
    }
    for(int i=0;i<4*100010;i++)
    {
        if(bst[i]!=inf)cout<<i<<' '<<bst[i]<<endl;
    }
    cout<<endl;
    //inOrderTraverse(0);
    //preOrderTraverse(0);
    postOrderTraverse(0);
    cout<<"\n\n\n"<<minimumValue()<<endl;
}
