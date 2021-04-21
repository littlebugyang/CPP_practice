#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    /**
     * 旋转数组
     * @param n int整型 数组长度
     * @param m int整型 右移距离
     * @param a int整型vector 给定数组
     * @return int整型vector
     */
    vector<int> solve(int n, int m, vector<int> &a)
    {
        int newStart = m % n;
        reverseArray(a, 0, a.size());
        reverseArray(a, 0, newStart);
        reverseArray(a, newStart, a.size());
        return a;
    }

    void reverseArray(vector<int> &a, int begin, int end)
    {
        int temp = a[0];
        int i = begin;
        int j = end - 1;
        while (i < j)
        {
            temp = a[i];
            a[i++] = a[j];
            a[j--] = temp;
        }
    }
};