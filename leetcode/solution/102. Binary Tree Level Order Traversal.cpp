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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        vector<TreeNode *> queue;
        vector<int> vals;
        queue.push_back(root);
        vals.push_back(root->val);
        result.push_back(vector<int>(1, root->val));

        int potentialTries = 2;
        int remainingTries = potentialTries;

        int headIndex = 0;
        int layerBegin = 0, layerEnd = 1;

        while (headIndex != queue.size())
        {
            if (potentialTries == remainingTries)
                layerBegin = queue.size();

            if (queue[headIndex]->left)
                queue.push_back(queue[headIndex]->left), vals.push_back(queue[headIndex]->left->val);
            if (queue[headIndex]->right)
                queue.push_back(queue[headIndex]->right), vals.push_back(queue[headIndex]->right->val);

            remainingTries -= 2;
            if (remainingTries == 0)
            {
                layerEnd = queue.size();
                remainingTries = potentialTries = (layerEnd - layerBegin) * 2;
                if (layerBegin != layerEnd)
                    result.push_back(vector<int>(vals.begin() + layerBegin, vals.begin() + layerEnd));
            }
            ++headIndex;
        }
        return result;
    }
};