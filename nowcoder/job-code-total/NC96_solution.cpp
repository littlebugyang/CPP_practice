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
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode *head)
    {
        int count = 0;
        ListNode *front, *back;
        front = back = head;
        while (front != nullptr)
        {
            ++count;
            front = front->next;
        }

        front = head;
        for (int i = 0; i < int(count / 2.0 + 0.5); ++i)
            front = front->next;

        front = reverseList(front);

        while (front != nullptr)
        {
            if (front->val != back->val)
            {
                return false;
            }
            back = back->next;
            front = front->next;
        }
        return true;
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
    ListNode two = ListNode(2);
    ListNode three = ListNode(2);
    ListNode four = ListNode(1);
    one.next = &two;
    two.next = &three;
    three.next = &four;
    Solution solution;
    bool result = solution.isPail(&one);
    return 0;
}