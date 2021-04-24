#include <vector>
using std::vector;
class Solution
{
public:
    /**
     * 
     * @param m int整型 
     * @param n int整型 
     * @return int整型
     */
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; ++i)
            dp[i] = vector<int>(m);
        dp[0][0] = 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (i == 0 && j == 0)
                    continue;
                int fromUp, fromLeft;
                fromUp = (i - 1 >= 0 ? dp[i - 1][j] : 0);
                fromLeft = (j - 1 >= 0 ? dp[i][j - 1] : 0);
                dp[i][j] = fromUp + fromLeft;
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main()
{
    Solution solution;
    int result = solution.uniquePaths(2, 2);
    return 0;
}