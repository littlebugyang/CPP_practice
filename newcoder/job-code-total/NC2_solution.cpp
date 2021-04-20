struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return; // 无节点或单节点链表直接返回
        ListNode sentinelO = ListNode(0);
        ListNode *sentinel, *slow, *fast;
        sentinel = slow = fast = &sentinelO;
        sentinel->next = head;

        // 快慢指针找到中心节点
        bool moveSlow = false;
        while (fast != nullptr)
        {
            if (moveSlow)
            {
                slow = slow->next;
            }
            fast = fast->next;
            moveSlow = !moveSlow;
        }

        // 以慢指针为新链表头部，分开链表，并反转
        // 节点数为偶数时，慢指针停在前一半节点的末尾，则可以以其下一个节点为头部
        // 节点数为奇数时，慢指针停在中间节点，则可以以其下一个节点为头部
        // 这样一来，前半部分的节点至少与后半部分节点数相同，至多比后半部分多一个节点
        ListNode *backHalf = reverseList(slow->next);
        slow->next = nullptr; // 斩草除根

        // 合并两链表
        ListNode *frontHalf = head;
        ListNode *temp = head;

        while (backHalf != nullptr)
        {
            temp = frontHalf->next;
            frontHalf->next = backHalf;
            backHalf = backHalf->next;
            frontHalf->next->next = temp;
            frontHalf = temp;
        }
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *prev = nullptr;
        while (head != nullptr)
        {
            head = head->next;
            current->next = prev;
            prev = current;
            current = head;
        }
        return prev;
    }
};

int main()
{
    ListNode one = ListNode(1);
    ListNode two = ListNode(4);
    ListNode three1 = ListNode(6);
    ListNode three2 = ListNode(3);
    ListNode four1 = ListNode(7);
    ListNode four2 = ListNode(1);
    ListNode five1 = ListNode(1);
    one.next = &two;
    two.next = &three1;
    three1.next = &three2;
    three2.next = &four1;
    // four1.next = &four2;
    // four2.next = &five1;
    Solution solution;
    solution.reorderList(&one);
    return 0;
}