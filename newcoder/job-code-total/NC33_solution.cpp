
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
    /**
     * 
     * @param l1 ListNode类 
     * @param l2 ListNode类 
     * @return ListNode类
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode header(0);
        ListNode *pHeader = &header;
        ListNode *current = pHeader;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val) // l1 优先
            {
                current->next = l1;
                current = l1;
                l1 = l1->next;
            }
            else // l2 优先
            {
                current->next = l2;
                current = l2;
                l2 = l2->next;
            }
        }

        if (l1 == nullptr)
        {
            current->next = l2;
            l1 = pHeader->next;
            return l1;
        }
        else
        {
            current->next = l1;
            l2 = pHeader->next;
            return l2;
        }
    }
};