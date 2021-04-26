#include <vector>
#include <map>
using std::map;
using std::vector;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // HashMap version
        /* map<int, int> maps;
        for (int i = 0; i < nums.size(); ++i)
            ++maps[nums[i]];
        for (int i = 0; i < nums.size(); ++i)
            if (maps[nums[i]] > nums.size() / 2)
                return nums[i];
        return 0; */

        // Boyer-Moore version
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == candidate)
                ++count;
            else
            {
                if (count == 0)
                {
                    candidate = nums[i];
                    count = 1;
                    continue;
                }
                --count;
            }
        }
        return candidate;
    }
};