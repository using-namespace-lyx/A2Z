#include "ListNode.h"
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head==NULL || head->next==NULL) return head;

        ListNode*temp=NULL,*prev=NULL,*curr=head;

        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;

            prev=curr;
            curr=temp;
        }

        return prev;
    }

    ListNode* reverseList2(ListNode* head) {

        if(head==NULL || head->next==NULL) return head;

        ListNode*newHead= reverseList2(head->next);

        ListNode *temp=head->next;
        temp->next=head;
        head->next=NULL;

        return newHead;
    }
};

