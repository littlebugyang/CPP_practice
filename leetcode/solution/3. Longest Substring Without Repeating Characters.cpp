#include <string>
#include <algorithm>
#include <map>
using std::map;
using std::max;
using std::string;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() < 2)
            return s.size();

        map<char, int> counts;

        int start = 0, end = 1;
        int len = 0;
        ++counts[s[start]];

        while (s.size() != end)
        {
            if (counts[s[end]] > 0) // 重复了，start 开始右移
            {
                --counts[s[start]];
                ++start;
            }
            else
            {
                ++counts[s[end]];
                len = max(len, end - start + 1);
                ++end;
            }
        }
        return len;
    }
};

int main()
{
    Solution solution;
    solution.lengthOfLongestSubstring("abcabcbb");
    return 0;
}