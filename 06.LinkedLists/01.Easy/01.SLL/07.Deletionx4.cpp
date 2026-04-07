#include<bits/stdc++.h>
#include "ListNode.h"

ListNode* deletebegin(ListNode* head)
{
    if(head==nullptr) return nullptr;
    ListNode* newHead=head->next;
    delete head;
    return newHead;
}

ListNode* deleteEnd(ListNode* head)
{
    if(head==nullptr ) return head;
    if(head->next==nullptr)
    {
        delete head;
        return nullptr;
    }
    ListNode *prev=nullptr, *curr=head;
    while(curr->next!=nullptr)
    {
        prev=curr;
        curr=curr->next;
    }

    prev->next=nullptr;
    delete curr;

    return head;

}

ListNode* deleteAtPos(ListNode* head, int pos)
{
    // assume pos starts from 1

    if(head==nullptr) return head;

    if(pos==1)
    {
        ListNode* temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    ListNode* prev=nullptr,*curr=head;
    int count=1;
    while(curr!=nullptr)
    {
        if(count==pos)
        {
            prev->next=curr->next;
            delete curr;
            break;

        }
        prev=curr;
        curr=curr->next;
        count++;
    }
   

    return head;
    

}

ListNode* deletValueFirst(ListNode* head, int val)
{
    if(head==nullptr) return head;

    if(head->data==val)
    {
        ListNode* temp=head->next;
        delete head;
        return temp;
    }

    ListNode *prev=nullptr, *curr=head;

    while(curr!=nullptr)
    {
        if(curr->data==val)
        {
            prev->next=curr->next;
            delete curr;
            break;

        }
        prev=curr;
        curr=curr->next;
    }



    return head;


}

ListNode* deletValueAll(ListNode* head, int val)
{
    

    while(head!=nullptr&& head->data==val)
    {
        ListNode* temp=head;
        head=head->next;
        delete temp;
        
    }
    if(head==nullptr) return head;

    ListNode *prev=nullptr, *curr=head;

    while(curr!=nullptr)
    {
        if(curr->data==val)
        {
            prev->next=curr->next;
            delete curr;
            
            curr=prev->next;
            continue;

        }
        prev=curr;
        curr=curr->next;
    }



    return head;


}