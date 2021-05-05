#include <vector>
#include <map>
#include <algorithm>
using std::map;
using std::sort;
using std::vector;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.size() == 0)
            return result;

        map<int, int> numsMap;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i)
        {
        }
    }
};