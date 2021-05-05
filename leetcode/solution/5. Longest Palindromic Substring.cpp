#include <string>
#include <algorithm>
using std::max;
using std::string;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() == 0 || s.size() == 1)
            return s;
        int maxLen = 0;
        int maxI = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int len = lenPalindrome(s, i);
            if (len > maxLen)
            {
                maxLen = len;
                maxI = i;
            }
        }
        return s.substr(maxI, maxLen);
    }

    int lenPalindrome(const string &s, int begin)
    {
        int i = begin, j = s.size() - 1;
        int end = j + 1;
        while (s[--end] != s[begin])
            ;
        j = end;
        while (i < j)
        {
            if (s[i] == s[j])
                ++i, --j;
            else
                return -1;
        }
        return end - begin + 1;
    }
};