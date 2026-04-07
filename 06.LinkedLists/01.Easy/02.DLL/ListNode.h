#include<bits/stdc++.h>
using namespace std;

class ListNode{

    public:
    int data;
    ListNode *next;
    ListNode *back;

    ListNode(int data1, ListNode* next1, ListNode* back1)
    {
        data=data1;
        next=next1;
        back=back1;
    }

};

