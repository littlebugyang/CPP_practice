#include <iostream>
class Solution
{
public:
    /**
     * 
     * @param n int整型 
     * @param m int整型 
     * @return int整型
     */
    int ysf(int n, int m)
    {
        int x = 0;
        for (int i = 1; i < n; ++i)
        {
            x = (x + m % (i + 1)) % (i + 1);
        }
        return x + 1;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.ysf(5, 2);
    return 0;
}