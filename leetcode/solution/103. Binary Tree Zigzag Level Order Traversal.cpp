#include <vector>
#include <queue>
#include <algorithm>
using std::queue;
using std::reverse;
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<TreeNode *> q;
        q.push(root);

        bool reversed = true;

        while (!q.empty())
        {
            result.push_back(vector<int>());
            int currSize = q.size();
            for (int i = 0; i < currSize; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                result.back().push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (reversed = !reversed)
                reverse(result.back().begin(), result.back().end());
        }

        return result;
    }
};