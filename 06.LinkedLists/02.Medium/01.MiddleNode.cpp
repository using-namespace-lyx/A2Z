#include "ListNode.h"
#include <bits/stdc++.h>

using namespace std;

// ListNode class represents a ListNode in a linked list


// Function to find the middle
// ListNode of a linked list
ListNode *findMiddle(ListNode *head) {
    // If the list is empty or has only
    // one element, return the head as 
    // it's the middle.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* temp = head;
    int count = 0;

    // Count the number of ListNodes in the linked list.
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Calculate the position of the middle ListNode.
    int mid = count / 2 + 1;
    temp = head;

    // Traverse to the middle ListNode by moving
    // temp to the middle position.
    while (temp != nullptr) {
        mid = mid - 1;

        // Check if the middle
        // position is reached.
        if (mid == 0){
            // break out of the loop
            // to return temp
            break;
        }
        // Move temp ahead
        temp = temp->next;
    }

    // Return the middle ListNode.
    return temp;
}

ListNode* findMiddle(ListNode*head)
{
    if(head==NULL || head->next==NULL) return head;

    ListNode *slow=head,*fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}