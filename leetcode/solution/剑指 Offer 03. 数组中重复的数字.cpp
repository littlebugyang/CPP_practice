#include <vector>
using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        bool zero = false;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                if (zero)
                    return 0;
                zero = true;
            }
            else
            {
                int real = nums[i] < 0 ? -nums[i] : nums[i];
                if (nums[real] < 0)
                    return real;
                else
                    nums[real] = -nums[real];
            }
        }
        return 0;
    }
};