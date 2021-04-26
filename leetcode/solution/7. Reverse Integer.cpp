#include <climits>
#include <iostream>
#include <cmath>
class Solution
{
public:
    int reverse(int x)
    {
        const int MAX = pow(2, 31) - 1;
        const int MIN = -pow(2, 31);

        int result = x % 10;
        x /= 10;
        while (x != 0)
        {
            if (result > INT_MAX / 10 || result < INT_MIN / 10)
                return 0;
            long long temp = 10 * result + x % 10;
            if (temp > MAX || temp < MIN)
                return 0;
            result = temp;
            x /= 10;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int result = solution.reverse(1463847412);
    return 0;
}