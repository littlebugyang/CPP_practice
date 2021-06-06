#include <vector>
#include <algorithm>
using std::swap;
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<ListNode *> heap;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i])
                heap.push_back(lists[i]);
        heapify(heap);
        ListNode sentinel(0);
        ListNode *curr = &sentinel;

        while (heap.size() > 0 && heap[0])
        {
            curr->next = heap[0];
            curr = curr->next;

            if (heap[0]->next) // 该链表还没有遍历完
            {
                heap[0] = heap[0]->next;
            }
            else // 根节点所在的链表已经完成遍历了
            {
                heap[0] = heap[heap.size() - 1];
                heap.pop_back();
            }
            percolateDown(heap, 0);
        }
        return sentinel.next;
    }

    void heapify(vector<ListNode *> &lists)
    {
        for (int i = lists.size(); i >= 0; --i)
            percolateDown(lists, i);
    }

    void percolateDown(vector<ListNode *> &lists, int i)
    {
        int proper = findProperChild(lists, i);
        while (proper != -1 && !compare(lists[i]->val, lists[proper]->val))
        {
            swap(lists[i], lists[proper]);
            i = proper;
            proper = findProperChild(lists, i);
        }
    }

    int findProperChild(vector<ListNode *> &lists, int i)
    {
        int leftI = 2 * i + 1, rightI = 2 * i + 2;
        int properChild = -1;
        if (leftI < lists.size()) // 左孩子存在
        {
            properChild = leftI;
            if (rightI < lists.size()) // 右孩子也存在
            {
                properChild = compare(lists[leftI]->val, lists[rightI]->val) ? leftI : rightI;
            }
        }
        return properChild;
    }

    bool compare(int a, int b)
    {
        return a < b;
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
    vector<vector<int>> test = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode *> lists;
    for (int i = 0; i < test.size(); ++i)
        lists.push_back(constructList(test[i]));
    Solution solution;
    solution.mergeKLists(lists);
    return 0;
}