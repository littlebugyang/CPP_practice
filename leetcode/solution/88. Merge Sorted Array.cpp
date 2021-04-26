#include <vector>
using std::vector;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = m + n - 1; i >= n; --i)
        {
            nums1[i] = nums1[i - n];
        }
        int j = n;    // for back of nums1
        int k = 0;    // for nums2
        int curr = 0; // for nums1 of whole
        while (j != m + n && k != n)
        {
            if (nums1[j] <= nums2[k])
                nums1[curr++] = nums1[j++];
            else
                nums1[curr++] = nums2[k++];
        }

        if (j == m + n)
            for (int i = k; i < n; ++i)
                nums1[curr++] = nums2[i];
    }
};