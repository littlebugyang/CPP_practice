#include <map>
#include <string>
using std::map;
using std::string;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        map<char, int> charsMap;
        for (int i = 0; i < s.size(); ++i)
            ++charsMap[s[i]];
        for (int i = 0; i < t.size(); ++i)
            --charsMap[t[i]];
        for (int i = 0; i < t.size(); ++i)
            if (charsMap[t[i]] != 0)
                return false;
        return true;
    }
};