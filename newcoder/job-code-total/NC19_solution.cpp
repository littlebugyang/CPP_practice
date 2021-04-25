#include <vector>
#include <algorithm>
using std::max;
using std::vector;
class Solution
{
public:
    /**
     * max sum of the subarray
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxsumofSubarray(vector<int> &arr)
    {
        int maximum = arr[0];
        vector<int> dp(arr.size());
        dp[0] = arr[0];
        for (int i = 1; i < arr.size(); ++i)
            maximum = max(dp[i] = max(dp[i - 1] + arr[i], arr[i]), maximum);
        return maximum;
    }
};

int main()
{
    vector<int> arr = {1, -2, 3, 5, -2, 6, -1};
    Solution solution;
    int result = solution.maxsumofSubarray(arr);
    return 0;
}