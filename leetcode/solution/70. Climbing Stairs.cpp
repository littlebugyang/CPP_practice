#include <vector>
using std::vector;

class Solution
{
public:
    int climbStairs(int n)
    {
        // vector<int> steps(n + 1);
        // if (n < 2)
        //     return 1;
        // steps[0] = 1;
        // steps[1] = 1;
        // for (int i = 2; i < n + 1; ++i)
        //     steps[i] = steps[i - 1] + steps[i - 2];
        // return steps[n];

        if (n < 2)
            return 1;
        int i, j, k;
        i = j = 1;
        while (--n)
        {
            k = i + j;
            i = j;
            j = k;
        }
        return j;
    }
};