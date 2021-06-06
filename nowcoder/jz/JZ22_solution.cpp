#include <vector>
using std::vector;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};
class Solution
{
public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<TreeNode *> queue;
        vector<int> result;
        if (!root)
            return result;
        int headOfQueue = -1;
        queue.push_back(root);
        while (headOfQueue != queue.size() - 1)
        {
            TreeNode *nextNode = queue[headOfQueue + 1];
            // 1. 加入首元素的左右孩子
            if (nextNode->left)
                queue.push_back(nextNode->left);
            if (nextNode->right)
                queue.push_back(nextNode->right);

            // 2. 访问队首元素
            result.push_back(nextNode->val);

            // 3. 出队
            ++headOfQueue;
        }
        return result;
    }
};