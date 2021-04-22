#include <vector>
#include <algorithm>
using std::max;
using std::vector;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 最少需要跳跃几次能跳到末尾
     * @param n int整型 数组A的长度
     * @param A int整型vector 数组A
     * @return int整型
     */
    int Jump(int n, vector<int> &A)
    {
        int jumpCount = 0;
        int farthest = 0;
        int lastJumpLimit = A[0];
        for (int i = 0; i < A.size() - 1; ++i)
        {
            farthest = max(farthest, i + A[i]);
            if (i == lastJumpLimit)
            {
                lastJumpLimit = farthest;
                ++jumpCount;
            }
        }

        return ++jumpCount; 
    }
};

int main()
{
    vector<int> A;
    Solution solution;
    int result = solution.Jump(A.size(), A);
    return 0;
}