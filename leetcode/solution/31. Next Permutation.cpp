#include <vector>
#include <algorithm>
#include <iostream>
using std::next_permutation;
using std::swap;
using std::vector;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // 从后往前，找到第一个非升序的元素
        int i = nums.size() - 1;
        while (i - 1 >= 0 && nums[i - 1] >= nums[i])
            --i;
        --i;

        int j = nums.size() - 1;

        if (i != -1)
        {
            // 从后往前，找到一个比 nums[i] 大的元素
            while (nums[i] >= nums[j])
                --j;

            // 交换两者值
            swap(nums[i], nums[j]);
        }

        // i 之后的元素翻转
        i = i + 1;
        j = nums.size() - 1;
        while (i < j)
            swap(nums[i++], nums[j--]);
    }
};