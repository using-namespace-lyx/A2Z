#include<bits/stdc++.h>
#include "ListNode.h"

ListNode* insertBegin(ListNode* head, int x)
{
    ListNode* temp= new ListNode(x,head);
    return temp;
}

ListNode* insertEnd(ListNode* head, int x)
{
    ListNode* temp= new ListNode(x,nullptr);
    ListNode* curr=head;
    if(curr==nullptr) return temp;
    while(curr->next!=nullptr)
    {
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}

ListNode* insertAtIndex(ListNode* head, int x, int pos)
{
    // assume pos from 1

   

    if(pos==1)
    {
        return new ListNode(x,head);
    }

    ListNode* prev=nullptr, *curr=head;
    int count=1;
    while(curr!=nullptr)
    {
        if(count==pos)
        {
            ListNode* temp=new ListNode(x,nullptr);
            prev->next=temp;
            temp->next=curr;
            return head;

        }
        prev=curr;
        curr=curr->next;
        count++;
    }

    if(count==pos)
    {
        ListNode* temp=new ListNode(x,nullptr);
            prev->next=temp;
            temp->next=curr;
    }

    return head;

}


ListNode* insertAtIndex(ListNode* head, int x, int pos)
{
    // assume pos from 1

   

    if(pos==1)
    {
        return new ListNode(x,head);
    }

    ListNode* prev=nullptr, *curr=head;
    int count=1;
    while(curr!=nullptr)
    {
        if(count==pos)
        {
            ListNode* temp=new ListNode(x,nullptr);
            prev->next=temp;
            temp->next=curr;
            return head;

        }
        prev=curr;
        curr=curr->next;
        count++;
    }

    if(count==pos)
    {
        ListNode* temp=new ListNode(x,nullptr);
            prev->next=temp;
            temp->next=curr;
    }

    return head;

}