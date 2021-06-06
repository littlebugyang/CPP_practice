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
    bool isCompleteTree(TreeNode *root)
    {
        return comment(root);
    }

    bool comment(TreeNode *root)
    {
        queue<TreeNode *> nodes;
        nodes.push(root);
        bool meetNull = false;
        while (!nodes.empty())
        {
            TreeNode *front = nodes.front();
            nodes.pop();
            if (!front) // 首元素是个空节点，后面的最好都是空节点
            {
                meetNull = true;
                continue;
            }
            if (meetNull) // 之前出现过空节点，而且 front 不是空
                return false;
            nodes.push(front->left);
            nodes.push(front->right);
        }
        return true;
    }

    bool official(TreeNode *root)
    {
        vector<TreeNode *> nodes;
        vector<int> indexes;
        nodes.push_back(root);
        indexes.push_back(0);
        int head = 0;
        while (head != nodes.size())
        {
            TreeNode *front = nodes[head];
            if (front->left)
            {
                nodes.push_back(front->left);
                indexes.push_back(2 * head + 1);
            }
            if (front->right)
            {
                nodes.push_back(front->right);
                indexes.push_back(2 * head + 2);
            }
            ++head;
        }
        return indexes[indexes.size() - 1] + 1 == nodes.size();
    }

    bool personal(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool lastLayer = false; // lastLayer 只检测最后一层是否存在不符合特性的节点
        while (!q.empty())
        {
            bool meetNull = false; // 在每一层开始都会置于 false，所以 meetNull 只检测本层中是否存在不符合特性的节点
            int currSize = q.size();
            for (int i = 0; i < currSize; ++i)
            {
                TreeNode *top = q.front();
                q.pop();
                if (top->left)
                {
                    if (meetNull || lastLayer)
                        return false;
                    q.push(top->left);
                }
                else
                    meetNull = true;

                if (top->right)
                {
                    if (meetNull || lastLayer)
                        return false;
                    q.push(top->right);
                }
                else
                    meetNull = true;
            }

            if (q.size() != currSize * 2) // 到了最后一层
                lastLayer = true;
        }
        return true;
    }
};