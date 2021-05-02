#include <string>
using std::string;

class Solution
{
public:
    int *buildNext(string pattern)
    {
        int *next = new int[pattern.size()];
        int j = 0;
        int k = next[0] = -1;
        while (j < pattern.size() - 1)
        {
            if (0 > k || pattern[j] == pattern[k])
                next[++j] = ++k;
            else
                k = next[k];
        }
        return next;
    }

    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;
        if (haystack.size() == 0)
            return -1;
        int *next = buildNext(needle);
        int i = 0, j = 0;
        int n = haystack.size();
        int m = needle.size();
        while (i < n && j < m)
        {
            if (0 > j || haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
                j = next[j];
        }
        delete[] next;
        return (i - j > n - m) ? -1 : i - j;
    }
};