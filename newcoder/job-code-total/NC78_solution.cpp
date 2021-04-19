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
        ListNode *current = new ListNode(0);
        ListNode *prev = new ListNode(0);
        while (pHead != nullptr)
        {
            prev->next = current->next;
            current->next = pHead;
            pHead = pHead->next;
            current->next->next = prev->next;
        }
        ListNode * ret = current->next;
        delete prev;
        delete current;
        return ret;
    }
};