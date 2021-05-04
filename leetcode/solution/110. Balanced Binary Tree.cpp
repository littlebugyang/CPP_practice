#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using std::abs;
using std::map;
using std::max;
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
public:
    bool isBalanced(TreeNode *root)
    {
        return height(root) >= 0;
    }

    int height(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) < 1)
            return -1;
        else
            return max(leftHeight, rightHeight) + 1;
    }

    bool isBalancedIterative(TreeNode *root)
    {
        if (!root)
            return true;

        map<TreeNode *, int> nodeHeight;
        nodeHeight[root] = 1;

        vector<TreeNode *> queue;
        queue.push_back(root);
        
        map<TreeNode *, TreeNode *> nodeParent;
        nodeParent[root] = nullptr;

        int headIndex = 0;
        while (queue.size() != headIndex)
        {
            TreeNode *curr = queue[headIndex];
            if (curr->left)
            {
                queue.push_back(curr->left);
                nodeParent[curr->left] = curr;
            }
            if (curr->right)
            {
                queue.push_back(curr->right);
                nodeParent[curr->right] = curr;
            }

            ++headIndex;
        }

        vector<TreeNode *> stack;
        stack.push_back(root);
        findSuccessor(stack);

        while (true)
        {
            TreeNode *x = stack[stack.size() - 1];
            stack.pop_back();

            // update height
            int leftHeight = nodeHeight[x->left];
            int rightHeight = nodeHeight[x->right];
            int balanceFactor = leftHeight - rightHeight;
            if (balanceFactor > 1 || balanceFactor < -1)
                return false;
            nodeHeight[x] = max(leftHeight, rightHeight) + 1;

            if (stack.empty())
                break;

            if (nodeParent[x] != stack[stack.size() - 1])
                findSuccessor(stack);
        }
        return true;
    }

    void findSuccessor(vector<TreeNode *> &s)
    {
        // 保证 s 至少有一个节点
        while (TreeNode *x = s[s.size() - 1])
        {
            if (x->left)
            {
                if (x->right)
                    s.push_back(x->right);
                s.push_back(x->left);
            }
            else
                s.push_back(x->right);
        }
        s.pop_back();
    }

    bool isBalancedExceedTimeLimit(TreeNode *root)
    {
        if (!root)
            return true;
        vector<TreeNode *> queue;
        map<TreeNode *, TreeNode *> nodeParent;
        map<TreeNode *, int> nodeHeight;

        int headIndex = 0;
        queue.push_back(root);
        nodeParent[root] = nullptr;
        nodeHeight[root] = 1; // 约定空树高度为 0，因为用了 map，不存在的节点高度都被设置成 0 了。

        while (queue.size() != headIndex)
        {
            TreeNode *curr = queue[headIndex];
            if (curr->left)
            {
                queue.push_back(curr->left);
                nodeParent[curr->left] = curr;
                nodeHeight[curr->left] = 1;
            }
            if (curr->right)
            {
                queue.push_back(curr->right);
                nodeParent[curr->right] = curr;
                nodeHeight[curr->right] = 1;
            }

            int childHeight = 1;
            while (curr = nodeParent[curr])
            {
                if (nodeHeight[curr] == childHeight)
                    ++nodeHeight[curr];
                else
                    break;
                childHeight = nodeHeight[curr];
            }

            ++headIndex;
        }

        // 遍历所有节点，检查平衡因子
        headIndex = 0;
        while (queue.size() != headIndex)
        {
            int balanceFactor = nodeHeight[queue[headIndex]->left] - nodeHeight[queue[headIndex]->right];
            if (balanceFactor > 1 || balanceFactor < -1)
                return false;
            ++headIndex;
        }
        return true;
    }
};