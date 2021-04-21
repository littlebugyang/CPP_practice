#include <iostream>
#include <vector>
#include <climits>
using std::vector;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求最小差值
     * @param a int整型vector 数组a
     * @return int整型
     */
    int minDifference(vector<int> &a)
    {
        unsigned int min = INT_MAX;
        for (int i = 0; i < a.size() - 1; ++i)
        {
            for (int j = i + 1; j < a.size(); ++j)
            {
                unsigned int abs = (a[i] - a[j]) > 0 ? (a[i] - a[j]) : -(a[i] - a[j]);
                if (abs < min)
                    min = abs;
            }
        }
        return min;
    }
};