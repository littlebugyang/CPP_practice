#include <map>
#include <queue>
using std::map;
using std::queue;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        map<TreeNode *, TreeNode *> parents;
        queue<TreeNode *> nodes;
        nodes.push(root);

        // 构建父子关系
        while (!nodes.empty())
        {
            TreeNode *node = nodes.front();
            nodes.pop();
            if (node->left)
            {
                nodes.push(node->left);
                parents[node->left] = node;
            }
            if (node->right)
            {
                nodes.push(node->right);
                parents[node->right] = node;
            }
        }

        // 求相交链表
        bool resetA = false, resetB = false;
        TreeNode *pA = p, *pB = q;
        while (pA && pB)
        {
            if (pA == pB)
                return pA;
            pA = parents[pA];
            pB = parents[pB];
            if (!pA && !resetA)
            {
                resetA = true;
                pA = q;
            }
            if (!pB && !resetB)
            {
                resetB = true;
                pB = p;
            }
        }
        return root;
    }
};