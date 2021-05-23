#include <vector>
using std::vector;

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || !head->next || k == 1)
            return head;

        ListNode sentinel(0);
        sentinel.next = head;

        ListNode *start = &sentinel;
        ListNode *end = head;

        int count = 1;
        while (end != nullptr) // problem
        {

            if (count >= k && count % k == 0)
            {
                ListNode *endNextBack = end->next;
                vector<ListNode *> ret = reverse(start->next, end->next);

                start->next = ret[0];
                start = ret[1];
                ret[1]->next = endNextBack;
                end = ret[1];
            }

            end = end->next;
            ++count;
        }

        return sentinel.next;
    }

    vector<ListNode *> reverse(ListNode *begin, ListNode *end)
    {
        // 反转 [begin, end) 区间内的节点，返回第一个和最后一个非空节点。
        ListNode *beginBak = begin;
        ListNode *curr = begin;
        ListNode *prev = nullptr;
        while (begin != end)
        {
            begin = begin->next;
            curr->next = prev;
            prev = curr;
            curr = begin;
        }

        return vector<ListNode *>{prev, beginBak};
    }
};