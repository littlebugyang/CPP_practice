
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
     * @param n int整型 
     * @return ListNode类
     */
    ListNode *removeNthFromEnd2(ListNode *head, int n) // 我的旧思路
    {
        // 计算有多少个节点。
        int count = 0;
        ListNode *sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode *current = head;
        while (current != nullptr)
        {
            ++count;
            current = current->next;
        }
        int jumps = count - n; // 从 sentinel 出发要跳 jumps 次
        current = sentinel;
        for (int i = 0; i < jumps; ++i)
        {
            current = current->next;
        }
        ListNode *toDelete = current->next;
        current->next = toDelete->next;
        ListNode *ret = sentinel->next;
        delete toDelete;
        delete sentinel;
        return ret;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n) // 别人的新思路
    {
        ListNode *front, *back;
        ListNode *sentinel = new ListNode(0);
        sentinel->next = head;
        front = back = sentinel;
        for (int i = 0; i < n + 1; ++i)
        {
            front = front->next;
        }

        while (front != nullptr)
        {
            front = front->next;
            back = back->next;
        }

        ListNode *toDelete = back->next;
        back->next = back->next->next;
        ListNode *ret = sentinel->next;
        delete toDelete;
        delete sentinel;
        return ret;
    }
};

int main()
{
    ListNode one = ListNode(1);
    ListNode two = ListNode(2);
    one.next = &two;
    Solution solution;
    ListNode *result = solution.removeNthFromEnd(&one, 1);
    return 0;
}