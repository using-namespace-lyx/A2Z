#include<bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode *findStartingPoint(ListNode *head) {

        ListNode* temp=head;
        unordered_map<ListNode*,int> mpp;

        while(temp!=NULL)
        {
            if(mpp.find(temp)!=mpp.end())
            {
                return temp;
            }
            mpp[temp]=1;
            temp=temp->next;
        }

        return NULL;

    }

ListNode *findStartingPoint(ListNode *head) {

        ListNode* slow=head,*fast=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast)
            {
                slow=head;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;

                    
                }
                return slow;
            }
        }

        return NULL;

    }


