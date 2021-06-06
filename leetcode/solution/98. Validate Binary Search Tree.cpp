#include <stack>
#include <climits>
using std::stack;

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
    stack<TreeNode *> st;

public:
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return false;

        TreeNode *top = nullptr;
        includeLeftBranch(root);
        int last = st.top()->val; // 利用中序遍历第一个值确定最小值，仅初始化为 INT_MIN 的话还不行，否则会在 while 中的 if 处判断出错，也就是说，在第一个元素就是 INT_MIN 的时候，<= last 该逻辑就会出问题
        top = st.top();
        st.pop();
        includeLeftBranch(top->right);

        while (!st.empty())
        {
            top = st.top();
            st.pop();
            if (top->val <= last)
                return false;
            last = top->val;
            includeLeftBranch(top->right);
        }
        return true;
    }

    void includeLeftBranch(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }
};