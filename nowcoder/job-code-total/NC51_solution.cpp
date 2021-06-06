#include <vector>
using std::vector;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;

        // 下面这段被注释的代码可以通过
        // while (lists.size() != 1)
        // {
        //     ListNode *frontHalf = *(--lists.end());
        //     lists.pop_back();
        //     ListNode *backHalf = *(--lists.end());
        //     lists.pop_back();
        //     lists.push_back(mergeTwoLists(frontHalf, backHalf));
        // }
        // return *(lists.begin());

        // 下面这段被注释的代码会提示输出超限
        // while (lists.size() != 1)
        // {
        //     for (int i = 0; i < lists.size() / 2; ++i)
        //     {
        //         lists.at(i) = mergeTwoLists(*(lists.begin() + i), *(lists.end() - i - 1));
        //         lists.pop_back();
        //     }
        // }
        // return *(lists.begin());

        // 下面这段代码终于过了。
        while (lists.size() != 1)
        {
            int originalSize = lists.size();
            for (int i = 0; i < originalSize / 2; ++i)
            {
                lists.at(i) = mergeTwoLists(*(lists.begin() + i), *(lists.end() - 1));
                lists.pop_back();
            }
        }
        return *(lists.begin());

        // if (lists.size() == 0)
        //     return NULL;
        // ListNode *res = lists[0];              //取出第一个链表
        // for (int i = 1; i < lists.size(); i++) //反复调用
        //     res = mergeTwoLists(res, lists[i]);
        // return res;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode sentinel = ListNode(0);
        ListNode *current = &sentinel;

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
        }

        if (l1 == nullptr)
        {
            current->next = l2;
        }
        else // l2 为 nullptr
        {
            current->next = l1;
        }
        return sentinel.next;
    }
};

int main()
{
    ListNode one = ListNode(1);
    ListNode two = ListNode(2);
    ListNode three = ListNode(3);
    ListNode four = ListNode(4);
    ListNode five = ListNode(5);
    ListNode six = ListNode(6);
    ListNode seven = ListNode(7);
    ListNode eight = ListNode(8);
    Solution solution;
    // one.next = &two;
    // two.next = &three;
    // four.next = &five;
    // five.next = &six;
    // six.next = &seven;
    std::vector<ListNode *> lists;
    lists.push_back(&one);
    lists.push_back(&four);
    lists.push_back(&eight);
    lists.push_back(nullptr);
    lists.push_back(nullptr);
    ListNode *result = solution.mergeKLists(lists);
    return 0;
}