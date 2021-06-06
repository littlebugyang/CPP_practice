
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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode *sortInList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode sentinelO(0);
        ListNode *slow, *fast, *sentinel;
        slow = fast = sentinel = &sentinelO;
        sentinel->next = head;
        bool moveSlow = false;

        while (fast->next != nullptr)
        {
            fast = fast->next;
            if (moveSlow)
            {
                slow = slow->next;
            }
            moveSlow = !moveSlow;
        }

        ListNode *backSorted = sortInList(slow->next);
        slow->next = nullptr;
        ListNode *frontSorted = sortInList(head);
        return mergeTwoLists(frontSorted, backSorted);
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode sentinelO = ListNode(0);
        ListNode *sentinel, *current;
        sentinel = current = &sentinelO;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
            current->next = nullptr;
        }

        if (l1 == nullptr)
        {
            current->next = l2;
        }
        else // l2 为 nullptr
        {
            current->next = l1;
        }
        return sentinel->next;
    }
};

int main()
{
    ListNode one = ListNode(1);
    ListNode two = ListNode(3);
    ListNode three = ListNode(2);
    ListNode four = ListNode(4);
    ListNode five = ListNode(5);
    ListNode six = ListNode(6);
    ListNode seven = ListNode(7);
    ListNode eight = ListNode(8);
    Solution solution;
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    // five.next = &six;
    // six.next = &seven;

    ListNode *result = solution.sortInList(&one);
    return 0;
}