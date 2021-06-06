#include <vector>
#include <algorithm>
using std::max;
using std::sort;
using std::vector;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        int sorted = 0;
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= intervals[sorted][1])
                intervals[sorted][1] = max(intervals[sorted][1], intervals[i][1]);
            else
                intervals[++sorted] = intervals[i];
        }
        return vector<vector<int>>(intervals.begin(), intervals.begin() + sorted + 1);
    }
};