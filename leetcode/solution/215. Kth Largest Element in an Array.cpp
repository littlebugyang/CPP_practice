#include <algorithm>
#include <vector>
using std::sort;
using std::swap;
using std::vector;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        heapify(nums, k);
        for (int i = k; i < nums.size(); ++i)
        {
            if (nums[i] > nums[0]) // 如果后来者比堆顶大，则放入其中，令其下滤
            {
                nums[0] = nums[i];
                percolateDown(nums, 0, k);
            }
        }
        return nums[0];
    }

    // Floyd 建堆：自下而上的下滤
    void heapify(vector<int> &nums, int size)
    {
        for (int i = size - 1; (i - 1) / 2 >= 0; --i)
            percolateDown(nums, i, size);
    }

    // 对堆中某个元素下滤
    void percolateDown(vector<int> &nums, int start, int size)
    {
        int index = start;
        int leftIndex = index * 2 + 1;
        int rightIndex = index * 2 + 2;
        int swapIndex = leftIndex;

        while (leftIndex < size)
        {
            if (rightIndex < size && nums[rightIndex] < nums[leftIndex]) // 如果有右孩子
                swapIndex = rightIndex;
            if (nums[swapIndex] < nums[index]) // 孩子中最小的那个与父节点交换
            {
                swap(nums[swapIndex], nums[index]);
                index = swapIndex;

                leftIndex = index * 2 + 1;
                rightIndex = index * 2 + 2;
                swapIndex = leftIndex;
            }
            else // 孩子没有与父节点交换，说明已经符合性质
            {
                break;
            }
        }
    }
};

int main()
{
    vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
    Solution solution;
    solution.findKthLargest(nums, 4);
    return 0;
}