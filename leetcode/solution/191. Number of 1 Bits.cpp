#include <cstdint>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        for (int i = 0; i < 32; ++i, n >>= 1)
        {
            if (n & 0b1)
                ++count;
        }
        return count;
    }
};