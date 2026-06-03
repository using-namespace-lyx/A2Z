#include<bits/stdc++.h>
#include"ListNode.h"
using namespace std;

// Brute would be to take 2 queues and put odd and even accordingly and then put the odd and even values as a group
class Solution 
{
    public:
        ListNode* oddEvenList(ListNode* &head) 
        {
            //your code goes here

            ListNode* odd= new ListNode(-1,nullptr),*even=new ListNode(-1,nullptr),*temp1=odd,*temp2=even,*temp=head;

            int count=1;

            while(temp!=NULL)
            {
                if(count&1)
                {
                    temp1->next=temp;
                    temp1=temp1->next;
                }

                else
                {
                    temp2->next=temp;
                    temp2=temp2->next;
                }

                count++;
                temp=temp->next;
            }

            temp1->next=even->next;
            temp2->next=NULL;

            return odd->next;

        }

};
