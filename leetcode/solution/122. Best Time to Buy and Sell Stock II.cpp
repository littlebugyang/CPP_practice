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
        int profitAccum = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
                profitAccum += prices[i] - prices[i - 1];
        }
        return profitAccum;
    }
};