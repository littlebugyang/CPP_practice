struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return nullptr;

        /*
            设长度即为节点数
            链表头到相遇地点的长度为 n1，相遇地点到环起点长度为 n2，环的长度为 n3
            可得 n1 - n3 为 链表头到环起点的长度与 n2 的差 d
            则 fast 先在链表头开始前进 d 步（如果 d 为正，否则由 slow 在相遇地点先行），然后 slow 和 fast 同步前进
            最终相遇地点为环起点
        */

        /*
            如果设长度为节点之间的连线的话（即便不存在），在快指针与慢指针速度 2:1 时，有更好的解决办法：
            两指针同时从相遇节点和链表头出发，再次相遇的地方就是环起点
       */

        ListNode *slow = head, *fast = head->next;
        ListNode sentinel(0);
        sentinel.next = head;
        while (fast)
        {
            if (fast == slow) // 有环
            {
                fast = &sentinel;
                while (fast != slow)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
            slow = slow->next;
            if (fast->next)
                fast = fast->next->next;
            else
                return nullptr;
        }
        return nullptr;
    }
};