#include <vector>
using std::vector;
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> isPrime(n, 1);
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i] == 1)
            {
                ++count;
                for (unsigned long long j = (unsigned long long)i * i; j < n; j += i)
                    isPrime[j] = 0;
            }
        }
        return count;
    }
};