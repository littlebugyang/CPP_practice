#include <cstdint>
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t x = 0;
        uint32_t mask = 1;
        for (int i = 0; i < 32; ++i, n >>= 1)
        {
            x <<= 1;
            x |= (mask & n);
        }
        return x;
    }
};