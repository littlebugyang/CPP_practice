#include <vector>
#include <algorithm>
using std::vector;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 最多有多少数字不小于x
     * @param n int整型 
     * @param x int整型 
     * @param a int整型vector 
     * @return int整型
     */
    int arrange(int n, int x, vector<int> &a)
    {
        sort(a.begin(), a.end());

        // long long sum = 0;
        long long largerSum = 0;
        int count = 0;
        int i = 0;
        for (i = a.size() - 1; i >= 0; --i)
        {
            if (a[i] >= x)
            {
                ++count;
                largerSum += a[i];
                break;
            }
        }
        largerSum -= count * x;
        for (--i; i >= 0; --i)
        {
            if (largerSum >= (x - a[i]))
            {
                largerSum -= (x - a[i]);
                ++count;
            }
        }

        // long long average = sum / a.size();
        // if (average >= x)
        //     return a.size();

        // long long rest = largerSum - count * x;
        // for (int i = a.size() - 1 - count; i >= 0; --i)
        // {
        //     if (rest >= a[i] - x)
        //     {
        //         ++count;
        //         rest -= a[i] - x;
        //     }
        // }
        return count;
    }
};

int main()
{
    vector<int> a = {971, 958, 930, 924, 918, 893, 881, 862, 853, 836, 832, 800, 796, 768, 747, 728, 713, 706, 672, 671, 668, 600, 596, 595, 568, 567, 546, 539, 511, 496, 472, 469, 451, 420, 416, 349, 342, 304, 283, 257, 255, 231, 170, 157, 152, 113, 92, 52, 50, 25, 13};
    Solution solution;
    solution.arrange(51, 839, a);
    return 0;
}