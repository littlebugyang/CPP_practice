struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode sentinel(0);
        sentinel.next = head;
        ListNode *slow, *fast;
        slow = &sentinel;
        fast = head;
        bool moveSlow = true;
        while (fast != nullptr)
        {
            if (moveSlow)
                slow = slow->next;
            fast = fast->next;
            if (slow == fast)
                break;
            moveSlow = !moveSlow;
        }
        return !(fast == nullptr);
    }
};