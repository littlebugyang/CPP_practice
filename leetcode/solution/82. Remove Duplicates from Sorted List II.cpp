struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode sentinel(0);
        sentinel.next = head;
        ListNode *prev = &sentinel, *curr = head->next;

        bool del = false;
        while (curr)
        {
            if (prev->next->val == curr->val)
            {
                curr = curr->next;
                del = true;
                continue;
            }
            else
            {
                if (del)
                {
                    prev->next = curr;
                    del = (curr->next && curr->next->val == curr->val);
                }
                else
                {
                    prev = prev->next;
                }
                curr = curr->next;
            }
        }

        if (del) // 应付最后的节点都被删除掉的场景
            prev->next = curr;

        return sentinel.next;
    }
};