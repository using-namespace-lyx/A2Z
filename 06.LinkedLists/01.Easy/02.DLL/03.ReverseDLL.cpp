#include<bits/stdc++.h>
#include "ListNode.h"
using namespace std;

// Brute force
// SC: O(N)
// TC:O(2N) 
// we are changing values

ListNode* reverseBrute(ListNode*head)
{
    if(head==NULL || head->next==NULL) return head;
    stack<int> s;
    ListNode* curr=head;
    while(curr!=nullptr)
    {
        s.push(curr->data);
        curr=curr->next;
    }

    curr=head;
    while(curr!=NULL)
    {
        curr->data=s.top();
        s.pop();
        curr=curr->next;
    }

    return head;
}



ListNode* reverseBrute2(ListNode*head)
{
    if(head==NULL || head->next==NULL) return head;
    queue<int> q;
    ListNode* curr=head;

    while(curr->next!=NULL)
    {
        q.push(curr->data);
        curr=curr->next;
    }

    q.push(curr->data);

    while(curr!=NULL)
    {
        curr->data=q.front();
        q.pop();
        curr=curr->back;
    }

    return head;
}

// O(N) TC O(1) SC

ListNode* reverseLinks(ListNode* head)
{
    ListNode* curr=head,*prev=NULL;

    if(head==NULL || head->next==NULL) return head;

    while(curr!=NULL)
    {
        prev=curr->back;
        curr->back=curr->next;
        curr->next=prev;

        curr=curr->back;
    }

    return prev->back;
}