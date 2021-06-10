#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // return recursive(nums, target);
        return dynamicProgramming(nums, target);
    }

    int dynamicProgramming(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int n : nums)
            sum += n;

        if ((sum - target) < 0 || (sum - target) % 2 != 0)
            return 0;

        int neg = (sum - target) >> 1;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(neg + 1));
        dp[0][0] = 1;

        for (int i = 1; i <= nums.size(); ++i)
        {
            for (int j = 0; j <= neg; ++j)
            {
                if (nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nums.size()][neg];
    }

    int recursive(vector<int> &nums, int target)
    {
        if (nums.size() == 1)
        {
            int sum = 0;
            if (nums[0] == target)
                ++sum;
            if (nums[0] == -target)
                ++sum;
            return sum;
        }

        vector<int> former = vector<int>(nums.begin(), nums.begin() + nums.size() - 1);
        return recursive(former, target - nums[nums.size() - 1]) +
               recursive(former, target + nums[nums.size() - 1]);
    }
};