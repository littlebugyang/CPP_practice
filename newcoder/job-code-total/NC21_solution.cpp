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
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode sentinelO = ListNode(0);
        ListNode *sentinel = &sentinelO;
        ListNode *slow, *slowPrev, *fast, *fastForward;
        slow = slowPrev = fast = fastForward = sentinel;
        fast->next = head;

        // 快指针先走几步
        int jumps = n - m;
        for (int i = 0; i < jumps; ++i)
            fast = fast->next;

        // 快慢指针同等速度前进
        for (int i = 0; i < m; ++i)
        {
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        // 快指针与后半部分，分开
        fastForward = fast->next;
        fast->next = nullptr;

        // 反转链表，之后续接原先的后半部分
        slowPrev->next = reverseAndConcatenate(slow, fastForward);
        return sentinel->next;
    }

    ListNode *reverseAndConcatenate(ListNode *head, ListNode *tail)
    {
        ListNode *current, *originalHead;
        current = originalHead = head;
        ListNode *prev = nullptr;
        while (head != nullptr)
        {
            head = head->next;
            current->next = prev;
            prev = current;
            current = head;
        }
        originalHead->next = tail;
        return prev;
    }
};

int main()
{
    ListNode one = ListNode(3);
    ListNode two = ListNode(5);
    ListNode three = ListNode(3);
    ListNode four = ListNode(4);
    ListNode five = ListNode(5);
    one.next = &two;
    // two.next = &three;
    // three.next = &four;
    // four.next = &five;
    Solution solution;
    ListNode *result = solution.reverseBetween(&one, 1, 2);
    return 0;
}