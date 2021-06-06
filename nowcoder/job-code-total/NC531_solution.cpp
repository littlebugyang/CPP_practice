#include <vector>
using std::vector;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector array
     * @return long长整型
     */
    long long IncreasingArray(vector<int> &array)
    {
        vector<long long> increments;
        for (int i = 1; i < array.size(); ++i)
        {
            if (array[i - 1] >= array[i])
            {
                increments.push_back(array[i - 1] - array[i] + 1);
                array[i] = array[i - 1] + 1;
            }

            else
                increments.push_back(0);
        }

        long long count = 0;
        bool connected = false;
        for (int i = 0; i < increments.size(); ++i)
        {
            if (increments[i] == 0)
            {
                connected = false;
                continue;
            }

            if (connected)
            { // 非零增量，而且前面已有增量
                if (increments[i] > increments[i - 1])
                    count += increments[i] - increments[i - 1];
            }
            else
            {
                // 非零增量，而且前面没有增量，是新区间的开端
                count += increments[i];
            }
            connected = true;
        }
        return count;
    }
};

int main()
{
    vector<int> arr;
    Solution solution;
    long long result = solution.IncreasingArray(arr);
    return 0;
}