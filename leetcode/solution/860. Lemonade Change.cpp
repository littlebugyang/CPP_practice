#include <vector>
using std::vector;
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int fives = 0;
        int tens = 0;
        for (int i = 0; i < bills.size(); ++i)
        {
            if (5 == bills[i])
                ++fives;
            if (10 == bills[i])
            {
                if (0 < fives)
                {
                    --fives;
                    ++tens;
                }
                else
                    return false;
            }
            if (20 == bills[i])
            {
                if (0 < fives)
                {
                    if (0 < tens)
                    {
                        --tens;
                        --fives;
                    }
                    else if (2 < fives)
                    {
                        fives -= 3;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};