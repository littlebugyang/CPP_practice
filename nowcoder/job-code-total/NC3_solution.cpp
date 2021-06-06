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
        if (head == nullptr)
            return nullptr;
        ListNode *slow, *fast;
        fast = head->next;
        slow = head;
        bool slowMove = false;
        while (fast != nullptr)
        {
            if (fast == slow)
            { // 有环
                if (!slowMove)
                {
                    slow = slow->next;
                }
                ListNode *slow2 = head;
                while (true)
                {
                    if (slow2 == slow)
                    {
                        return slow;
                    }
                    slow2 = slow2->next;
                    slow = slow->next;
                }
            }
            slowMove = !slowMove;
            if (slowMove)
            {
                slow = slow->next;
            }
            fast = fast->next;
        }
        // 跳出 while 则是无环
        return nullptr;
    }
};