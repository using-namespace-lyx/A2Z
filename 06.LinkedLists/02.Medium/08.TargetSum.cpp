#include<bits/stdc++.h>
#include "ListNode.h"
using namespace std;

/*
class ListNode {
public:
    int data;
    ListNode* next;
    ListNode* prev; 

    ListNode(int dataue) : data(dataue), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        // Your code goes here
        vector<vector<int>> res;

        for(ListNode* temp1=head;temp1!=NULL;temp1=temp1->next)
        {
            
            

            for(ListNode* temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
            {
                if(temp1->data+temp2->data==target)
                {
                    res.push_back({temp1->data,temp2->data});
                }
                else if(temp1->data+temp2->data>target)
                break;
            }
        }

        return res;
    }
};

/*
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        // Your code goes here

        ListNode *low=head,*high=head;
        vector<vector<int>> res;
        if(head==NULL) return res;
        while(high->next!=NULL) high=high->next;
        

        while( low->val < high->val)
        {
            int sum=low->val+high->val;
            if(sum==target)
            {
                res.push_back({low->val,high->val});
                low=low->next;
                high=high->prev;
            }
            else if(sum<target)
            {
                low=low->next;

            }
            else
            {
                high=high->prev;
            }
        }

        return res;
    }
};