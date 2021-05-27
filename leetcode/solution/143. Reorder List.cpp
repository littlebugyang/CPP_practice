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
    void reorderList(ListNode *head)
    {
        vector<ListNode *> nodes;
        vector<ListNode *> prevNodes;

        // 遍历该链表，当前节点地址入栈，前继节点地址入栈
        prevNodes.push_back(head); // 第一个节点没有必要入 nodes 栈，因为 prevNodes 中不可能有其前继
        ListNode *curr = head->next;
        while (curr != nullptr)
        {
            prevNodes.push_back(curr);
            nodes.push_back(curr);
            curr = curr->next;
        }

        curr = head;
        for (int i = 0; i < nodes.size() / 2; ++i)
        {
            insertAfter(curr, nodes[nodes.size() - i - 1], prevNodes[nodes.size() - i - 1]);
            curr = curr->next->next;
        }
    }

    void insertAfter(ListNode *pos, ListNode *target, ListNode *beforeTarget)
    {
        // 必须保证每个参数都不为空
        beforeTarget->next = target->next;
        target->next = pos->next;
        pos->next = target;
    }
};