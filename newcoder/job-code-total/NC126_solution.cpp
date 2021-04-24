#include <vector>
#include <algorithm>
#include <climits>
using std::min;
using std::sort;
using std::vector;
class Solution
{
public:
    /**
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
    int minMoney(vector<int> &arr, int aim)
    {
        vector<int> dp(aim + 1);
        for (int i = 1; i < dp.size(); ++i)
        {
            dp[i] = INT_MAX;
            if (i >= arr[0] && dp[i - arr[0]] != INT_MAX)
                dp[i] = dp[i - arr[0]] + 1;
        }

        for (int i = 1; i < arr.size(); ++i)
        {
            for (int j = 1; j < dp.size(); ++j)
            {
                if (j >= arr[i])
                {
                    int excludeMoneyI = dp[j];
                    int includeMoneyI = (dp[j - arr[i]] == INT_MAX) ? INT_MAX : dp[j - arr[i]] + 1;
                    dp[j] = min(excludeMoneyI, includeMoneyI);
                }
            }
        }
        return dp[dp.size() - 1] == INT_MAX ? -1 : dp[dp.size() - 1];
    }
};

int main()
{
    vector<int> arr;
    Solution solution;
    int result = solution.minMoney(arr, 20);
    return 0;
}