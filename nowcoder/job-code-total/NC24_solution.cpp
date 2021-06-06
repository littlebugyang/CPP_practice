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
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *current = head;
        ListNode *next = head->next;
        bool duplicated = false;

        while (next != nullptr)
        {
            if (next->val != current->val)
            {
                if (!duplicated) // current 指向的值还没有重复的
                    current = current->next;

                current->val = next->val;
                duplicated = false; // 总之是遇到不一样的值了，current 指向的值是新值，可能等下会遇上一样的，但是现在还没有，所以不为重复
            }
            else // 遇上与 current 一样的值，标记一下，之后用于删除。
                duplicated = true;

            next = next->next;
        }

        if (duplicated)
        {
            if (head == current)
                return nullptr;

            ListNode *tempCurrent = head;
            while (tempCurrent->next != current)
                tempCurrent = tempCurrent->next;

            tempCurrent->next = nullptr;
        }
        else
            current->next = nullptr;

        return head;
    }
};

int main()
{
    ListNode one = ListNode(1);
    ListNode two = ListNode(1);
    ListNode three1 = ListNode(1);
    ListNode three2 = ListNode(1);
    ListNode four1 = ListNode(1);
    ListNode four2 = ListNode(1);
    ListNode five1 = ListNode(1);
    one.next = &two;
    two.next = &three1;
    three1.next = &three2;
    three2.next = &four1;
    four1.next = &four2;
    four2.next = &five1;
    Solution solution;
    ListNode *result = solution.deleteDuplicates(&one);
    return 0;
}