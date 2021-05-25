#include <vector>
#include <algorithm>
using std::sort;
using std::vector;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int j = i + 1, k = nums.size() - 1; // 把问题转化为“找到 nums[i+1, num.size()) 之间和为 -nums[i] 的两个数”。
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0) // 找到符合要求的 i, j, k
                {
                    result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    while (j + 1 < k && nums[j + 1] == nums[j]) // 去掉所有同样的 j
                        ++j;
                    while (j < k - 1 && nums[k - 1] == nums[k]) // 去掉所有同样的 k
                        --k;
                }
                if (nums[j] + nums[k] + nums[i] < 0) // 三者和还需要再大点，则 j 右移
                {
                    ++j;
                }
                else // 三者和还需要再小点，则 k 左移
                {
                    --k;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) // 去掉所有同样的 i
                ++i;
        }
        return result;
    }
};