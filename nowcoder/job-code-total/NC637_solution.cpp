#include <vector>
#include <algorithm>
#include <climits>
using std::sort;
using std::vector;
class Solution
{
public:
    /**
     * 
     * @param arr int整型vector 
     * @return int整型
     */
    int Answerofjudge(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        long long sum = 0;
        for (unsigned i = 0; i < arr.size(); ++i)
        {
            sum += arr[i];
        }
        double average = 1.0 * sum / arr.size();
        double mid = 1.0 * ((arr.size() % 2 == 0) ? (arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2.0 : arr[arr.size() / 2]);
        if (mid == average)
            return 0;
        if (mid < average)
            return -1;
        else
            return 1;
    }
};

int main()
{
    vector<int> arr = {7, 4, 8, 11};
    Solution solution;
    int result = solution.Answerofjudge(arr);
    return 0;
}