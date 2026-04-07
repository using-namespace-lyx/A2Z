#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node*next1)
    {
        data=data1;
        next=next1;
    }
};

int main()
{
    int arr[]={1,2,3,4};

    Node* head= new Node(arr[0],nullptr);

    Node* mover=head;

    for(int i=1;i<4;i++)
    {
        Node* temp=new Node(arr[i],nullptr);
        mover->next=temp;
        mover=mover->next;
    }
}