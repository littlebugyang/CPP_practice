#include <vector>
#include <algorithm>
using std::sort;
using std::vector;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int count = 1;         // 留下来的区间的个数，排序后第一个区间是一定会留下来的
        int lastPreserved = 0; // 上一个留下来的区间的下标

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] >= intervals[lastPreserved][1])
            {
                ++count;
                lastPreserved = i;
            }
        }

        return intervals.size() - count;
    }
};