#include <climits>
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;

        unsigned int maxPowerThree = 3;
        while (maxPowerThree < INT_MAX)
            maxPowerThree *= 3;
        return maxPowerThree % n == 0;
    }
};