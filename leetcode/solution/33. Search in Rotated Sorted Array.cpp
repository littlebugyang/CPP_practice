#include <vector>
using std::vector;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 左闭右开
        int start = 0, end = nums.size();
        int mid = 0;
        while (start < end)
        {
            mid = start + (end - start) / 2; // 中间或者中间偏右的元素
            if (nums[mid] == target)
                return mid;
            if (nums[start] <= nums[mid]) // 左边有序
            {
                if (nums[start] <= target && target <= nums[mid]) // 在左边有序部分进行查找
                {
                    end = mid;
                }
                else // 在右边无序部分进行查找
                {
                    start = mid + 1;
                }
            }
            else // 右边有序
            {
                if (nums[mid] <= target && target <= nums[end - 1]) // 在右边有序部分进行查找
                {
                    start = mid + 1;
                }
                else // 在左边无序部分进行查找
                {
                    end = mid;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums{1, 3, 4, 5, 6, 8};
    Solution solution;
    int result = solution.search(nums, 8);
    return 0;
}
