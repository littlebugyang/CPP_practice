#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // 定义 dp[i] 的含义为：以 nums[i] 为结尾的多个连续子数组中能得到的最大和
        // 下面用遍历过的 nums[i] 表示 dp[i]
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            // 决定在 nums[i] 这个位置上要延续上一段，还是自己另起一段
            nums[i] = max(nums[i] + nums[i - 1], nums[i]);
            maxSum = max(nums[i], maxSum);
        }
        return maxSum;
    }
};