#include<bits/stdc++.h>
#include "ListNode.h"

using namespace std;

ListNode* deletebegin(ListNode* head)
{
    if(head==nullptr) return head;

    if(head->next==nullptr)
    {
        delete head;
        return nullptr;
    }

    ListNode* temp=head;
    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;

}

ListNode* deleteend(ListNode* head){
    if(head==NULL) return head;
    if(head->next==nullptr)
    {
        delete head;
        return nullptr;
    }
    ListNode* curr=head;

    while (curr->next!=nullptr)
    {
        curr=curr->next;
    }
    
    curr->back->next=nullptr;
    curr->back=nullptr;
    delete curr;
    return head;
    
}

ListNode* deleteAtPos(ListNode* head, int pos)
{
    //pos will be btw 1 to size itself assume
    if(head==NULL) return head;

    ListNode* curr=head;
    int count=1;
    while(curr!=NULL)
    {
        if(count==pos)
        break;

        curr=curr->next;
        count++;

    }

    if(curr!=NULL)
    {
        ListNode* prev=curr->back;
        ListNode* front=curr->next;

        if(prev==nullptr)
        {
            return deletebegin(head);
        }

        else if(front==nullptr)
        {
            return deleteend(head);
        }
        else
        {
            prev->next=front;
            front->back=prev;
            curr->back=nullptr;
            curr->next=nullptr;
            delete curr;
        }

    }

    return head;
}

ListNode* deleteVal(ListNode* head, int val)
{
    //pos will be btw 1 to size itself assume
    if(head==NULL) return head;

    ListNode* curr=head;
    
    while(curr!=NULL)
    {
        if(curr->data==val)
        break;

        curr=curr->next;
        

    }

    if(curr!=NULL)
    {
        ListNode* prev=curr->back;
        ListNode* front=curr->next;

        if(prev==nullptr)
        {
            return deletebegin(head);
        }

        else if(front==nullptr)
        {
            return deleteend(head);
        }
        else
        {
            prev->next=front;
            front->back=prev;
            curr->back=nullptr;
            curr->next=nullptr;
            delete curr;
        }

    }

    return head;
}
