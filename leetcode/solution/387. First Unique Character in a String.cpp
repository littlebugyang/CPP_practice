#include <string>
using std::string;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int alphas[26] = {0};
        for (int i = 0; i < s.size(); ++i)
            ++alphas[s.at(i) - 'a'];
        for (int i = 0; i < s.size(); ++i)
            if (alphas[s.at(i) - 'a'] == 1)
                return i;
        return -1;
    }
};