#include <vector>
#include <map>
using std::map;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    map<TreeNode *, TreeNode *> parentMaps;

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        constructParentMaps(root);
        vector<TreeNode *> stack;
        TreeNode *x = nullptr;

        stack.push_back(root);

        while (!stack.empty())
        {
            if (!x || parentMaps[x] != stack[stack.size() - 1]) // x 为空节点，也就是刚开始时；或者栈顶是节点不是刚刚 pop 出去的节点的父节点
                findSuccessor(stack);                           // 栈顶现在是 x 的右兄弟

            x = stack[stack.size() - 1];
            result.push_back(x->val); // 访问
            stack.pop_back();         // 出栈
        }

        return result;
    }

    void findSuccessor(vector<TreeNode *> &s)
    {
        // 必须保证 s 的大小至少为 1
        while (TreeNode *node = s[s.size() - 1])
        {
            if (node->left)
            {
                if (node->right)
                    s.push_back(node->right);
                s.push_back(node->left);
            }
            else
                s.push_back(node->right);
        }
        s.pop_back(); // s 中最后一个节点一定为空节点，否则无法退出 while 循环
    }

    void constructParentMaps(TreeNode *root)
    {
        vector<TreeNode *> queue;
        queue.push_back(root);
        parentMaps[root] = nullptr; // 根节点没有父节点
        unsigned int headIndex = 0;
        while (headIndex != queue.size())
        {
            if (queue[headIndex]->left)
            {
                queue.push_back(queue[headIndex]->left);
                parentMaps[queue[headIndex]->left] = queue[headIndex];
            }
            if (queue[headIndex]->right)
            {
                queue.push_back(queue[headIndex]->right);
                parentMaps[queue[headIndex]->right] = queue[headIndex];
            }
            ++headIndex;
        }
    }
};