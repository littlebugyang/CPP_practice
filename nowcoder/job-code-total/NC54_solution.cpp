#include <vector>
#include <algorithm>
using std::vector;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &num)
    {
        vector<vector<int>> result;
        if (num.size() < 3)
            return result;

        std::sort(num.begin(), num.end());

        for (int i = 0; i < num.size() - 2; ++i)
        {
            int start = i + 1;
            int end = num.size() - 1;
            while (start < end)
            {
                if (num[start] + num[end] == -num[i])
                {
                    result.push_back(vector<int>({num[i], num[start], num[end]}));
                    do
                    {
                        ++start;
                    } while (start < end && num[start] == num[start - 1]);
                    do
                    {
                        --end;
                    } while (start < end && num[end] == num[end + 1]);
                }
                else if (num[start] + num[end] < -num[i])
                { // 两者之和还需要再大一些，需要 start 再右一些
                    ++start;
                }
                else
                { // 两者之和还需要再大一些，需要 end 再左一些
                    --end;
                }
            }

            while (num[i] == num[i + 1])
                ++i;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> num = {-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0};
    // vector<int> num = {0, 0, 0, 0};
    // vector<int> num = {-2, 0, 1, 1, 2};
    vector<vector<int>> result = solution.threeSum(num);
    return 0;
}