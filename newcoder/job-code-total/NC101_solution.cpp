#include <vector>
#include <climits>
using std::vector;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 找缺失数字
     * @param a int整型vector 给定的数字串
     * @return int整型
     */
    int solve(vector<int> &a)
    {
        long long sum = 0;
        int max = 0;
        int min = INT_MAX;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] > max)
                max = a[i];
            if (a[i] < min)
                min = a[i];
            sum += a[i];
        }
        long long originalSum = (1 + max) / 2.0 * max;
        if (originalSum == sum)
            if (min == 0)
                return max + 1;
            else
                return 0;

        return originalSum - sum;
    }
};

int main()
{
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    Solution solution;
    int result = solution.solve(a);
    return 0;
}