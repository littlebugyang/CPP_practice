#include <vector>
using std::vector;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; ++i)
        {
            result.push_back(vector<int>(i + 1));
            result[i][0] = 1;
            result[i][i] = 1;
            for (int j = 1; j < result[i].size() - 1; ++j)
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
        return result;
    }
};