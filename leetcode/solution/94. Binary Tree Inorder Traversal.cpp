#include <vector>
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        vector<TreeNode *> stack;

        stack.push_back(root);
        findSuccessor(stack);

        while (!stack.empty())
        {
            TreeNode *x = stack[stack.size() - 1];
            stack.pop_back();
            result.push_back(x->val);

            if (x->right)
            {
                stack.push_back(x->right);
                findSuccessor(stack);
            }
        }
        return result;
    }

    void findSuccessor(vector<TreeNode *> &s)
    {
        // 必须保证 s 至少有一个节点
        TreeNode *x = s[s.size() - 1];
        while (x = x->left)
            s.push_back(x);
    }
};