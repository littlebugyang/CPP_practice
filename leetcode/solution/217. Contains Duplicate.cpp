#include <vector>
#include <map>
using std::map;
using std::vector;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        map<int, int> maps;
        for (int i = 0; i < nums.size(); ++i)
            ++maps[nums[i]];
        for (int i = 0; i < nums.size(); ++i)
            if (maps[nums[i]] >= 2)
                return true;
        return false;
    }
};