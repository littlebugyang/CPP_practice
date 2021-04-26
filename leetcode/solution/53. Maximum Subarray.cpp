#include <vector>
#include <algorithm>
using std::max;
using std::vector;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] = max(nums[i - 1] + nums[i], nums[i]);
            maxSum = max(maxSum, nums[i]);
        }
        return maxSum;
    }
};