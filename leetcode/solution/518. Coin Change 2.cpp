#include <vector>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int count = 0;

        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= coins.size(); ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= coins.size(); ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                int k = 1;
                while (k * coins[i - 1] <= j)
                {
                    dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
                    ++k;
                }
            }
        }
        return dp[coins.size()][amount];
    }
};