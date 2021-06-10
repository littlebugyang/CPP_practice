#include <string>
#include <map>
using std::map;
using std::string;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        map<char, int> counts;
        map<char, bool> exists;

        for (int i = 1; i < s.size(); ++i)
            ++counts[s[i]];
        string stack = s;
        int top = 0;
        exists[stack[0]] = true;

        for (int i = 1; i < s.size(); ++i)
        {
            if (exists[s[i]])
            {
                --counts[s[i]];
                continue;
            }

            if (stack[top] < s[i] || counts[stack[top]] == 0)
            {
                --counts[s[i]];
                stack[++top] = s[i];
                exists[stack[top]] = true;
                continue;
            }

            while (top >= 0 && stack[top] > s[i] && counts[stack[top]] > 0)
            {
                exists[stack[top]] = false;
                stack[top--] = s[i];
            }
            ++top;
            exists[stack[top]] = true;
            --counts[stack[top]];
        }
        return stack.substr(0, top + 1);
    }
};