#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];

        string result = "";
        bool keep = true;
        int i = 0;
        while (keep)
        {
            if (strs[0].size() <= i)
                break;
            char current = strs[0].at(i);

            for (int j = 1; j < strs.size(); ++j)
            {
                if (strs[j].size() <= i || strs[j].at(i) != current)
                {
                    keep = false;
                    break;
                }
            }
            if (keep)
                result += current;
            ++i;
        }
        return result;
    }
};