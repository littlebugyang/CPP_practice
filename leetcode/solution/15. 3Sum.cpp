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
            int j = i + 1, k = nums.size() - 1;
            vector<int> temp{nums[i]};
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    result.push_back(temp);
                    temp.pop_back();
                    temp.pop_back();
                    while (j + 1 < k && nums[j + 1] == nums[j])
                        ++j;
                    while (j < k - 1 && nums[k - 1] == nums[k])
                        --k;
                }
                if (nums[j] + nums[k] < -nums[i])
                    ++j;
                else
                    --k;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++i;
        }
        return result;
    }
};