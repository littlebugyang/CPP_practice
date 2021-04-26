#include <vector>
#include <algorithm>
using std::max;
using std::min;
using std::vector;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int priceMin = prices[0];
        int profitMax = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            priceMin = min(priceMin, prices[i]);
            profitMax = max(profitMax, prices[i] - priceMin);
        }
        return profitMax;
    }
};