#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int child = 0, biscuit = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (biscuit++ != s.size() && child != g.size())
            if (s[biscuit - 1] >= g[child])
                ++child;
        return child;
    }
};