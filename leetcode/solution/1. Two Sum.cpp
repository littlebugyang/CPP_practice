#include <vector>
#include <map>
using std::map;
using std::vector;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        map<int, int> numsMap;
        for (int i = 0; i < nums.size(); ++i)
            numsMap[nums[i]] = i + 1;

        for (int i = 0; i < nums.size(); ++i)
        {
            int potential = numsMap[target - nums[i]];
            if (potential != 0 && potential - 1 != i)
            {
                result.push_back(i);
                result.push_back(potential - 1);
                break;
            }
        }
        return result;
    }
};