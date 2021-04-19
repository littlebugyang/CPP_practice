
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *begin = head;
        ListNode *end = head;
        ListNode *current = head;
        int count = 1;
        while (current != nullptr)
        {
            if ((k <= count) && (count % k == 0))
            {
                end = current;
                reverse(begin, end);
                begin = end = current->next;
            }
            current = current->next;
            ++count;
        }
        return head;
    }

    void reverse(ListNode *begin, ListNode *end)
    {
        while (begin != end && end->next != begin)
        {
            int val = begin->val;
            begin->val = end->val;
            end->val = val;
            ListNode *temp = begin;
            while (temp->next != end)
            {
                temp = temp->next;
            }
            begin = begin->next;
            end = temp;
        }
    }
};