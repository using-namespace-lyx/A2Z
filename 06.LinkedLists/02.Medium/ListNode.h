class ListNode{
    public:
    int data,val;
    ListNode* next;
    ListNode *prev;

    ListNode(int data1, ListNode*next1)
    {
        data=data1;
        next=next1;
    }
};