
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
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode *FindKthToTail(ListNode *pHead, int k)
    {
        if (pHead == nullptr)
            return nullptr;
        ListNode *sentinel = new ListNode(0);
        sentinel->next = pHead;
        ListNode *back, *front;
        back = front = sentinel;
        for (int i = 0; i < k + 1; ++i)
        {
            front = front->next;
            if (i < k && front == nullptr)
            {
                return nullptr;
            }
        }
        while (front != nullptr)
        {
            back = back->next;
            front = front->next;
        }
        delete sentinel;
        return back->next;
    }
};

int main()
{
    ListNode one = ListNode(9);
    ListNode two = ListNode(6);
    ListNode three = ListNode(3);
    Solution solution;
    ListNode *result = solution.FindKthToTail(&one, 1);
    return 0;
}