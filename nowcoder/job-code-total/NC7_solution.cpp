#include <vector>
#include <algorithm>
using std::max;
using std::min;
using std::vector;
class Solution
{
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int> &prices)
    {
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};

int main()
{
    Solution solution;
    vector<int> prices;
    int result = solution.maxProfit(prices);
    return 0;
}