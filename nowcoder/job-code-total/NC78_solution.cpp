struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};

class Solution
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode *current = pHead;
        ListNode *prev = nullptr;
        while (pHead != nullptr)
        {
            pHead = pHead->next;
            current->next = prev;
            prev = current;
            current = pHead;
        }
        return prev;
    }
};