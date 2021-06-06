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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) // 链表中没有节点或只有一个节点
            return head;

        ListNode *oddHead, *oddCurrent;
        ListNode *evenHead, *evenCurrent;
        oddHead = oddCurrent = head;
        evenHead = evenCurrent = head->next;

        while (true)
        {
            if (oddCurrent->next != nullptr && oddCurrent->next->next != nullptr)
            {
                oddCurrent->next = oddCurrent->next->next;
                oddCurrent = oddCurrent->next;
            }
            else  // 节点个数为奇数时，偶链表首先遇到退出条件；但是不需要断开与后继节点的边接，因为到最后还是会重连到偶链表的头。
                break;

            if (evenCurrent->next != nullptr && evenCurrent->next->next != nullptr)
            {
                evenCurrent->next = evenCurrent->next->next;
                evenCurrent = evenCurrent->next;
            }
            else // 节点个数为奇数时，偶链表首先遇到退出条件
            {
                evenCurrent->next = nullptr;
                break;
            }
        }
        oddCurrent->next = evenHead;
        return oddHead;
    }
};

int main()
{
    ListNode one = ListNode(1);
    ListNode two = ListNode(4);
    ListNode three1 = ListNode(6);
    ListNode three2 = ListNode(3);
    ListNode four1 = ListNode(7);
    ListNode four2 = ListNode(1);
    ListNode five1 = ListNode(1);
    one.next = &two;
    two.next = &three1;
    three1.next = &three2;
    three2.next = &four1;
    // four1.next = &four2;
    // four2.next = &five1;
    Solution solution;
    ListNode *result = solution.oddEvenList(&one);
    return 0;
}