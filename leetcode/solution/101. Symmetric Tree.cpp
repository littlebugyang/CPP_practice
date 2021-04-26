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
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) // 根节点为叶子节点或空节点
            return true;
        if (root->left == nullptr || root->right == nullptr) // 根节点不同时拥有左右孩子
            return false;

        symmetrize(root->right);
        vector<TreeNode *> leftNodes;
        vector<TreeNode *> rightNodes;
        leftNodes.push_back(root->left);
        rightNodes.push_back(root->right);

        int i = 0;
        while (true)
        {
            if (leftNodes[i]->val != rightNodes[i]->val)
                return false;
            if (leftNodes[i]->left)
            {
                if (!rightNodes[i]->left)
                    return false;
                leftNodes.push_back(leftNodes[i]->left);
                rightNodes.push_back(rightNodes[i]->left);
            }
            else if (rightNodes[i]->left)
                // 此时左树没有左分支了，如果右树还有左分支，则不对称；下面有对应左树没有右分支这种情况的处理
                return false;

            if (leftNodes[i]->right)
            {
                if (!rightNodes[i]->right)
                    return false;
                leftNodes.push_back(leftNodes[i]->right);
                rightNodes.push_back(rightNodes[i]->right);
            }
            else if (rightNodes[i]->right)
                return false;

            if (i == leftNodes.size() - 1)
                break;
            ++i;
        }
        return true;
    }

    void symmetrize(TreeNode *root)
    {
        // Recursive Version
        /* if (root == nullptr || (root->left == nullptr && root->right == nullptr)) // 叶子节点或空节点
            return;

        if (root->left || root->right)
        {
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
            symmetrize(root->left);
            symmetrize(root->right);
        } */

        // Iterative Version
        vector<TreeNode *> nodes;
        nodes.push_back(root);
        int i = 0;
        while (true)
        {
            TreeNode *temp = nodes[i];
            // 镜像反转
            if (nodes[i]->left || nodes[i]->right)
            {
                temp = nodes[i]->left;
                nodes[i]->left = nodes[i]->right;
                nodes[i]->right = temp;
            }
            if (nodes[i]->left)
                nodes.push_back(nodes[i]->left);
            if (nodes[i]->right)
                nodes.push_back(nodes[i]->right);
            if (i == nodes.size() - 1)
                break;
            ++i;
        }
    }
};