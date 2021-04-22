#include <vector>
#include <algorithm>
using std::vector;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * ​返回按照这些花排成一个圆的序列中最小的“丑陋度”
     * @param n int整型 花的数量
     * @param array int整型vector 花的高度数组
     * @return int整型
     */
    int arrangeFlowers(int n, vector<int> &array)
    {
        sort(array.begin(), array.end());
        int max = array[1] - array[0];
        for (int i = 0; i < array.size() - 1; ++i)
        {
            int diff = 0;
            if (i == array.size() - 2) // 恰好为第二大元素
                diff = array[i + 1] - array[i];

            else // 对比对象在范围内
                diff = array[i + 2] - array[i];

            if (diff > max)
                max = diff;
        }
        return max;
    }
};

int main()
{
    vector<int> arr;
    Solution solution;
    int result = solution.arrangeFlowers(arr.size(), arr);
    return 0;
}