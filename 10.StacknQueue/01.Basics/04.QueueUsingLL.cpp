#include<bits/stdc++.h>
using namespace std;



class ListNode
{
    public:
    int value;
    ListNode *next;

    ListNode(int val)
    {
        value=val;
        next=NULL;
    }
};

class LinkedListQueue {
public:

    ListNode* front,*rear;

    LinkedListQueue() {
        front=rear=NULL;
    }
    
    void push(int x) {

        ListNode *temp=new ListNode(x);
        
        if(front==NULL && rear==NULL)
        {
            front=rear=temp;
            return;

        }

        rear->next=temp;
        rear=rear->next;

   
    }
    
    int pop() {

        if(front==NULL) return -1;

        int el=front->value;

        ListNode* temp=front;

        if(front==rear)
        {
            rear=NULL;
            
        }

        front=front->next;

        delete temp;

        return el;
  
    }
    
    int peek() {

        if(front==NULL) return -1;

        return front->value;
    
    }
    
    bool isEmpty() {

        return (front==NULL);
  
    }
};