#include<bits/stdc++.h>
#include "ListNode.h"
using namespace std;

// Insert at beginning
ListNode* insertBegin(ListNode* head, int x)
{
    return new ListNode(x, head);
}

// Insert at end
ListNode* insertEnd(ListNode* head, int x)
{
    ListNode* temp = new ListNode(x, nullptr);

    // Empty list
    if(head == nullptr)
        return temp;

    ListNode* curr = head;

    while(curr->next != nullptr)
    {
        curr = curr->next;
    }

    curr->next = temp;

    return head;
}

// Insert at position (1-based indexing)
ListNode* insertAtIndex(ListNode* head, int x, int pos)
{
    // Invalid position
    if(pos <= 0)
        return head;

    // Insert at beginning
    if(pos == 1)
    {
        return new ListNode(x, head);
    }

    ListNode* prev = nullptr;
    ListNode* curr = head;

    int count = 1;

    while(curr != nullptr)
    {
        if(count == pos)
        {
            ListNode* temp = new ListNode(x, curr);

            prev->next = temp;

            return head;
        }

        prev = curr;
        curr = curr->next;

        count++;
    }

    // Insert at end if pos = length+1
    if(count == pos)
    {
        prev->next = new ListNode(x, nullptr);

        return head;
    }

    // Position greater than valid range
    return head;
}

// Insert AFTER first occurrence of value
ListNode* insertAfterValue(ListNode* head, int x, int val)
{
    ListNode* curr = head;

    while(curr != nullptr)
    {
        if(curr->data == val)
        {
            ListNode* temp = new ListNode(x, curr->next);

            curr->next = temp;

            return head;
        }

        curr = curr->next;
    }

    // Value not found
    return head;
}

// Insert BEFORE first occurrence of value
ListNode* insertBeforeValue(ListNode* head, int x, int val)
{
    // Empty list
    if(head == nullptr)
        return head;

    // Insert before head
    if(head->data == val)
    {
        return new ListNode(x, head);
    }

    ListNode* prev = nullptr;
    ListNode* curr = head;

    while(curr != nullptr)
    {
        if(curr->data == val)
        {
            ListNode* temp = new ListNode(x, curr);

            prev->next = temp;

            return head;
        }

        prev = curr;
        curr = curr->next;
    }

    // Value not found
    return head;
}