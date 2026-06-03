#include<bits/stdc++.h>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_map<ListNode*,int> mpp;

        ListNode*temp=head;

        while(temp!=NULL)
        {
            if(mpp.find(temp)!=mpp.end()) return true;

            mpp[temp]=1;
            temp=temp->next;
        }

        return false;

    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow=head,*fast=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast) return true;
        }

        return false;

    }
};