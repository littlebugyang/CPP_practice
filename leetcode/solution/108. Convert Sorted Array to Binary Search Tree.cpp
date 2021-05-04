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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return constructTree(nums, 0, nums.size());
    }

    TreeNode *constructTree(vector<int> &nums, int begin, int end)
    {
        if (begin == end)
            return nullptr;

        int mid = (begin + end) / 2;
        return new TreeNode(nums[mid], constructTree(nums, begin, mid), constructTree(nums, mid + 1, end));
    }
};