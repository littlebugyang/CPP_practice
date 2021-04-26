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
    bool isPalindrome(ListNode *head)
    {
        // 1. 定义速度比为 1:2 的慢快指针，让快指针走到头
        // 2. 以慢指针为界，把链表分成两半，后一半反转
        // 3. 与之比较，后一半节点数小于等于前一半节点数，所以只判断后半部分是否已经遍历完即可

        // 1. 定义速度比为 1:2 的慢快指针，让快指针走到头
        ListNode sentinel = ListNode(0);
        sentinel.next = head;
        ListNode *slow = &sentinel;
        ListNode *fast = head;
        bool moveSlow = false;
        while (fast != nullptr)
        {
            if (moveSlow)
                slow = slow->next;
            fast = fast->next;
            moveSlow = !moveSlow;
        }

        // 2. 以慢指针为界，把链表分成两半，后一半反转
        ListNode *reversed = reverseList(slow->next);

        // 3. 与之比较，后一半节点数小于等于前一半节点数，所以只判断后半部分是否已经遍历完即可
        slow = sentinel.next;
        while (reversed != nullptr)
        {
            if (slow->val != reversed->val)
                return false;
            slow = slow->next;
            reversed = reversed->next;
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