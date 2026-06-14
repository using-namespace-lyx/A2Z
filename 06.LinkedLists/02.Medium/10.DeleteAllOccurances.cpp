#include<bits/stdc++.h>
#include "ListNode.h"
using namespace std;

/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {

        ListNode* curr=head,*back=NULL,*front=NULL;
        while(curr!=NULL)
        {
            if(curr->val==target)
            {
                ListNode* temp=curr;

                back=curr->prev;
                front=curr->next;

                if(back) back->next=front;
                if(front) front->prev=back;

                if(curr==head) head=head->next;

                 curr=curr->next;

                
                delete temp;
                continue;
                
                

            }

            curr=curr->next;
            



        }

        return head;

    }
};