class Solution {
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;
        int l = 1;
        int r = x;
        int ans = 0;
        while (l != r)
        {
            long long mid = l + (r - l) / 2;
            if (mid * mid <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid;
        }
        return ans;
    }
};