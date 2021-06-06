#include <vector>
#include <algorithm>
using std::max;
using std::vector;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0) // 题目没有要求，但求规范
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> money(nums.size());
        money[0] = nums[0], money[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i)
            money[i] = max(money[i - 2] + nums[i], money[i - 1]);
        return money.back();
    }
};