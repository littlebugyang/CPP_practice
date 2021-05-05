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
        bool carry = false;
        ListNode *curr1 = l1, *curr2 = l2;
        while (curr1 && curr2)
        {
            int sum = curr1->val + curr2->val + int(carry);
            carry = sum > 9;
            curr1->val = curr2->val = sum % 10;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        if (curr1)
        {
            ListNode *prev = curr1;
            while (curr1)
            {
                int sum = curr1->val + int(carry);
                carry = sum > 9;
                curr1->val = sum % 10;
                prev = curr1;
                curr1 = curr1->next;
            }
            if (carry)
                prev->next = new ListNode(1);
            return l1;
        }

        else if (curr2)
        {
            ListNode *prev = curr2;
            while (curr2)
            {
                int sum = curr2->val + int(carry);
                carry = sum > 9;
                curr2->val = sum % 10;
                prev = curr2;
                curr2 = curr2->next;
            }
            if (carry)
                prev->next = new ListNode(1);
            return l2;
        }

        else
        {
            if (carry)
            {
                curr1 = l1;
                while (curr1->next)
                    curr1 = curr1->next;
                curr1->next = new ListNode(1);
            }
            return l1;
        }
    }
};