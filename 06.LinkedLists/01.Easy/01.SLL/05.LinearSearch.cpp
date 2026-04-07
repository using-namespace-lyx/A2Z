#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1)
    {
        data=data1;
        next=next1;
    }
};

int search(Node* head, int k)
{
    Node*curr=head;
    int index=0;
    while(curr!=nullptr)
    {
        if(curr->data==k) return index;
        curr=curr->next;
        index++;
    }

    return -1;
}