
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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode *sortInList(ListNode *head)
    {
        ListNode sortedS(0);
        ListNode *sorted = &sortedS; // 有序链表哨兵
        sorted->next = head;
        ListNode *lastSorted = sorted; // 有序部分移动

        while (lastSorted->next != nullptr)
        {
            int minVal = lastSorted->next->val;
            ListNode *current = lastSorted->next;
            ListNode *minNode = current;
            while (current != nullptr)
            {
                if (current->val < minVal)
                {
                    minVal = current->val;
                    minNode = current;
                }
                current = current->next;
            }
            minNode->val = lastSorted->next->val;
            lastSorted->next->val = minVal;
            lastSorted = lastSorted->next;
        }

        return head;
    }
};

int main()
{
    ListNode one = ListNode(9);
    ListNode two = ListNode(6);
    ListNode three = ListNode(3);
    Solution solution;
    ListNode *result = solution.sortInList(&one);
    return 0;
}