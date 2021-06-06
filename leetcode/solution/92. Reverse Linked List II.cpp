struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode sentinel(0);
        sentinel.next = head;
        ListNode *beforeLeft = &sentinel;
        for (int i = 0; i < left - 1; ++i)
            beforeLeft = beforeLeft->next;

        ListNode *reversedTail = beforeLeft->next;
        ListNode *moved = reversedTail->next;

        for (int i = 0; i < right - left; ++i)
        {
            reversedTail->next = moved->next;
            moved->next = beforeLeft->next;
            beforeLeft->next = moved;
            moved = reversedTail->next;
        }

        return sentinel.next;
    }
};