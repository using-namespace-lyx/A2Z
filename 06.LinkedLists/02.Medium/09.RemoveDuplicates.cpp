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
    ListNode * removeDuplicates(ListNode *head) {

        ListNode* curr=head;

        while(curr!=NULL)
        {
            ListNode* temp=curr->next;

            while(temp!=NULL && temp->val==curr->val)
            {
                ListNode* nextNode=temp;
                temp=temp->next;
                delete nextNode;

            }
            curr->next=temp;
            if(temp) temp->prev=curr;

            curr=curr->next;
        }

        return head;



    }
};