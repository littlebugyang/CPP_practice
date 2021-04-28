#include <vector>
#include <map>
using std::map;
using std::vector;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        map<int, int> numsMap;
        for (int i = 0; i < nums1.size(); ++i)
            ++numsMap[nums1[i]];
        for (int i = 0; i < nums2.size(); ++i)
            if (numsMap[nums2[i]] > 0)
            {
                --numsMap[nums2[i]];
                result.push_back(nums2[i]);
            }
        return result;
    }
};