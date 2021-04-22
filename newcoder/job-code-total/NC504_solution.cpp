#include <vector>
#include <iostream>
using std::vector;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a int整型vector 
     * @return double浮点型
     */
    double solve(vector<int> &a)
    {
        // write code here
    }
};

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            for (int k = 0; k < j; ++k)
            {
                std::cout << '(' << a[i] << ", " << a[j] << ", " << a[k] << std::endl;
            }
        }
    }
    // Solution solution;
    // double result = solution.solve(a);
    return 0;
}