#include <string>
#include <algorithm>
#include <map>
#include <climits>
using std::map;
using std::min;
using std::string;

// 这道题有点操蛋，s 为 "a"，t 为 "aa"，应输出的居然是空串。

class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<char, int> existsT; // 记录 t 中不同的字符及其个数
        map<char, int> numInS;  // 记录 t 中各个不同字符在 s 中出现的次数，如果没有这个 map，那么在 left 指针再次前进的时候，需要 right 指针回溯以确定 [left, right] 是否包含了所有 t 字符

        for (int i = 0; i < t.size(); ++i)
            ++existsT[t[i]];

        int tInS = 0; // 记录当前 t 中字符在 s 中的个数
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minIndex = left;

        while (left < s.size() && 0 == existsT[s[left]])
            ++left;
        if (left < s.size())
        {
            tInS = 1;
            numInS[s[left]] = 1;
        }
        if (tInS == t.size())
        {
            minLen = 1;
            minIndex = left;
        }
        right = left + 1;

        while (right < s.size())
        {
            // right 去到该去的地方，去到恰好有 [left, right] 包含了所有的 t 字符的地方
            while (right < s.size())
            {
                if (0 < existsT[s[right]])
                {
                    tInS = (numInS[s[right]] < existsT[s[right]]) ? tInS + 1 : tInS;
                    ++numInS[s[right]];
                    if (tInS == t.size())
                        break;
                }
                ++right;
            }

            if (tInS == t.size() && right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                minIndex = left;
            }

            // left 去到该去的地方，寻求下个合适的为 t 字符的位置
            while (left < s.size())
            {
                // 此时 left 上为 t 字符，前进之前要做准备
                if (0 < existsT[s[left]])
                {
                    if (tInS == t.size())
                    {
                        if (right - left + 1 < minLen)
                        {
                            minLen = right - left + 1;
                            minIndex = left;
                        }
                        --numInS[s[left]];
                        tInS = (numInS[s[left]] < existsT[s[left]]) ? tInS - 1 : tInS;
                        ++left;
                    }
                    else
                    {
                        break;
                    }
                }
                else // 此时 left 上不为 t 字符，仅前进
                {
                    ++left;
                }
            }
            ++right;
        }

        
        if (minLen != INT_MAX)
            return string(s.begin() + minIndex, s.begin() + minIndex + minLen);
        return "";
    }
};

int main()
{
    Solution solution;
    // string result = solution.minWindow("ADOBECODEBANC", "ABC");
    string result = solution.minWindow("bba", "ab");
    // solution.minWindow("a", "a");
    return 0;
}