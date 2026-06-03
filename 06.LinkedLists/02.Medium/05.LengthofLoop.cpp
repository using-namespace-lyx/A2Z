#include<bits/stdc++.h>
#include "ListNode.h"
using namespace std;

int findLengthOfLoop(ListNode *head) {

        ListNode *curr=head;
        unordered_map<ListNode*, int> mpp;
        int count=1;

        while(curr!=NULL)
        {
            if(mpp.find(curr)!=mpp.end())
            {
                return count-mpp[curr];

            }

            mpp[curr]=count++;
            curr=curr->next;

        }

        return 0;

    }

class Solution {

    private:
    int loopLength(ListNode*fast, ListNode*slow)
    {
        fast=fast->next;
        int count=1;
        while(slow!=fast)
        {
            fast=fast->next;
            count++;
        }

        return count;
    }
public:
    
    int findLengthOfLoop(ListNode *head) {

            ListNode *slow=head,*fast=head;

            while(fast!=NULL && fast->next!=NULL)
            {
                slow=slow->next;
                fast=fast->next->next;

                if(slow==fast) return loopLength(slow,fast);
            }

            return 0;

    }
};