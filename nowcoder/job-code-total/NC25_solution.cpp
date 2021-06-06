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
     * @return ListNode类
     */
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *current = head;
        ListNode *next = current->next;
        int currentVal = current->val;
        while (next != nullptr)
        {
            if (next->val != currentVal)
            {
                current = current->next;
                current->val = next->val;
                currentVal = next->val;
            }
            next = next->next;
        }
        current->next = nullptr;
        return head;
    }
};

int main()
{
    ListNode one = ListNode(1);
    ListNode two = ListNode(1);
    ListNode three = ListNode(2);
    one.next = &two;
    two.next = &three;
    Solution solution;
    ListNode *result = solution.deleteDuplicates(&one);
    return 0;
}