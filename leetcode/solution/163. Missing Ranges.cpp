#include <vector>
#include <string>
using std::string;
using std::to_string;
using std::vector;

class Solution
{
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        vector<string> result;
        // 处理零元素
        if (nums.size() == 0)
        {
            if (upper > lower)
                result.push_back(to_string(lower) + "->" + to_string(upper));
            else
                result.push_back(to_string(upper));
            return result;
        }

        // 处理首元素，以便于后面的元素有“前”元素
        if (nums[0] - lower > 0)
        {
            string temp = to_string(lower);
            if (nums[0] - lower > 1)
                temp += ("->" + to_string(nums[0] - 1));
            result.push_back(temp);
        }

        // 处理剩余元素
        for (int i = 1; i < nums.size(); ++i)
        {
            int diff = nums[i] - nums[i - 1];
            if (diff > 1)
                if (diff == 2)
                    result.push_back(to_string(nums[i] - 1));
                else
                    result.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
        }

        // 处理最后一个元素
        int diff = upper - nums[nums.size() - 1];
        if (diff > 0)
        {
            if (diff == 1)
                result.push_back(to_string(upper));
            else
                result.push_back(to_string(nums[nums.size() - 1] + 1) + "->" + to_string(upper));
        }
        return result;
    }
};

int main()
{
    vector<int> test;
    Solution solution;
    vector<string> result = solution.findMissingRanges(test, 0, 10);
    return 0;
}