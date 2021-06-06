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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *head = new TreeNode(preorder[0]);

        int leftSize = searchInorder(inorder, head->val);
        if (0 < leftSize)
        {
            vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
            vector<int> leftInorder(inorder.begin(), inorder.begin() + leftSize);
            head->left = buildTree(leftPreorder, leftInorder);
        }
        if (0 < preorder.size() - leftSize - 1)
        {
            vector<int> rightPreorder(preorder.begin() + 1 + leftSize, preorder.end());
            vector<int> rightInorder(inorder.begin() + 1 + leftSize, inorder.end());
            head->right = buildTree(rightPreorder, rightInorder);
        }
        return head;
    }

    int searchInorder(vector<int> &inorder, int target)
    {
        // todo: 因为 inorder 一定是有序的，可以二分查找
        for (int i = 0; i < inorder.size(); ++i)
            if (inorder[i] == target)
                return i;
        return 0; // 因为这是在中序遍历中找前序遍历的节点，所以根据题目设定，该函数一定能找到符合条件的 i，这里的 return 0 只是起规范作用，实际上并不会运行至此。
    }
};