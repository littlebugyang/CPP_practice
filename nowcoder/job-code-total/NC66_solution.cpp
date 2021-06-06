
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
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        int l1 = listLength(pHead1);
        int l2 = listLength(pHead2);
        ListNode *current1 = pHead1;
        ListNode *current2 = pHead2;
        if (l1 < l2)
        {
            current2 = listForward(current2, l2 - l1);
        }
        else if (l1 > l2)
        {
            current1 = listForward(current1, l1 - l2);
        }

        while (current1 != current2)
        {
            current1 = current1->next;
            current2 = current2->next;
        }
        return current1;
    }

    int listLength(ListNode *head)
    {
        int count = 0;
        ListNode *current = head;
        while (current != nullptr)
        {
            ++count;
            current = current->next;
        }
        return count;
    }

    ListNode *listForward(ListNode *head, int k)
    {
        for (int i = 0; i < k; ++i)
        {
            head = head->next;
        }
        return head;
    }
};

int main()
{
    ListNode one = ListNode(1);
    ListNode two = ListNode(2);
    ListNode three = ListNode(3);
    ListNode four = ListNode(4);
    one.next = &two;
    two.next = &four;
    three.next = &four;
    Solution solution;
    ListNode *result = solution.FindFirstCommonNode(&one, &three);
    return 0;
}