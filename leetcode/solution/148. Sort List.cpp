#include <vector>
#include <iostream>
#include <climits>
using std::cout;
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
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }

    ListNode *mergeSort(ListNode *head)
    {
        ListNode sentinel(INT_MIN);
        sentinel.next = head;

        int step = 1;

        ListNode *h1 = head, *h2 = nullptr, *begin = &sentinel, *end = nullptr;

        while (true)
        {
            h2 = h1;
            for (int i = 0; i < step && h2; ++i) // 从 h1 出发，找到 h2
                h2 = h2->next;

            if (!h2) // h1 不够长了
            {
                if (begin == &sentinel) // h1 是该链表第一段
                {
                    break;
                }
                else // h1 不是第一段，步长翻倍，指针回头
                {
                    step <<= 1;
                    begin = &sentinel;
                    h1 = begin->next;
                    continue;
                }
            }

            end = h2;
            for (int i = 0; i < step && end; ++i)
                end = end->next;

            begin = mergeTwoList(begin, h1, h2, end);
            h1 = begin->next;
        }
        return sentinel.next;
    }

    ListNode *mergeTwoList(ListNode *begin, ListNode *h1, ListNode *h2, ListNode *end)
    {
        // 合并两个已经有序的列表
        // 需确保 begin 不为空
        ListNode *nextBegin = begin;
        ListNode *h1End = h2;

        while (h1 != h1End && h2 != end)
        {
            if (h1->val <= h2->val)
            {
                begin->next = h1;
                h1 = h1->next;
            }
            else
            {
                begin->next = h2;
                h2 = h2->next;
            }
            nextBegin = begin;
            begin = begin->next;
        }

        if (h1 == h1End) // h1 先完事儿
        {
            begin->next = h2;    // 最后找到 h2 连接起来就好
            while (begin != end) // 一路追到 end
            {
                nextBegin = begin;
                begin = begin->next;
            }
        }
        if (h2 == end) // h2 先完事儿
        {
            // 找到 h1 当前的地方，一路复制到 end
            while (h1 != h1End)
            {
                begin->next = h1;
                h1 = h1->next;
                begin = begin->next;
            }
            nextBegin = begin; // 反正最终 begin 的下一个就是 end，这恰好就是 nextBegin
            begin->next = end;
        }

        // 最终返回 end 前一个节点，可能用作下次 mergeTwoList 的 begin
        return nextBegin;
    }

    ListNode *quickSort(ListNode *start, ListNode *end)
    {
        // 左闭右开
        if (!start)
            return end;
        if (start == end || start->next == end) // 不存在元素，或者只剩下一个元素
            return start;

        // 使用 LUG 方法，L 为小于等于 pivot 的元素集合，G 为大于 pivot 的元素集合，U 为未确定的元素集合
        ListNode headL(0), *currL = &headL;
        ListNode headG(0), *currG = &headG;
        ListNode *pivot = start;
        ListNode *currU = start->next;

        while (currU != end)
        {
            if (currU->val <= pivot->val)
            {
                currL->next = currU;
                currL = currL->next;
            }
            else
            {
                currG->next = currU;
                currG = currG->next;
            }
            currU = currU->next;
        }

        currL->next = pivot;
        pivot->next = nullptr;
        currG->next = end;
        ListNode *sortedL = quickSort(headL.next, pivot);
        ListNode *sortedG = quickSort(headG.next, end);
        pivot->next = sortedG;

        return sortedL;
    }
};

ListNode *constructList(const vector<int> &nums)
{
    ListNode head = ListNode(0);
    ListNode *curr = &head;
    for (int i = 0; i < nums.size(); ++i)
    {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head.next;
}

int main()
{
    vector<int> test{-1, 5, 3, 4, 0};
    Solution solution;
    solution.sortList(constructList(test));
    return 0;
}