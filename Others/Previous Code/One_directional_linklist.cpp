#include <bits/stdc++.h>
using namespace std;


struct node
{
    int roll;
    node *next;
};

node *root=NULL;

void add(int roll)
{
    node *current_node=root;
    if(root==NULL)
    {
        root=new node();
        root->roll=roll;
        root->next=NULL;
        return;
    }
    while(current_node->next!=NULL)
    {
        current_node=current_node->next;
    }
    node *newnode=new node();
    newnode->roll=roll;
    newnode->next=NULL;
    current_node->next=newnode;
    return;
}

void print()
{
    node *newnode=root;
    while(newnode->next!=NULL)
    {
        cout<<newnode->roll<<endl;
        newnode=newnode->next;
    }
    cout<<newnode->roll<<endl;
}

void erase(int roll)
{
    node *current_node=root;
    node *previous_node=NULL;
    bool bo=1;
    while(current_node->roll!=roll && current_node->next!=NULL)
    {
        //cout<<1<<endl;
        previous_node=current_node;
        current_node=current_node->next;
    }
    if(current_node->roll!=roll) bo=0;
    if(!bo)
    {
        cout<<"THE VALUE IS NOT IN THE LIST"<<endl;
        return;
    }
    if(current_node==root)
    {
        root=root->next;
        current_node=NULL;
    }
    else
    {
        previous_node->next=current_node->next;
    }
}

void add_intermediate(int roll1,int roll2)
{
    node *current_node=root;
    while(current_node->roll!=roll1)
    {
        current_node=current_node->next;
    }
    node *temp=current_node->next;
    node *newnode=new node();
    current_node->next=newnode;
    newnode->roll=roll2;
    newnode->next=temp;
}

int main()
{
    for(int i=0;i<5;i++)
    {
        add(i+1);
    }
    erase(2);
    add_intermediate(3,8);
    print();
}
/*OUTPUT
1
3
8
4
5
*/