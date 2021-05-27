#include <queue>
#include <vector>
using std::queue;
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
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> nodes;
        vector<int> values;
        if (!root)
            return values;
        nodes.push(root);
        while (!nodes.empty())
        {
            int currSize = nodes.size();
            int value = 0;
            for (int i = 0; i < currSize; ++i)
            {
                value = nodes.front()->val;
                if (nodes.front()->left)
                    nodes.push(nodes.front()->left);
                if (nodes.front()->right)
                    nodes.push(nodes.front()->right);
                nodes.pop();
            }
            values.push_back(value);
        }
        return values;
    }
};