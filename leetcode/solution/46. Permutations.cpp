#include <vector>
#include <algorithm>
using std::swap;
using std::vector;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> results;
        int size = 1;
        for (int i = 1; i < nums.size(); ++i)
            size *= (i + 1);
        for (int i = 0; i < size; ++i)
        {
            nextPermutation(nums);
            results.push_back(vector<int>(nums));
        }
        return results;
    }

    void nextPermutation(vector<int> &nums)
    {
        // 从后往前找到一个非升序的元素 x，记录其下标
        int iX = nums.size() - 2, iY = nums.size() - 1;
        while (iX >= 0 && nums[iX] > nums[iX + 1])
            --iX;

        if (iX != -1)
        {
            // 从后往前找到一个恰好比 x 大的元素 y
            while (iY >= 0 && nums[iY] <= nums[iX])
                --iY;

            // 交换 x 和 y
            swap(nums[iX], nums[iY]);
        }

        // 从 y 此时的位置后一位开始（下标加 1），直到末尾，把所有元素翻转
        ++iX, iY = nums.size() - 1;
        while (iX < iY)
        {
            swap(nums[iX], nums[iY]);
            ++iX, --iY;
        }
    }
};