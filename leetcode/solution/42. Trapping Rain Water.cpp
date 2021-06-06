#include <algorithm>
#include <vector>
#include <map>
#include <stack>
using std::lower_bound;
using std::map;
using std::max;
using std::min;
using std::stack;
using std::vector;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        return trapDoublePointer(height);
    }

    int trapPersonal(vector<int> &height)
    {
        if (height.size() < 3)
            return 0;

        int maxHeight = 0;
        map<int, bool> exists;               // 记录某高度的柱子是否存在
        map<int, bool> counted;              // 记录某位置的柱子是否已被计算
        map<int, vector<int>> heightIndexes; // 记录某高度的位置，可能有多个位置

        // 统计各类高度
        for (int i = 0; i < height.size(); ++i)
        {
            counted[i] = false;
            exists[height[i]] = true;
            maxHeight = max(height[i], maxHeight);
            heightIndexes[height[i]].push_back(i);
        }

        // 计算雨水量
        int waters{0};
        for (int i = maxHeight; i > 0; --i)
        {
            // 遍历某高度的所有区间，若某高度不存在，则再降高度
            if (!exists[i])
                continue;

            int nextHeight = i;
            while (!exists[--nextHeight] && nextHeight > 0)
                ;

            if (heightIndexes[i].size() == 1) // 只有一个这样高度的柱子，不参与计算雨量
            {
                // 但是要当作低一级的柱子，应付示例 2 中 [4,2,0,3,2,5] 的情况
                counted[heightIndexes[i][0]] = true;
                int onlyIndex = heightIndexes[i][0];
                // 用 upper_bound 找到该位置在低一级高度的 vector 中的位置，然后插入
                if (nextHeight > 0)
                    heightIndexes[nextHeight].insert(lower_bound(heightIndexes[nextHeight].begin(), heightIndexes[nextHeight].end(), onlyIndex), onlyIndex);
            }

            for (int j = 0; j < heightIndexes[i].size() - 1; ++j)
            {
                for (int k = heightIndexes[i][j]; k <= heightIndexes[i][j + 1]; ++k) // 区间内计数
                {
                    if (!counted[k])
                    {
                        waters += (i - height[k]);
                        counted[k] = true;
                    }
                }
                if (nextHeight > 0)
                {
                    heightIndexes[nextHeight].insert(lower_bound(heightIndexes[nextHeight].begin(), heightIndexes[nextHeight].end(), heightIndexes[i][j]), heightIndexes[i][j]);
                    heightIndexes[nextHeight].insert(lower_bound(heightIndexes[nextHeight].begin(), heightIndexes[nextHeight].end(), heightIndexes[i][j + 1]), heightIndexes[i][j + 1]);
                }
            }
            i = nextHeight + 1;
        }

        return waters;
    }

    int trapBruteForce(vector<int> &height)
    {
        if (height.size() < 3)
            return 0;

        int sum = 0;
        for (int i = 1; i < height.size(); ++i)
        {
            int leftMax = height[i];
            for (int j = 0; j < i; ++j)
            {
                leftMax = max(leftMax, height[j]);
            }
            int rightMax = height[i];
            for (int j = i + 1; j < height.size(); ++j)
            {
                rightMax = max(rightMax, height[j]);
            }
            sum += min(leftMax, rightMax) - height[i];
        }
        return sum;
    }

    int trapDP(vector<int> &height)
    {
        if (height.size() < 3)
            return 0;
        int sum = 0;
        vector<int> leftMax(height.size()), rightMax(height.size());

        leftMax[0] = height[0];
        for (int i = 1; i < height.size(); ++i)
            leftMax[i] = max(height[i], leftMax[i - 1]);

        rightMax[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; --i)
            rightMax[i] = max(height[i], rightMax[i + 1]);

        for (int i = 0; i < height.size(); ++i)
            sum += (min(leftMax[i], rightMax[i]) - height[i]);
        return sum;
    }

    int trapStack(vector<int> &height)
    {
        if (height.size() < 3)
            return 0;
        int sum = 0;
        stack<int> indexes; // 栈中的下标对应的高度是递减的
        indexes.push(0);
        for (int i = 1; i < height.size(); ++i)
        {
            if (height[i] <= height[indexes.top()])
            {
                indexes.push(i);
            }
            else // 有比栈顶更高的元素，可以蓄水
            {
                while (indexes.size() > 1) // 栈中至少还有两个元素时
                {
                    int temp = indexes.top();
                    if (height[temp] >= height[i]) // 已经不比栈顶的柱子高了，仅凭当前柱子不可能再增加积水
                        break;
                    indexes.pop();
                    int w = i - indexes.top() - 1;
                    int h = min(height[i], height[indexes.top()]) - height[temp];
                    sum += (w * h);
                }

                if (height[i] >= height[indexes.top()]) // 当前柱为左侧最高柱，左边不可能再有积水
                {
                    indexes.pop();
                }

                indexes.push(i);
            }
        }
        return sum;
    }

    int trapDoublePointer(vector<int> &height)
    {
        /*
            该方法的核心思想是：
            - 如果 leftMax <= rightMax，那么左指针当前位置的水位只由 leftMax 来决定，无论右边的 rightMax 是否还会更大；
            - 同理得：如果 leftMax >= rightMax，那么右指针当前位置的水位只由 rightMax 来决定，无论左边的 leftMax 是否还会更大。
        */
        if (height.size() < 3)
            return 0;
        int sum = 0;
        int leftMax = height.front(), rightMax = height.back();
        int left = 0, right = height.size() - 1;
        bool turnLeft = true; // 是否轮到左指针移动
        while (left != right)
        {
            if (leftMax <= rightMax)
            {
                turnLeft = true;
                sum += (leftMax - height[left]);
            }
            else
            {
                turnLeft = false;
                sum += (rightMax - height[right]);
            }

            if (turnLeft)
            {
                leftMax = max(leftMax, height[++left]);
            }
            else
            {
                rightMax = max(rightMax, height[--right]);
            }
        }
        return sum;
    }
};