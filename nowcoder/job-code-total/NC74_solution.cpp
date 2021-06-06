#include <vector>
using std::vector;

class Solution
{
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        int count = 0;
        for (unsigned int i = 0; i < data.size(); ++i)
            if (data[i] == k)
                ++count;
        return count;
    }
};

int main()
{
    vector<int> data;
    Solution solution;
    int result = solution.GetNumberOfK(data, 3);
    return 0;
}