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
private:
    vector<int> result;

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return result;

        vector<TreeNode *> stack;
        stack.push_back(root);

        while (!stack.empty())
            visitTillLeftmost(stack);
        return result;
    }

    void visitTillLeftmost(vector<TreeNode *> &s)
    {
        // 从栈顶取出一个节点，遍历其左侧分支
        TreeNode *x = s[s.size() - 1];
        s.pop_back();

        do
        {
            result.push_back(x->val);
            if (x->right)
                s.push_back(x->right);
        } while (x = x->left);
    }
};