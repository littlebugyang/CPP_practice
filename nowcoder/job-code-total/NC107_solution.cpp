class Solution
{
public:
    /**
     * 寻找最后的山峰
     * @param a int整型一维数组 
     * @param aLen int a数组长度
     * @return int整型
     */
    int solve(int *a, int aLen)
    {
        if (aLen == 1 || (aLen >= 2 && a[aLen - 1] >= a[aLen - 2]))
            return aLen - 1;

        for (int i = aLen - 2; i >= 1; --i)
        {
            if (a[i] >= a[i + 1] && a[i] >= a[i - 1])
                return i;
        }

        // 如果到这里都还没有找到山峰，那只可能是首元素
        return 0;
    }
};