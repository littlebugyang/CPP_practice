
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
        if (head == nullptr)
        {
            return false;
        }
        ListNode *slow, *fast;
        slow = head;
        fast = head->next;
        bool slowMove = false;
        while (fast != nullptr)
        {
            if (fast == slow)
            {
                return true;
            }
            slowMove = !slowMove;

            if (slowMove)
            {
                slow = slow->next;
            }
            fast = fast->next;
        }
        return false;
    }
};