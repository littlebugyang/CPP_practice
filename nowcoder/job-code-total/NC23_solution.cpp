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
     * @param x int整型 
     * @return ListNode类
     */
    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode sentinelO = ListNode(0);
        ListNode *sentinel, *slow, *fast;
        slow = fast = sentinel = &sentinelO;
        sentinel->next = head;

        while (fast->next != nullptr)
        {
            if (fast->next->val < x)
            {
                if (fast == slow)
                {
                    // 不需要移动，而且移动了会出错
                    fast = fast->next;
                    slow = slow->next;
                    continue;
                }

                ListNode *temp = slow->next;
                slow->next = fast->next;
                fast->next = slow->next->next;
                slow->next->next = temp;
                slow = slow->next;
            }
            else
            {
                fast = fast->next;
            }
        }
        return sentinel->next;
    }
};

int main()
{
    ListNode one = ListNode(1);
    ListNode two = ListNode(4);
    ListNode three = ListNode(3);
    ListNode four = ListNode(2);
    ListNode five = ListNode(5);
    ListNode six = ListNode(2);
    Solution solution;
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    five.next = &six;
    ListNode *result = solution.partition(&one, 3);
    return 0;
}