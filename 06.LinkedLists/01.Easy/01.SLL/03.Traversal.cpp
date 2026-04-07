#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1,Node* next1)
    {
        data=data1;
        next=next1;

    }
};

void traverse(Node* head)
{
    Node* curr=head;
    while(curr!=nullptr)
    {
        cout<<curr->data<<" ";
        curr=curr->next;

    }
}