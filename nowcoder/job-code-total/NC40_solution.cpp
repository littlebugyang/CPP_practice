#include <iostream>
#include <climits>
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
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode *addInList(ListNode *head1, ListNode *head2)
    {
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        ListNode *current1 = head1;
        ListNode *current2 = head2;

        bool carry = false;
        while (current1 != nullptr && current2 != nullptr)
        {
            int sum = current1->val + current2->val;
            current1->val = current2->val = (sum + int(carry)) % 10;
            carry = bool((sum + int(carry)) / 10);
            current1 = current1->next;
            current2 = current2->next;
        }

        ListNode *longer = current1 == nullptr ? current2 : current1;
        ListNode *prev = nullptr;
        while (longer != nullptr)
        {
            int sum = longer->val + int(carry);
            longer->val = sum % 10;
            carry = bool(sum / 10);
            prev = longer;
            longer = longer->next;
        }
        if (carry)
        {
            longer = new ListNode(1);
            prev->next = longer;
        }
        return reverseList(current1 == nullptr ? head2 : head1);
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
    ListNode one = ListNode(9);
    ListNode two = ListNode(6);
    ListNode l3 = ListNode(3);
    ListNode l32 = ListNode(3);
    ListNode l7 = ListNode(7);
    one.next = &l3;
    l3.next = &l7;
    two.next = &l32;
    Solution solution;
    ListNode *result = solution.addInList(&one, &two);
    return 0;
}