#include <bits/stdc++.h>
using namespace std;


struct node
{
    int roll;
    node *next,*prev;
};

node *root=NULL,*tail=NULL;

void add(int roll)
{
    node *current_node=root;
    if(root==NULL)
    {
        root=new node();
        root->roll=roll;
        root->next=NULL;
        root->prev=NULL;
        tail=root;
        return;
    }
    node *newnode=new node();
    newnode->roll=roll;
    newnode->next=NULL;
    newnode->prev=tail;
    tail->next=newnode;
    tail=newnode;
}

void print_from_first()
{
    node *newnode=root;
    while(newnode->next!=NULL)
    {
        cout<<newnode->roll<<endl;
        newnode=newnode->next;
    }
    cout<<newnode->roll<<endl;
}

void print_from_last()
{
    node *current_node=tail;
    while(current_node->prev!=NULL)
    {
        cout<<current_node->roll<<endl;
        current_node=current_node->prev;
    }
    cout<<current_node->roll<<endl;
}

void erase(int roll)
{
    node *current_node=root;
    node *previous_node=NULL;
    bool bo=1;
    while(current_node->roll!=roll && current_node->next!=NULL)
    {
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
        root->prev=NULL;
        current_node=NULL;
    }
    else
    {
        previous_node->next=current_node->next;
        current_node->next->prev=previous_node;
    }
}

void add_intermediate_from_first(int roll1,int roll2)
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
    newnode->prev=current_node;
    temp->prev=newnode;
}

int main()
{
    for(int i=0;i<5;i++)
    {
        add(i+1);
    }
    erase(2);
    add_intermediate_from_first(3,8);
    print_from_first();
    cout<<"\n";
    print_from_last();
}
