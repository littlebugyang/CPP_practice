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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        vector<TreeNode *> nodes;
        nodes.push_back(root);
        int queueIndex = 0;
        int depth = 1;

        while (true)
        {
            int lastSize = nodes.size();
            for (int i = queueIndex; i < lastSize; ++i)
            {
                if (nodes[i]->left != nullptr)
                    nodes.push_back(nodes[i]->left);
                if (nodes[i]->right != nullptr)
                    nodes.push_back(nodes[i]->right);
            }
            queueIndex = lastSize;
            int numAddedNodes = nodes.size() - lastSize;
            if (!numAddedNodes)
                break;
            depth += (numAddedNodes > 0 ? 1 : 0);
        }
        return depth;
    }
};