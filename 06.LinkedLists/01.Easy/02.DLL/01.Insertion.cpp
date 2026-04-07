#include<bits/stdc++.h>
#include "ListNode.h"

ListNode* insertbegin(ListNode* head, int val)
{
    ListNode* temp= new ListNode(val,nullptr,nullptr);

    if(head==nullptr) return temp;

    head->back=temp;
    temp->next=head;
    return temp;
}

ListNode* insertend(ListNode* head, int val)
{
    ListNode* temp=new ListNode(val,nullptr,nullptr);

    if(head==nullptr) return temp;

    ListNode* curr=head;

    while(curr->next!=NULL)
    {
        curr=curr->next;
    }

    curr->next=temp;
    temp->back=curr;

    return head;
}

ListNode* insertBeforePos(ListNode* head, int val, int pos)
{
    ListNode* temp=new ListNode(val,nullptr,nullptr);

    // assume pos between 1 and size;
    int count=1;
    ListNode* curr=head;
    while(curr!=NULL)
    {
        if(count==pos) break;
        
        curr=curr->next;
        count++;
    }

    if(curr!=NULL)
    {
        ListNode* prev=curr->back;
        
        if(prev==nullptr)
        {
            return insertbegin(head,val);
        }
        else
        {
            prev->next=temp;
            temp->back=prev;

            temp->next=curr;
            curr->back=temp;
        }
    }

    return head;

}

ListNode* insertBeforeTarget(ListNode* head, int target, int val)
{
    // assume target is always present
    

    ListNode* temp=new ListNode(val,nullptr,nullptr);
    
    ListNode* curr=head;
    while(curr!=NULL)
    {
        if(curr->data==target) break;
        
        curr=curr->next;
        
    }

    if(curr!=NULL)
    {
        ListNode* prev=curr->back;
        
        if(prev==nullptr)
        {
            return insertbegin(head,val);
        }
        else
        {
            prev->next=temp;
            temp->back=prev;

            temp->next=curr;
            curr->back=temp;
        }
    }

    return head;




}