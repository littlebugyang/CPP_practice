#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder2(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        vector<TreeNode *> queue;

        queue.push_back(root);
        result.push_back(vector<int>(1, root->val));

        int potentialTries = 2;
        int remainingTries = potentialTries;

        int headIndex = 0;
        int layerBegin = 0, layerEnd = 1;

        while (headIndex != queue.size())
        {
            if (potentialTries == remainingTries) // 新一层开始了
            {
                layerBegin = queue.size();
                result.push_back(vector<int>());
            }

            if (queue[headIndex]->left)
                queue.push_back(queue[headIndex]->left), result.back().push_back(queue[headIndex]->left->val);
            if (queue[headIndex]->right)
                queue.push_back(queue[headIndex]->right), result.back().push_back(queue[headIndex]->right->val);

            remainingTries -= 2;     // 尝试了两次
            if (remainingTries == 0) // 尝试次数为 0，则下一层不可能再有元素了
            {
                layerEnd = queue.size();
                remainingTries = potentialTries = (layerEnd - layerBegin) * 2; // 下一层可尝试的次数
            }
            ++headIndex; // 转至下个节点
        }
        result.pop_back();
        return result;
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int currSize = q.size();
            result.push_back(vector<int>());
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
        }
        return result;
    }
};