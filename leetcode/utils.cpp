#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *constructTree(const vector<int> &nums)
{
    TreeNode *root = new TreeNode(nums[0]);
    TreeNode *curr = root;
    int i = 0;
    while (i != nums.size() - 1)
    {
        curr->left = (nums[++i] == -1) ? nullptr : new TreeNode(nums[i]);
        curr->right = (nums[++i] == -1) ? nullptr : new TreeNode(nums[i]);
        curr = curr->left ? curr->left : curr->right;
    }
    return root;
}