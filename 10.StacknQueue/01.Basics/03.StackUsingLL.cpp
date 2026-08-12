#include<bits/stdc++.h>
using namespace std;


class ListNode
{
    public:
    int value;
    ListNode* next;

    ListNode(int val)
    {
        value=val;
        next=NULL;
    }

    
};

class LinkedListStack {
public:
    ListNode *topp;
    

    LinkedListStack() {
        topp=NULL;


    }
    
    void push(int x) {

        ListNode* temp =new ListNode(x);

        temp->next=topp;
        topp=temp;

   
    }
    
    int pop() {

        if(topp==NULL) return -1;
        
        int el=topp->value;

        ListNode* temp=topp;

        topp=topp->next;

        delete temp;

        return el;
  
    }
    
    int top() {

        if(topp==NULL) return -1;

        return topp->value;
    
    }
    
    bool isEmpty() {

        return topp==NULL;
  
    }
};