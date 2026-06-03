#include<bits/stdc++.h>
#include"ListNode.h"
using namespace std;

bool isPalindrome(ListNode* head) {

        stack<int> st;
        ListNode *curr=head;

        while(curr!=NULL)
        {
            st.push(curr->data);
            curr=curr->next;
        
        }

        curr=head;

        while(curr!=NULL)
        {
            if(st.top()!=curr->data) return false;

            st.pop();
            curr=curr->next;
        }

        return true;

    }

ListNode* reverse(ListNode *head)
    {
        if(head==NULL || head->next==NULL) return head;

        ListNode*curr=head,*prev=NULL,*temp=NULL;

        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr= temp;

        }

        return prev;

    }
    bool isPalindrome(ListNode* head) {

        ListNode *slow=head,*fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* newHead=reverse(slow->next);

        ListNode *first=head,*second=newHead;
        while(second!=NULL)
        {
            if(first->data!=second->data)
            {
                reverse(slow->next);
                return false;
            }

            first=first->next;
            second=second->next;
        }

        reverse(slow->next);
        return true;

    }