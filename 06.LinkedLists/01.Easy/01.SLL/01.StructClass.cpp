#include<bits/stdc++.h>
using namespace std;

struct Node1
{
    int data;
    Node1* next;

    Node1(int data1, Node1* next1)
    {
        data=data1;
        next=next1;
    }

    Node1(int data1)
    {
        data=data1;
        next=nullptr;
    }
};

// simply replace struct by class
class Node2
{
    public:
    int data;
    Node2* next;

    Node2(int data1, Node2* next1)
    {
        data=data1;
        next=next1;
    }

    Node2(int data1)
    {
        data=data1;
        next=nullptr;
    }

};

int main()
{
    Node1 node1 = Node1(23,nullptr);
    // It directly creates a structure instance
    Node1* node11 =new Node1(24,nullptr);
    // It creates a structure ptr , the new keyword

    Node2 node2=Node2(3);
    Node2 *node21 =new Node2(5,nullptr);

    cout<<node1.data;
    cout<<node11->data;
    cout<<node2.data;
    cout<<node21->data;
}