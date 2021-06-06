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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode sen1(0), *curr1 = &sen1; // 哨兵真香
        curr1->next = l1;
        ListNode sen2(0), *curr2 = &sen2;
        curr2->next = l2;
        bool carry = false;
        while (curr1->next && curr2->next)
        {
            int sum = curr1->next->val + curr2->next->val + int(carry);
            carry = sum > 9;
            curr1->next->val = curr2->next->val = (sum % 10);
            curr1 = curr1->next, curr2 = curr2->next;
        }

        ListNode *longer = curr1->next ? curr1 : curr2;
        solveRest(longer, carry);
        return curr1->next ? l1 : l2;
    }

    void solveRest(ListNode *head, bool carry)
    {
        // 此处的 head 是之前某链表上最后一个更新 val 的节点
        while (head->next)
        {
            int sum = head->next->val + int(carry);
            carry = sum > 9;
            head->next->val = (sum % 10);
            head = head->next;
        }

        if (carry)
            head->next = new ListNode(1), head = head->next;
    }
};