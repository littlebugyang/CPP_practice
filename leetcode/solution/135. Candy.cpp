#include <vector>
#include <algorithm>
using std::max;
using std::vector;
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> candies(ratings.size(), 1);
        for (int i = 0; i < ratings.size() - 1; ++i)
            if (ratings[i + 1] > ratings[i])
                candies[i + 1] = candies[i] + 1;

        for (int i = ratings.size() - 1; i > 0; --i)
            if (ratings[i - 1] > ratings[i])
                candies[i - 1] = max(candies[i - 1], candies[i] + 1);
        int count = 0;
        for (int i = 0; i < candies.size(); ++i)
            count += candies[i];
        return count;
    }
};