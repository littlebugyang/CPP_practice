#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int sum = 0;
        if (height.size() < 3)
            return sum;
        vector<int> leftMaxes(height.size());
        vector<int> rightMaxes(height.size());
        int leftMax = 0, rightMax = 0;
        leftMaxes[0] = rightMaxes[height.size() - 1] = 0;

        for (int i = 1; i < height.size() - 1; ++i)
        {
            leftMaxes[i] = max(leftMaxes[i - 1], height[i - 1]);
            rightMaxes[height.size() - 1 - i] = max(rightMaxes[height.size() - i], height[height.size() - i]);
        }

        for (int i = 1; i < height.size() - 1; ++i)
        {
            int minHeight = min(leftMaxes[i], rightMaxes[i]);
            if (minHeight > height[i])
                sum += minHeight - height[i];
        }

        return sum;
    }
};